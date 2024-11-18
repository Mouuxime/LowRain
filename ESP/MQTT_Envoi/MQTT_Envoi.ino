#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiSTA.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiType.h>
#include <WiFiUdp.h>

#include <WiFi.h>
#include <PubSubClient.h>

// Wi-Fi credentials
const char* ssid = "SFR_69CF";
const char* password = "VJGFQ25W2S2M";

// Ably MQTT credentials
const char* mqtt_server = "mqtt.ably.io";
const int mqtt_port = 1883; // Use 1883 if not using TLS
const char* mqtt_username = "MKKMRQ.CoKIIA";
const char* mqtt_password = "1IOQ8NvDe7FsTlkivZbikgT6k6ipip2DR4FTznAJUbIEst";
const char* mqtt_client_id = "ESP32_1";

WiFiClient wifiClient; // Use WiFiClient if not using TLS
PubSubClient client(wifiClient);

void setup() {
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  // Connect to Ably MQTT
  client.setServer(mqtt_server, mqtt_port);
  if (client.connect(mqtt_client_id, mqtt_username, mqtt_password)) {
    Serial.println("Connected to Ably MQTT");
    client.publish("esp32/test", "Hello from ESP32!");
  } else {
    Serial.println("MQTT connection failed!");
  }
}

void loop() {
  client.loop();
}

Client.subscribe("esp32/input");
Client.setCallback(callback);

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message received on topic: ");
  Serial.println(topic);
  Serial.print("Message: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
  }
  Serial.println();
}
