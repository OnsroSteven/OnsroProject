#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>  // Menggunakan HTTPS
#include <ESP8266HTTPClient.h>

//sensor
#define sensorLDR A0 

const char* ssid = "Nama_SSID"; //nama SSID atau WiFi kamu...
const char* password = "Password_WiFi"; //password SSID atau WiFi
const char* Google_script = "ID_SpreadSheet_GoogleScript"; //Masukkan Link Google Script untuk Spreadsheet

WiFiClientSecure client;
HTTPClient http;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  Serial.print("Menghubungkan ke WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nWiFi Terhubung!");

  client.setInsecure(); // Abaikan sertifikat SSL (Agar bisa HTTPS)

  pinMode(sensorLDR, INPUT);
}

void loop() {
  //troubleshoot pada SSID
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi terputus! Menghubungkan ulang...");
    WiFi.disconnect();
    WiFi.reconnect();
    delay(5000);
    return;
  }

  //pembacaan sensor
  Serial.println("Sensor LDR: " + String(analogRead(sensorLDR)));

  //nilai untuk di kirim
  int nilai1 = analogRead(sensorLDR);
  int nilai2 = 0;
  int nilai3 = 0;

  //mengirim data ke google script
  String data = String(Google_script) + "?value1=" + String(nilai1) +
                "&value2=" + String(nilai2) + "&value3=" + String(nilai3);

  Serial.println("Mengirim data: " + data);
  http.begin(client, data);
  

  //monitoring ke server
  int httpCode = http.GET();
  if (httpCode > 0) {
    String response = http.getString();
    Serial.println("Respon: " + response);
  } else {
    Serial.println("Gagal menghubungi server! Kode error: " + String(httpCode));
  }

  http.end();
  delay(5000); // Memberikan Delay 5 detik
}
