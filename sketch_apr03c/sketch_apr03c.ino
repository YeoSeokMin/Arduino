int val=0;
int analogPin=0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  val=analogRead(analogPin);
  if(val<600) {
    tone(8, map(analogRead(A0), 0, 1023, 31, 4978), 20); //밝을때 무음
    delay(500);
  } else if (600>val) {
    tone(8, map(analogRead(A0), 1023, 0, 31, 4978), 20); //어두울때 알람
    delay(500);
  }
  Serial.println(val);
  delay(500);
}
