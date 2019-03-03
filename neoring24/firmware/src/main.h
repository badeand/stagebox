#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <OSCData.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

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

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
//Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB);

int delayval = 1; // delay for half a second

const int freq = 5000;
const int resolution = 8;


int ledPin = 0;
int ledR = 0;
int ledG = 0;
int ledB = 0;

const int indicatorPin = 2;

void indicate(int s) {
    // ledcWrite(indicatorPin, s);
}

void initNetwork();

void initUDP();

void initMDNS();

void handleOSCMessages();

void ringTest();

void setup() {

    Serial.begin(9600);

    /*
    Serial.print("PWN Setup.ch/pin: 2 ..");
    ledcSetup(indicatorPin, freq, resolution);
    ledcAttachPin(indicatorPin, indicatorPin);
*/

    Serial.println("--- SETUP ---");

    // initNetwork();
    indicate(64);

    // initUDP();
    indicate(255);

    // initMDNS();
    indicate(10);

    pixels.begin();

    Serial.println("--- SETUP DONE ---");
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

    ledPin = msg.getInt(0);
    ledR = msg.getInt(1);
    // ledcWrite(ledPin, ledState);
    Serial.print("pin:" );
    Serial.print( ledPin );
    Serial.print(" ledR: ");
    Serial.println(ledR);

    pixels.setPixelColor(ledPin, pixels.Color(ledR,0,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.

}

long timestamp = millis();


void loop() {
    // handleOSCMessages();
    ringTest();
}

void ringTest() {
    for(int i=0; i < NUMPIXELS; i++){
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
        delay(1);
        pixels.show(); // This sends the updated pixel color to the hardware.
        delay(delayval); // Delay for a period of time (in milliseconds).
    }
    for(int i=0;i<NUMPIXELS;i++){
        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
        delay(1);
        pixels.show(); // This sends the updated pixel color to the hardware.
        delay(delayval); // Delay for a period of time (in milliseconds).
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
            Serial.println(""+error);
        }
    }

    if( millis() < timestamp ) {
        indicate(255);
    } else {
        indicate(10);
    }
}