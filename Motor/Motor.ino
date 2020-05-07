#include <Servo.h>
Servo myservo; //라이브러리 변수 초기화
int pos = 0; //각도 초기화
void setup() {
  myservo.attach(9); //서보모터를 제어할 핀번호

}

void loop() {
  myservo.write(map(analogRead(A0), 0, 1023, 0, 1023));
  delay(15);
}
