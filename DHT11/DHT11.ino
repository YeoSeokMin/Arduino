#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(2, OUTPUT);
}

void loop() {
  delay(1000);
  float h=dht.readHumidity(); //습도 측정
  float t=dht.readTemperature(); //온도 측정
  float f=dht.readTemperature(true); //화씨 측정
  if(isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("DHT센서 에러");
    return;
  }

  if(55<h) {
    digitalWrite(2, HIGH);
  }
  
  float hif=dht.computeHeatIndex(f,h); //보정된 화씨 값
  float hic=dht.computeHeatIndex(t,h); //보정된 섭씨 값
  
  Serial.println(String("습도 ")+h);
  Serial.println(String("온도 ")+t);
  Serial.println(String("화씨 ")+f);
  Serial.println(String("보정된 화씨 ")+hif);
  Serial.println(String("보정된 섭씨 ")+hic);
}
