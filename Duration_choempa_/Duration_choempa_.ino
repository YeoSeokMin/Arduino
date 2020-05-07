#define red 11
#define green 10
#define blue 9

#define trig 3
#define echo 4
//거리가 10cm 이내이면 적색
// 11-20cm 녹색
// 21-30cm 청색
// 그외 꺼짐.
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2); //백만분의 2초
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long distance = pulseIn(echo, HIGH) / 58.2;
  //58.2로 나누는 이유 : 거리(d)=시간(t) X 속도(v) 미터
  if (distance < 10) {
    digitalWrite(red, 255);
  } else if (distance < 20) {
    digitalWrite(green, 255);
  } else if (distance < 30) {
    digitalWrite(blue, 255);
  } else {
    digitalWrite(red, 0);
    digitalWrite(green, 0);
    digitalWrite(blue, 0);
  }

  Serial.println(String("초음파 측정 거리 : ") + distance);
  delay(1000);
}
