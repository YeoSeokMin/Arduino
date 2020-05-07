float temp;
int reading;
int lm35pin=A0;

void setup() {
  analogReference(INTERNAL);
  Serial.begin(9600);
}

void loop() {
  reading = analogRead(lm35pin);
  temp=reading/9.31;
  Serial.println(String("TEMP:")+temp);
  delay(1000);

}
