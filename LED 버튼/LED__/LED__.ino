#define LED 9
#define BUTTON 2
//채터링현상을 없애기 위한 해결방안
boolean lastButton=LOW; //이전버튼의 눌림상태를 불린 변수로 저장함.
boolean currentButton=LOW; //현재버튼의 눌림상태를 불린 변수로 저장함.
boolean ledOn=false; //현재 LED 점멸상태

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  currentButton=debounce(lastButton);
    if(lastButton==LOW && currentButton==HIGH) {//버튼을 눌렀을때
      ledOn=!ledOn;
  }
  lastButton=currentButton; //이전 버튼 상태값을 현재 버튼 상태값으로 저장
  digitalWrite(LED, ledOn);
}
boolean debounce(boolean last) {
  boolean current=digitalRead(BUTTON); //현재 버튼상태
  if(last!=current){ //이전 버튼상태와 현재버튼상태가 다름.
    delay(5); //5ms를 기다림.
    current=digitalRead(BUTTON); //current에 현재 버튼상태를 저장
  }
  return current; //반환
}
