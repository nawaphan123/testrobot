#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6Tn62NVbj"
#define BLYNK_TEMPLATE_NAME "Uno R4 WiFi"
#define BLYNK_AUTH_TOKEN "9lPU36ty36eNjqTAXWpMFML4Mi34ydXD"
#define BLYNK_SERVER "blynk.cloud"

#include <BlynkMultiClient.h>
#include <WiFiS3.h>

static WiFiClient blynkWiFiClient;



void connectWiFi() {
  Serial.println("Connecting to " + String("Artron@Kit"));

  WiFi.begin("Artron@Kit", "Kit_Artron");

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
}

void blynkRun() {
  if (WiFi.status() != WL_CONNECTED) {
    connectWiFi();
    return;
  }
  Blynk.run();
}


void setup() {
  Serial.begin(115200);

  connectWiFi();

  Blynk.addClient("WiFi", blynkWiFiClient, 80);
  Blynk.config(BLYNK_AUTH_TOKEN, BLYNK_SERVER);
}

void loop() {
  blynkRun();
}
