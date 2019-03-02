
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <OSCData.h>
#include <WebServer.h>
#include <ESPmDNS.h>

char ssid[] = "Andreas's iPhone";          // your network SSID (name)
char pass[] = "badeerbest";                    // your network password

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

const int indicatorPin = 2;

void indicate(int s) {
    ledcWrite(indicatorPin, s);
}

void lprint(String s) {

}

void lprintln(String s) {

}


void setup() {

    // Serial.begin(115200);

    lprint("PWN Setup.ch/pin: 2 ..");
    ledcSetup(indicatorPin, freq, resolution);
    ledcAttachPin(indicatorPin, indicatorPin);

    lprint("PWN Setup.ch/pin: 1 ..");
    ledcSetup(1, freq, resolution);
    ledcAttachPin(1, 1);
    lprint("PWN Setup.ch/pin: 3 ..");
    ledcSetup(3, freq, resolution);
    ledcAttachPin(3, 3);
    lprint("PWN Setup.ch/pin: 4 ..");
    ledcSetup(4, freq, resolution);
    ledcAttachPin(4, 4);
    lprint("PWN Setup.ch/pin: 13 ..");
    ledcSetup(13, freq, resolution);
    ledcAttachPin(13, 13);
    lprintln("done.");


    for( int startcnt = 0 ; startcnt < 20 ; startcnt++) {
        indicate(255);
        ledcWrite(1, 255);
        ledcWrite(3, 255);
        ledcWrite(4, 255);
        ledcWrite(13, 255);
        delay(35);
        indicate(0);
        ledcWrite(1, 0);
        ledcWrite(3, 0);
        ledcWrite(4, 0);
        ledcWrite(13, 0);
        delay(35);
    }
    indicate(20);

    lprintln("--- SETUP ---");

   // Connect to WiFi network
   lprint("Connecting to ");
   lprintln(ssid);
   WiFi.begin(ssid, pass);

   while (WiFi.status() != WL_CONNECTED) {
       indicate(255);
       delay(255);
       indicate(0);
       delay(255);
       lprint(".");
   }
   lprintln("");

   lprintln("WiFi connected");
   lprintln("IP address: ");
   lprintln(""+ WiFi.localIP());
   ipAddress = WiFi.localIP();

   indicate(64);

   lprint("Starting UDP...");
   Udp.begin(localPort);
   lprintln("Done");

   indicate(255);

   lprint("Starting MDNS...");
   if (MDNS.begin("lightcon8_1")) {
       lprintln("MDNS responder started");
   }
   lprintln("Done");

   indicate(128);

   server.on("/", handleRoot);
   server.on("/ip", handleIP);
   server.begin();
   lprintln("HTTP server started");


    lprintln("Setting up PWM");


    lprintln("--- SETUP DONE ---");


    indicate(20);
}

void led(OSCMessage &msg) {

    ledPin = msg.getInt(0);
    ledState = msg.getInt(1);
    ledcWrite(ledPin, ledState);
    // lprint("pin:" );
    // lprint( ledPin );
    // lprint(" state: ");
    // lprintln(ledState);
}

long timestamp = millis();

void loop() {

    // lprint(".");
    server.handleClient();
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
            lprint("error: ");
            lprintln(""+error);
        }
    }

    if( millis() < timestamp ) {
        indicate(255);
    } else {
        indicate(10);
    }

}
