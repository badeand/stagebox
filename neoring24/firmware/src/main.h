#include "Arduino.h"
#include <WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <FastLED.h>

#ifdef __AVR__
#include <avr/power.h>
#endif

#define NUM_LEDS 24
#define DATA_PIN 4
CRGB leds[NUM_LEDS];

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            4

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      24

char ssid[] = "Bache";          // your network SSID (name)
char pass[] = "71073826";                    // your network password

// A UDP instance to let us send and receive packets over UDP
WiFiUDP Udp;
const unsigned int localPort = 8888;        // local port to listen for UDP packets (here's where we send the packets)


OSCErrorCode error;
IPAddress ipAddress;


int delayval = 1; // delay for half a second

const int freq = 5000;
const int resolution = 8;



const int indicatorPin = 2;

void indicate(int s) {
    ledcWrite(indicatorPin, s);
}

void initNetwork();

void initUDP();

void initMDNS();

void handleOSCMessages();

void ringTest();

void initIndicator();

void initFastLED();

void setup() {

    Serial.begin(9600);

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

void led(OSCMessage &msg) {
    int index = msg.getInt(0);
    int r = msg.getInt(1);
    int g = msg.getInt(2);
    int b = msg.getInt(3);
    leds[index] = CRGB(r,g,b);
    FastLED.show();
}

long timestamp = millis();

void loop() {
    handleOSCMessages();
    if( millis() < timestamp ) {
        indicate(128);
    } else {
        indicate(1);
    }
}

void handleOSCMessages() {// server.handleClient();
    OSCMessage msg;
    int size = Udp.parsePacket();

    if (size > 0) {
        timestamp = millis() + 250;
        while (size--) {
            msg.fill(Udp.read());
        }
        if (!msg.hasError()) {
            msg.dispatch("/led", led);
        } else {
            error = msg.getError();
            Serial.print("error: ");
            Serial.println("" + error);
        }
    }
}