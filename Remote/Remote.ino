#include <IRremote.h>

const int RECV_PIN  = 7;                            //IR Receiver로 수신한 값을 8번 핀으로 받습니다.
IRrecv irrecv(RECV_PIN);                     //IR Receiver를 선언합니다.
decode_results results;                     //수신결과가 저장됩니다.

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();                        //IR Receiver enable
  irrecv.blink13(true);
}

void loop() {
  if (irrecv.decode(&results)) {              //입력받은 값이 있으면
    Serial.println(results.value, HEX);      //콘솔에 출력 합니다.
    irrecv.resume();                          //다음 값을 받기위해 resume
    switch(results.value)
      case 0xFFA25D:
      Serial.println("CH-");
      break;
  }
}
