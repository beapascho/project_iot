#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// Wi-Fi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// MQTT
const char* mqttServer = "test.mosquitto.org";
const int mqttPort = 1883;
const char* topicTemperature = "misandro/temperature";
const char* topicHumidity = "misandro/humidity";
const char* topicRelay = "misandro/relay";

// Pinos
#define DHTPIN 13
#define DHTTYPE DHT22
#define RELAY_PIN 12

// Objetos
DHT dht(DHTPIN, DHTTYPE);
WiFiClient espClient;
PubSubClient client(espClient);

// Reconectar ao broker MQTT
void reconnectMQTT() {
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println(" conectado!");
    } else {
      Serial.print(" falhou. Código: ");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);

  // Conectar ao Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Conectando ao Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi conectado!");

  // Conectar ao servidor MQTT
  client.setServer(mqttServer, mqttPort);
}

void loop() {
  if (!client.connected()) {
    reconnectMQTT();
  }
  client.loop();

  // Ler sensores
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Erro na leitura do sensor DHT!");
    delay(2000);
    return;
  }

  // Controlar atuador (relé)
  bool relayState = false;
  if (temperature > 26.0) {
    digitalWrite(RELAY_PIN, HIGH);
    relayState = true;
  } else {
    digitalWrite(RELAY_PIN, LOW);
    relayState = false;
  }

  // Publicar via MQTT
  client.publish(topicTemperature, String(temperature).c_str());
  client.publish(topicHumidity, String(humidity).c_str());
  client.publish(topicRelay, relayState ? "ON" : "OFF");

  // Mostrar no console
  Serial.println("===== Leitura de Sensores =====");
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Umidade: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Relé (atuador): ");
  Serial.println(relayState ? "LIGADO (ON)" : "DESLIGADO (OFF)");

  Serial.println("Dados publicados via MQTT.");
  Serial.println("===============================");
  Serial.println();

  delay(10000); // Aguarda 10 segundos
}
