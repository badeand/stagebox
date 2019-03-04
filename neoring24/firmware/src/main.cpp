#include "main.h"
#include "Arduino.h"
#include <WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <FastLED.h>
#include <Shell.h>
#include "EEPROM.h"

#ifdef __AVR__
#include <avr/power.h>
#endif

#define NUM_LEDS 24
#define DATA_PIN 4
CRGB leds[NUM_LEDS];

String wifissid = "";
String wifipwd = "";
String mdnsname = "neoring24_1";

WiFiUDP Udp;
const unsigned int localPort = 8888;

OSCErrorCode error;
IPAddress ipAddress;

// PWM parameters
const int freq = 5000;
const int resolution = 8;

const int indicatorPin = 2;

static const int EEPROM_ADDR_SSID = 0;
static const int EEPROM_ADDR_PWD = 32;
static const int EEPROM_ADDR_MDNSNAME = 64;
long timestamp = millis();

void indicate(int s) {
    ledcWrite(indicatorPin, s);
}

int shell_reader(char *data) {
    // Wrapper for Serial.read() method
    if (Serial.available()) {
        *data = Serial.read();
        return 1;
    }
    return 0;
}

/**
 * Function to write data to serial port
 * Functions to write to physical media should use this prototype:
 * void my_writer_function(char data)
 */
void shell_writer(char data) {
    // Wrapper for Serial.write() method
    Serial.write(data);
}

void initNetwork();

void initUDP();

void initMDNS();

void handleOSCMessages();

void initIndicator();

void initFastLED();


void initEEPROM();

char *toString(String &string);

void initFastLED() { FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); }

void initIndicator() {
    Serial.println("Indicator setup");
    ledcSetup(indicatorPin, freq, resolution);
    ledcAttachPin(indicatorPin, indicatorPin);
    Serial.println("Indicator setup .. done");
}

void initNetwork() {// Connect to WiFi network
    timestamp = millis();
    wifissid = EEPROM.readString(EEPROM_ADDR_SSID);
    wifipwd = EEPROM.readString(EEPROM_ADDR_PWD);
    Serial.print("Connecting to ");
    Serial.println(wifissid);
    WiFi.begin(toString(wifissid), const_cast<char *>(wifipwd.c_str()));

    bool indicatorState = false;
    while (WiFi.status() != WL_CONNECTED) {
        shell_task();

        if (millis() > (timestamp + 200)) {
            timestamp = millis();
            indicatorState = !indicatorState;
            if (indicatorState) {
                indicate(255);
            } else {
                indicate(0);
            }
        }

    }

    Serial.print("WiFi connected. IP address: ");
    Serial.println(WiFi.localIP());
    ipAddress = WiFi.localIP();
}

char *toString(String &string) { return const_cast<char *>(string.c_str()); }

void initMDNS() {
    Serial.print("Starting MDNS .. ");
    mdnsname = EEPROM.readString(EEPROM_ADDR_MDNSNAME);
    Serial.print("name:");
    Serial.print(mdnsname);
    if (MDNS.begin(toString(mdnsname))) {
        Serial.println(" .. done .. ");
    } else {
        Serial.println(" FAILED! ");
    }
}

void initUDP() {
    Serial.print("Starting UDP...");
    Udp.begin(localPort);
    Serial.println("Done");
}

void osc_single(OSCMessage &msg) {
    leds[msg.getInt(0)] = CRGB(msg.getInt(1), msg.getInt(2), msg.getInt(3));
    FastLED.show();
}

void osc_all(OSCMessage &msg) {
    int g = msg.getInt(1);
    int b = msg.getInt(2);
    for (int i = 0; i <= NUM_LEDS; i++) {
        leds[i] = CRGB(msg.getInt(0), g, b);
    }
    FastLED.show();
}


void handleOSCMessages() {
    OSCMessage msg;
    int size = Udp.parsePacket();

    if (size > 0) {
        timestamp = millis() + 250;
        while (size--) {
            msg.fill(Udp.read());
        }
        if (!msg.hasError()) {
            msg.dispatch("/single", osc_single);
            msg.dispatch("/all", osc_all);
        } else {
            error = msg.getError();
            Serial.print("error: ");
            Serial.println("" + error);
        }
    }
}


int command_help(int argc, char **argv) {
    shell_println("  reset               - reset the system");
    shell_println("  wifissid <ssid>     - Set WIFI SSID");
    shell_println("  wifipwd  <password> - Set WIFI password");
    shell_println("  mdnsname <name>     - Set MDNS name");
    return SHELL_RET_SUCCESS;
}


int command_reset(int argc, char **argv) {
    shell_println("Resetting system");
    ESP.restart();
    return SHELL_RET_SUCCESS;
}

int command_wifissid(int argc, char **argv) {

    if (argc != 2) {
        shell_println("Expected one parameter: ssid");
        return SHELL_RET_FAILURE;
    }

    shell_printf("Saving SSID to EEPROM: \"%s\" \r\n", argv[1]);
    EEPROM.writeString(EEPROM_ADDR_SSID, argv[1]);
    EEPROM.commit();

    return SHELL_RET_SUCCESS;
}

int command_wifipwd(int argc, char **argv) {

    if (argc != 2) {
        shell_println("Expected one parameter: password");
        return SHELL_RET_FAILURE;
    }

    shell_printf("Saving Wifi password to EEPROM: \"%s\" \r\n", argv[1]);
    EEPROM.writeString(EEPROM_ADDR_PWD, argv[1]);
    EEPROM.commit();

    return SHELL_RET_SUCCESS;
}

int command_mdnsname(int argc, char **argv) {

    if (argc != 2) {
        shell_println("Expected one parameter: MDNS name (String)");
        return SHELL_RET_FAILURE;
    }

    shell_printf("Saving MDNS name to EEPROM: \"%s\" \r\n", argv[1]);
    EEPROM.writeString(EEPROM_ADDR_MDNSNAME, argv[1]);
    EEPROM.commit();

    return SHELL_RET_SUCCESS;
}

void initShell() {
    shell_init(shell_reader, shell_writer, 0);

    shell_register(command_reset, PSTR("reset"));
    shell_register(command_wifissid, PSTR("wifissid"));
    shell_register(command_wifipwd, PSTR("wifipwd"));
    shell_register(command_mdnsname, PSTR("mdnsname"));
    shell_register(command_help, PSTR("help"));
}

void setup() {

    Serial.begin(9600);
    Serial.println("--- SETUP ---");

    initEEPROM();

    initShell();
    Serial.println();

    initIndicator();

    indicate(255);
    initFastLED();

    initNetwork();
    indicate(64);

    initUDP();
    indicate(255);

    initMDNS();
    indicate(10);

    Serial.println("--- SETUP DONE ---");
}

void initEEPROM() {
    if (!EEPROM.begin(128)) {
        Serial.println("Failed to initialise EEPROM");
        Serial.println("Restarting...");
        delay(1000);
        ESP.restart();
    }
}


void loop() {

    shell_task();

    handleOSCMessages();
    if (millis() < timestamp) {
        indicate(128);
    } else {
        indicate(1);
    }
}
