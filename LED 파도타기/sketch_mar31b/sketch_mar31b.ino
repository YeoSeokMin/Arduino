#define DELAY_TIME 100
int led_pin[] = {4, 5, 6, 7, 8};
int count;

void setup() {
  count = sizeof(led_pin) / sizeof(int); //int는 4바이트이기 때문에 나누기 4(sizeof(int))를 해준다. count에 5를 넣기위함 자바의 length
  for (int i = 0; i < count; i++) {
    pinMode(led_pin[i], OUTPUT);
  }
  Serial.begin(9600); //시리얼을 초기화한다. 9600으로 통신한다. 9600은 아두이노의 속도
}

void loop() {
  for (int i = 0; i < count; i++) {
    Serial.println((i + 1) + String("번째 LED켜짐"));
    digitalWrite(led_pin[i], HIGH);
    delay(DELAY_TIME);
    digitalWrite(led_pin[i], LOW);
  }

  for (int i = count - 2; i >= 1; i--) {
    Serial.println((i + 1) + String("번째 LED켜짐"));
    digitalWrite(led_pin[i], HIGH);
    delay(DELAY_TIME);
    digitalWrite(led_pin[i], LOW);
  }
}
