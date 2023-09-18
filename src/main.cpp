#include <Arduino.h>

#include <WiFi.h>
#include <HTTPClient.h>



const char* ssid = "Telefon MI";
const char* password = "Barcelona1";

const char* serverAddress = "https://olgierdiwaniuk.github.io/strona-/templates/";

void setup(){
    Serial.begin(115200);
    delay(1000);

    WiFi.mode(WIFI_STA); //Optional
    WiFi.begin(ssid, password);
    Serial.println("\nConnecting");

    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(100);
    }

    
}

void loop() {
    // Odczytaj stan GPIO
   int gpioState = 10 ;

    // Wyślij żądanie POST na serwer Flask
    HTTPClient http;
    http.begin(serverAddress);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
   int code= http.POST( "/set_gpio?gpio_state="+ String(gpioState));
   Serial.print(code);
    // Poczekaj przez określony czas
    delay(1000);
}
