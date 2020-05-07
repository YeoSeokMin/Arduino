int tilt;
int led=8;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  tilt=analogRead(A0);
  Serial.println(String("기울기 : ")+tilt);
  delay(500);
  if(tilt>100) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
