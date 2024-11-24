#include <WiFi.h>
#include <HTTPClient.h>

// Configuration Wi-Fi
const char* ssid = "SFR_69CF";
const char* password = "VJGFQ25W2S2";

// URL du serveur Node-RED
const char* serverName = "http://127.0.0.1:1880/pingpong";

// Variables pour le ping-pong
String messageToSend = "Ping";
String expectedResponse = "Pong";

void setup() {
  Serial.begin(115200);

  // Connexion Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connecté.");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) { // Si Wi-Fi est connecté
    HTTPClient http;

    // Envoi du message Ping
    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");

    // Préparer le JSON à envoyer
    String jsonMessage = "{\"message\":\"" + messageToSend + "\"}";

    // Envoyer la requête POST
    int httpResponseCode = http.POST(jsonMessage);

    // Vérifier la réponse
    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Réponse reçue : " + response);

      // Vérifier si la réponse correspond à "Pong"
      if (response.indexOf(expectedResponse) != -1) {
        Serial.println("Pong reçu, envoi de Ping...");
        delay(2000); // Attente avant de renvoyer le Ping
      } else {
        Serial.println("Réponse inattendue.");
      }
    } else {
      Serial.println("Erreur lors de la requête HTTP");
    }

    http.end(); // Fermer la connexion HTTP
  } else {
    Serial.println("WiFi non connecté");
  }

  delay(5000); // Attendre avant la prochaine tentative
}
