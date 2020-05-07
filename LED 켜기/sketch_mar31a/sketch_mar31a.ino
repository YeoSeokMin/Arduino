#define DELAY_TIME 100

void setup() {
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);


}

void loop() {
  digitalWrite(4,HIGH); //4번 포트에 전기공급
  delay(DELAY_TIME);    //딜레이 0.1초 (위에 DELAY_TIME 100)선언
  digitalWrite(4,LOW);

  digitalWrite(5,HIGH);
  delay(DELAY_TIME);
  digitalWrite(5,LOW);

  digitalWrite(6,HIGH);
  delay(DELAY_TIME);
  digitalWrite(6,LOW);

  digitalWrite(7,HIGH);
  delay(DELAY_TIME);
  digitalWrite(7,LOW);

  digitalWrite(8,HIGH);
  delay(DELAY_TIME);
  digitalWrite(8,LOW);
}
