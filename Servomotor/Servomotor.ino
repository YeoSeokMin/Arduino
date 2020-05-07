#include <Servo.h>
Servo myservo; //서보모터 객체 생성

#define trig 7 //trig 할당
#define echo 6 //echo 할당
int angle = 0; //서보모터 각도 변수 초기화

void setup() {
  myservo.attach(9); //서보모터 핀번호 9
  Serial.begin(9600);
  pinMode(trig, OUTPUT); //trig OUTPUT 세팅
  pinMode(echo, INPUT);  //echo INPUT 세팅

  pinMode(12, OUTPUT);  //LED 출력모드
  pinMode(13, OUTPUT);  
}

void loop() {
  long duration, distance; //기본 변수 선언
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2); //2 마이크로초 중단 2유지
  digitalWrite(trig, HIGH); //중단 후 trig HIGH
  delayMicroseconds(10); //10 마이크로초 중단 10유지
  digitalWrite(trig, LOW); //중단 후 trig LOW

  duration = pulseIn(echo, HIGH); //echo가 HIGH를 유지한 시간을 저장
  distance = ((float)(340 * duration) / 10000) / 2; //거리 계산

  Serial.println(String("거리 : ") + distance + ("CM")); //측정된 거리 값 시리얼 모니터에 출력

  if (distance < 10) { 
    angle = 90;//측정된 거리가 10cm 이하면 모터 90도 회전
    on(); //문이 열릴때 메서드(녹색LED HIGH)
    delay(500); //딜레이 0.5초
  } else { 
    angle = -80; //측정된 거리가 10cm 이상이면 모터 -80도 회전
    off(); //문이 닫힐때 메서드(적색LED HIGH)
    delay(500); //딜레이 0.5초
  }
  myservo.write(angle); //서보모터를 angle 값 만큼 작동시킴
}

void on() { //문이 열릴때 메서드(녹색LED HIGH)
  digitalWrite(12, HIGH); //문이 열리면 녹색LED HIGH
  digitalWrite(13, LOW);  //적색LED LOW
  Serial.println("문이 열렸습니다.");
}
void off() { //문이 닫힐때 메서드(적색LED HIGH)
  digitalWrite(12, LOW);   //문이 닫히면 적색LED HIGH
  digitalWrite(13, HIGH);  //녹색LED LOW
  Serial.println("문이 닫혔습니다.");
}
