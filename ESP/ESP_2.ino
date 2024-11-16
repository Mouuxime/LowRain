#include <WiFi.h>
#include <PubSubClient.h>

// Configuration WiFi
const char* ssid = "Votre_SSID";
const char* password = "Votre_MotDePasse";

// Configuration MQTT
const char* mqtt_server = "192.168.1.100"; // Adresse IP du broker MQTT
const char* mqtt_client_id = "esp32";
const char* ping_topic = "test/ping";
const char* pong_topic = "test/pong";

WiFiClient espClient;
PubSubClient client(espClient);

// Fonction de connexion WiFi
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connexion à ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connecté");
  Serial.print("Adresse IP: ");
  Serial.println(WiFi.localIP());
}

// Callback appelée lors de la réception d'un message
void callback(char* topic, byte* payload, unsigned int length) {
  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.print("Message reçu [");
  Serial.print(topic);
  Serial.print("]: ");
  Serial.println(message);

  if (String(topic) == ping_topic && message == "ping") {
    Serial.println("Ping reçu, envoi de Pong...");
    client.publish(pong_topic, "pong");
  }
}

// Reconnexion au broker MQTT en cas de déconnexion
void reconnect() {
  while (!client.connected()) {
    Serial.print("Connexion au broker MQTT...");
    if (client.connect(mqtt_client_id)) {
      Serial.println("connecté");
      client.subscribe(ping_topic);
      Serial.println("Abonné au topic: test/ping");
    } else {
      Serial.print("Échec, rc=");
      Serial.print(client.state());
      Serial.println(" Nouvelle tentative dans 5 secondes...");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
