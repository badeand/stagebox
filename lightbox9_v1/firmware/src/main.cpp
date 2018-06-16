//
// Created by Andreas Bade on 07.05.18.
//



#ifdef ESP8266
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#endif
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <OSCData.h>
#include <Arduino.h>


char ssid[] = "X";          // your network SSID (name)
char pass[] = "X";                    // your network password

// A UDP instance to let us send and receive packets over UDP
WiFiUDP Udp;
const IPAddress outIp(10,40,10,105);        // remote IP (not needed for receive)
const unsigned int outPort = 9999;          // remote port (not needed for receive)
const unsigned int localPort = 8888;        // local port to listen for UDP packets (here's where we send the packets)


OSCErrorCode error;
unsigned int ledState = LOW;              // LOW means led is *on*
unsigned int ledPin = 2;              // LOW means led is *on*

#ifndef BUILTIN_LED
#ifdef LED_BUILTIN
#define BUILTIN_LED LED_BUILTIN
#else
#define BUILTIN_LED 13
#endif
#endif

void setup() {
    pinMode(BUILTIN_LED, OUTPUT);
    digitalWrite(BUILTIN_LED, ledState);    // turn *on* led

    Serial.begin(115200);

    // Connect to WiFi network
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");

    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.println("Starting UDP");
    Udp.begin(localPort);
    Serial.print("Local port: ");
#ifdef ESP32
    Serial.println(localPort);
#else
    Serial.println(Udp.localPort());
#endif


    pinMode(03, OUTPUT);
    pinMode(21, OUTPUT);
    pinMode(22, OUTPUT);
    pinMode(23, OUTPUT);
    pinMode(19, OUTPUT);
    pinMode(18, OUTPUT);
    pinMode(05, OUTPUT);
    pinMode(17, OUTPUT);
    pinMode(16, OUTPUT);
}


void led(OSCMessage &msg) {
    ledPin = msg.getInt(0);
    ledState = msg.getInt(1);
    digitalWrite(ledPin, ledState);
    Serial.print("pin:" );
    Serial.print( ledPin );
    Serial.print(" state: ");
    Serial.println(ledState);
}

void loop() {
    OSCMessage msg;
    int size = Udp.parsePacket();

    if (size > 0) {
        while (size--) {
            msg.fill(Udp.read());
        }
        if (!msg.hasError()) {
            msg.dispatch("/led", led);
        } else {
            error = msg.getError();
            Serial.print("error: ");
            Serial.println(error);
        }
    }
}
