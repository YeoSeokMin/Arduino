int led=9;
int value;
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  value=map(analogRead(A0),1023,0,0,255);
  Serial.println(value);
  if(value<100) {
    analogWrite(led,0);
  } else {
    analogWrite(led,value);
  }
}
