// NodeMCU Code (IoT Receiver)
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// Replace with your network credentials
const char* ssid = "<Your_SSID>";  // Replace with your WiFi SSID
const char* password = "<Your_PASSWORD>";  // Replace with your WiFi password

// Cloud server details
const char* apiKey = "<Your_API_Key>";  // Replace with your Write API Key
const char* server = "<Your_Cloud_Server_URL>";  // Replace with your cloud server URL

#define SLAVE_ADDRESS 8  // I2C address of the Arduino slave

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");

  // Initialize I2C as master
  Wire.begin();
}

void loop() {
  int danger = 0;

  // Request 1 byte from the slave
  Wire.requestFrom(SLAVE_ADDRESS, 1);

  // Check if data is available
  if (Wire.available()) {
    danger = Wire.read();  // Read the received byte

    // Print the danger value
    Serial.print("Danger Value: ");
    Serial.println(danger);

    // Always update cloud server, whether danger is 1 or 0
    if (danger == 1) {
      Serial.println("Danger detected! Updating cloud server...");
    } else {
      Serial.println("System is safe. Updating cloud server...");
    }

    // Update cloud server with the current danger value (0 or 1)
    updateCloudServer(danger);
  }

  delay(500);  // Small delay to avoid spamming the I2C requests
}

// Function to update cloud server
void updateCloudServer(int dangerValue) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Construct the cloud server update URL
    String url = String("http://") + server + "/update?api_key=" + apiKey + "&field3=" + String(dangerValue);

    Serial.print("Updating cloud server... ");
    WiFiClient client;  // Create a WiFiClient object
    http.begin(client, url);
    int httpCode = http.GET();  // Send the GET request

    // Check HTTP response
    if (httpCode > 0) {
      Serial.println("Update successful, HTTP Code: " + String(httpCode));
    } else {
      Serial.println("Update failed, HTTP Code: " + String(httpCode));
    }

    http.end();  // End the connection
  } else {
    Serial.println("WiFi not connected. Unable to update cloud server.");
  }
}
