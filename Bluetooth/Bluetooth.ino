#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3);

void setup() {
  Serial.begin(9600); //시리얼 통신 초기화
  BTSerial.begin(9600); //블루투스 모듈 초기화
}

void loop() {
  //블루투스 => 아두이노 => 시리얼모니터
  if (BTSerial.available()) {
    Serial.write(BTSerial.read());
  }
  //시리얼모니터 => 아두이노 => 블루투스
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}
