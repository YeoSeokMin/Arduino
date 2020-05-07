int analogPin=0;
int led=9;
int val=0; //워터센서가 감지하는 전류 변화값을 저장한다.

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  val=analogRead(analogPin);
  if(val>500) {
    digitalWrite(led, HIGH);
  } else if(val<500){
    digitalWrite(led, LOW);
  }
  Serial.println(val);
  delay(500);

}
