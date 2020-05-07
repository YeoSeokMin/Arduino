int BTN_PIN[] = {4,5,6};
int count;

void setup() {
  count = sizeof(BTN_PIN) / sizeof(int);
  for(int i=0; i<count; i++) { //int : 4bye /4(sizeof(int)
    pinMode(BTN_PIN[i], INPUT_PULLUP); 
  }
  Serial.begin(9600);
}

void loop() {
  for(int i=0; i<count; i++) {
    int btn = digitalRead(BTN_PIN[i]);
    if(BTN_PIN[0] == 1) {
      Serial.println("1번째 버튼 입력");
      delay(1000);
    } else if(BTN_PIN[1] == 1) {
      Serial.println("2번째 버튼 입력");
      delay(1000);
    } else if(BTN_PIN[2] == 1) {
      Serial.println("3번째 버튼 입력");
      delay(1000);
    }
  }
}
