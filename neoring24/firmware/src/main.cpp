#include "main.h"
#include "Arduino.h"
#include <WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <FastLED.h>
#include <Shell.h>

#ifdef __AVR__
#include <avr/power.h>
#endif

#define NUM_LEDS 24
#define DATA_PIN 4
CRGB leds[NUM_LEDS];

char ssid[] = "Bache";
char pass[] = "71073826";

WiFiUDP Udp;
const unsigned int localPort = 8888;

OSCErrorCode error;
IPAddress ipAddress;

// PWM parameters
const int freq = 5000;
const int resolution = 8;

const int indicatorPin = 2;

long timestamp = millis();

void indicate(int s) {
    ledcWrite(indicatorPin, s);
}

int shell_reader(char * data)
{
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
void shell_writer(char data)
{
    // Wrapper for Serial.write() method
    Serial.write(data);
}

void initNetwork();

void initUDP();

void initMDNS();

void handleOSCMessages();

void initIndicator();

void initFastLED();


void initFastLED() { FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); }

void initIndicator() {
    Serial.println("Indicator setup");
    ledcSetup(indicatorPin, freq, resolution);
    ledcAttachPin(indicatorPin, indicatorPin);
    Serial.println("Indicator setup .. done");
}

void initMDNS() {
    Serial.print("Starting MDNS...");
    if (MDNS.begin("neoring24_1")) {
        Serial.println("MDNS responder started");
    }
}

void initUDP() {
    Serial.print("Starting UDP...");
    Udp.begin(localPort);
    Serial.println("Done");
}

void initNetwork() {// Connect to WiFi network
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED) {
        indicate(255);
        delay(255);
        indicate(0);
        delay(255);
        Serial.print(".");
    }
    Serial.println("");

    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    ipAddress = WiFi.localIP();
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


int command_help(int argc, char** argv)
{
    shell_println("  reset - reset the system");
    return SHELL_RET_SUCCESS;
}


int command_reset(int argc, char** argv)
{
    shell_println("Resetting system");
    ESP.restart();
    return SHELL_RET_SUCCESS;
}

void initShell() {
    shell_init(shell_reader, shell_writer, 0);

    shell_register(command_reset, PSTR("reset"));
    shell_register(command_help, PSTR("help"));
}

void setup() {

    Serial.begin(9600);

    initShell();

    Serial.println("--- SETUP ---");

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


void loop() {

    shell_task();

    handleOSCMessages();
    if (millis() < timestamp) {
        indicate(128);
    } else {
        indicate(1);
    }
}
