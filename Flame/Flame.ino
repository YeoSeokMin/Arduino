int flame = 0;
int buzzer = 8;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  flame = analogRead(A0);
  delay(100);
  Serial.println(String("불꽃센서 값 : ") + flame);
  delay(100);
  if (flame > 0) {
    tone(buzzer, 100, 50);
    delay(50);
    tone(buzzer, 200, 50);
    delay(50);
    tone(buzzer, 300, 50);
    delay(50);
    tone(buzzer, 400, 50);
    delay(50);
    tone(buzzer, 1000, 50);
    delay(50);
  } else {
    noTone(buzzer);
  }
}
