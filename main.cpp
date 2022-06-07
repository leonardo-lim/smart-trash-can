#include <dummy.h>
#include <Servo.h>
#include <NewPing.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define triggerPin1  14
#define echoPin1     12

#define triggerPin2  16
#define echoPin2     5

Servo mrMoveGuy;

NewPing sonar[2] = {
  NewPing(triggerPin1, echoPin1, 400),
  NewPing(triggerPin2, echoPin2, 400)
};

const char* ssid = "";
const char* password = "";
const char* host = "";
const char* ipAddress = "";

void setup() {
  mrMoveGuy.attach(13);
  Serial.begin(9600);

  IPAddress localIP( , , , );
  IPAddress gateway( , , , );
  IPAddress subnet( , , , );
  IPAddress primaryDNS( , , , );
  IPAddress secondaryDNS( , , , );

  if (!WiFi.config(localIP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA failed to configure.");
  }

  WiFi.hostname("NodeMCU");
  WiFi.begin(ssid, password);

  Serial.println("");
  Serial.print("Connecting...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Wifi connected successfully.");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP());

  delay(3000);
}

void loop() {
  WiFiClient client;

  if (!client.connect(host, 80)) {
    Serial.println("Failed to connect.");
    return;
  }

  Serial.println("Connected successfully.");

  int distance = sonar[0].ping_cm();

  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");

  boolean isOpened;

  if (distance < 10) {
    mrMoveGuy.write(180);
    isOpened = true;
    delay(1000);
  } else {
    mrMoveGuy.write(0);
    isOpened = false;
    delay(50);
  }

  Serial.println("");

  int volume = sonar[1].ping_cm();

  Serial.print("Volume : ");
  Serial.print(volume);
  Serial.println(" cm");

  if (volume > 14) {
    Serial.println("Trash can is empty.");
  } else if (volume <= 14 && volume > 10.5) {
    Serial.println("Trash can is 25% full.");
  } else if (volume <= 10.5 && volume > 7) {
    Serial.println("Trash can is 50% full.");
  } else if (volume <= 7 && volume > 3.5) {
    Serial.println("Trash can is 75% full.");
  } else {
    Serial.println("Trash can is full.");
  }

  if (volume > 14) {
    volume = 14;
  }

  int capacity =  100 - (volume * 100 / 14);

  HTTPClient http;
  String link = "http://" + ipAddress + "/smart-trash-can/send_data.php?capacity=" + String(capacity) + "&status=" + String(isOpened);

  http.begin(client, link);
  http.GET();
  http.end();

  Serial.println(" ");
  delay(1000);
}