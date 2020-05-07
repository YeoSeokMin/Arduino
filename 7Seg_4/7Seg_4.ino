byte patterns[] = {
  0x03, // 11111100 : 0
  0x9F, // 01100000 : 1
  0x25, // 11011010 : 2
  0x0D, // 11110010 : 3
  0x99, // : 4
  0x49, // : 5
  0x41, // : 6
  0x1B, // : 7
  0x01, // : 8
  0x19  // : 9
};
int ds_pin[] = {10, 11, 12, 13};
int segment_pin[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int S_DELAY = 5; //숫자표시 시간 간격

int hours = 12;  //시작 시간입니다.
int minutes = 12; //시작 분입니다.
int second = 0; //0초부터 시작합니다.
unsigned long time_previous, time_current;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) { //자리수 선택 핀을 출력으로 설정
    pinMode(ds_pin[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) { //세그먼트 제어핀을 출력으로 설정
    pinMode(segment_pin[i], OUTPUT);
  }
}

void loop() {
  //  int reading = analogRead(A0); //가변 저항값을 읽어서 reading 변수에 입력
  //  show4digit(reading);
  time_current = millis();
  if(time_current-time_previous>1000){
    time_previous = time_current;
    second++;
    if(second == 60) {
      second = 0;
      minutes++;
    }
    if(minutes == 60)minutes=0;
  }
  show4digit(minutes*100+second);
}
void show4digit(int num) {
  int number = num;
  number = number % 10000; // 4자리로 제한
  int thousands = number / 1000; // 천의자리
  number = number % 1000;
  int hundreads = number / 100; // 백 자리
  number = number % 100;
  int tens = number / 10; // 십 자리
  int ones = number % 10; // 일 자리
  if (num > 999)showdigit(1,thousands);
  delay(S_DELAY);
  if (num > 99)showdigit(2,hundreads);
  delay(S_DELAY);
  if (num > 9)showdigit(3,tens);
  delay(S_DELAY);
  showdigit(4, ones);
  delay(S_DELAY);

  Serial.println(number);
  delay(500);
}
void showdigit(int pos, int number) { //위치와 출력할 숫자
  for (int i = 0; i < 4; i++) {
    if (i + 1 == pos) { //해당 자릿수의 선택 핀만 LOW로 설정
      digitalWrite(ds_pin[i], HIGH);
    } else {
      digitalWrite(ds_pin[i], LOW);
    }
  }
  for (int i = 0; i < 8; i++) {
    boolean onOff = bitRead(patterns[number], 7 - i); //bitRead : 16진수를 썻기에 사용
    digitalWrite(segment_pin[i], onOff);
  }
}
