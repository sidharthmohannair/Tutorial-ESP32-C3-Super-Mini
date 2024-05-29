/*
   ESP32-C3 Super mini with DHT11/DHT22 &  Display Values Using Web Server
  This is code created by Sidharth Mohan : https://github.com/sidharthmohannair/
*/


#include <WiFi.h>
#include <WebServer.h>
#include "DHT.h"

// Uncomment one of the lines below for the DHT sensor type you're using
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
//#define DHTTYPE DHT22   // DHT 22 (AM2302), AM2321

/* Put your SSID & Password */
const char* ssid = "POCO F5";       // Enter your WiFi SSID
const char* password = "987456321";     // Enter your WiFi password

WebServer server(80); // Create a web server object that listens for HTTP requests on port 80

// DHT Sensor pin
uint8_t DHTPin = 10;

// Initialize DHT sensor.
DHT dht(DHTPin, DHTTYPE);

float Temperature;
float Humidity;

// Debug Macros for easy debugging
// uncomment "#define DEBUG" this for activate debug
//#define DEBUG
#ifdef DEBUG
  #define DEBUG_PRINT(x) Serial.print(x)
  #define DEBUG_PRINTLN(x) Serial.println(x)
#else
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTLN(x)
#endif

void setup() {
  Serial.begin(115200); // Start the Serial communication to send messages to the computer
  delay(100);

  dht.begin(); // Initialize the DHT sensor

  DEBUG_PRINTLN("Connecting to WiFi...");
  WiFi.begin(ssid, password); // Connect to Wi-Fi network

  // Wait until the device is connected to Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    DEBUG_PRINT(".");
  }
  DEBUG_PRINTLN("\nWiFi connected!");
  DEBUG_PRINT("IP Address: ");
  DEBUG_PRINTLN(WiFi.localIP()); // Print the IP address

  server.on("/", handle_OnConnect); // Define handling function for root URL
  server.onNotFound(handle_NotFound); // Define handling function for 404 (Not Found)

  server.begin(); // Start the HTTP server
  DEBUG_PRINTLN("HTTP server started");
}

void loop() {
  server.handleClient(); // Handle client requests
}

// Handle connection to the root URL
void handle_OnConnect() {
  Temperature = dht.readTemperature();  // Get temperature value
  Humidity = dht.readHumidity();        // Get humidity value

  // Check if any reading failed and send "N/A" if so
  if (isnan(Temperature) || isnan(Humidity)) {
    DEBUG_PRINTLN("Failed to read from DHT sensor!");
    server.send(200, "text/html", SendHTML("N/A", "N/A"));
  } else {
    DEBUG_PRINT("Temperature: ");
    DEBUG_PRINTLN(Temperature);
    DEBUG_PRINT("Humidity: ");
    DEBUG_PRINTLN(Humidity);
    server.send(200, "text/html", SendHTML(String(Temperature), String(Humidity))); // Send the HTML page with the values
  }
}

// Handle not found URL
void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}

// Generate the HTML content to display
String SendHTML(String Temperaturestat, String Humiditystat) {
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>ESP32 Temperature & Humidity</title>\n";
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr += "body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;}\n";
  ptr += "p {font-size: 24px;color: #444444;margin-bottom: 10px;}\n";
  ptr += "</style>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<div id=\"webpage\">\n";
  ptr += "<h1>ESP32 Temperature & Humidity</h1>\n";

  ptr += "<p>Temperature: ";
  ptr += Temperaturestat;
  ptr += " &deg;C</p>";
  ptr += "<p>Humidity: ";
  ptr += Humiditystat;
  ptr += "%</p>";

  ptr += "</div>\n";
  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}
