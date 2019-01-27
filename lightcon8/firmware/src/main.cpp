#include <WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <OSCData.h>
#include <Arduino.h>
#include <WebServer.h>
#include <ESPmDNS.h>


char ssid[] = "Bache";          // your network SSID (name)
char pass[] = "71073826";                    // your network password

// A UDP instance to let us send and receive packets over UDP
WiFiUDP Udp;
const unsigned int localPort = 8888;        // local port to listen for UDP packets (here's where we send the packets)

OSCErrorCode error;
unsigned int ledState = LOW;              // LOW means led is *on*

WebServer server(80);

// setting PWM properties
const int freq = 5000;
const int resolution = 8;
int ledPin = 0;

IPAddress ipAddress;

void handleRoot() {
    server.send(200, "text/html", "{ ip: \""+ ipAddress.toString() + "\"}");
}

void handleIP() {
    server.send(200, "text/html", ipAddress.toString());
}

void setup() {

    Serial.begin(115200);
    Serial.println("--- SETUP ---");

    Serial.print("Setting up PWM....");
    // configure LED PWM functionalitites
    ledcSetup(1, freq, resolution);
    ledcSetup(3, freq, resolution);
    ledcSetup(4, freq, resolution);
    ledcSetup(13, freq, resolution);

    // attach the channel to the GPIO to be controlled
    ledcAttachPin(1, 1);
    ledcAttachPin(3, 3);
    ledcAttachPin(4, 4);
    ledcAttachPin(13, 13);
    Serial.println("Done");

    // Connect to WiFi network
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
    ipAddress = WiFi.localIP();

    Serial.print("Starting UDP...");
    Udp.begin(localPort);
    Serial.println("Done");

    Serial.print("Starting MDNS...");
    if (MDNS.begin("lightcon8_1")) {
        Serial.println("MDNS responder started");
    }
    Serial.println("Done");

    server.on("/", handleRoot);
    server.on("/ip", handleIP);
    server.begin();
    Serial.println("HTTP server started");

/*
    pinMode(03, OUTPUT);
    pinMode(21, OUTPUT);
    pinMode(22, OUTPUT);
    pinMode(23, OUTPUT);
    pinMode(19, OUTPUT);
    pinMode(18, OUTPUT);
    pinMode(05, OUTPUT);
    pinMode(17, OUTPUT);
    pinMode(16, OUTPUT);*/

    Serial.println("--- SETUP DONE ---");

}


void led(OSCMessage &msg) {
    ledPin = msg.getInt(0);
    ledState = msg.getInt(1);
//    digitalWrite(ledPin, ledState);
    ledcWrite(ledPin, ledState);
    Serial.print("pin:" );
    Serial.print( ledPin );
    Serial.print(" state: ");
    Serial.println(ledState);
}

void loop() {
    server.handleClient();
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
