#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "Masukan Template ID Anda"
#define BLYNK_DEVICE_NAME "Masukan Device Name Anda"
#define BLYNK_AUTH_TOKEN "Masukan Token Anda"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define ledBiru D13 //pin LED Biru
#define ledMerah D12 //pin LED Merah

#define ledR D9
#define ledB D11
#define ledG D10

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SSID";      //Masukkan nama Wifi
char pass[] = "PASSWORD";  //Masukkan password Wifi

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  pinMode(ledBiru, OUTPUT);
  pinMode(ledMerah, OUTPUT);
  pinMode(ledR,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(ledB,OUTPUT);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  Serial.print("V0 Switch value is: ");
  Serial.println(pinValue);

  digitalWrite(ledBiru, pinValue);
}
BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();
  Serial.print("V2 Switch value is: ");
  Serial.println(pinValue);

  digitalWrite(ledR, pinValue);
}

BLYNK_WRITE(V3)
{
  int pinValue = param.asInt();
  Serial.print("V3 Switch value is: ");
  Serial.println(pinValue);

  digitalWrite(ledG, pinValue);
}

BLYNK_WRITE(V4)
{
  int pinValue = param.asInt();
  Serial.print("V4 Switch value is: ");
  Serial.println(pinValue);

  digitalWrite(ledB, pinValue);
}
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  Serial.print("V1 Switch value is: ");
  Serial.println(pinValue);

  digitalWrite(ledMerah, pinValue);
}