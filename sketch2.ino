
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "*****";
const char* password = "*****";


const String serverPath = "http://robotcontrol.infinityfreeapp.com/get_state.php";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    // البدء بالاتصال بالرابط
    http.begin(client, serverPath);
    

    http.addHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36");

    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      String payload = http.getString();
      Serial.print("Command from server: ");
      Serial.println(payload);
    } else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    
    http.end(); // إنهاء الاتصال
  }

  delay(2000); 
}
