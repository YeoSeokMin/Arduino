int inPin = 9;
int val;

void setup() {
  Serial.begin(9600);
  pinMode(inPin, INPUT);

}

void loop() {
  val = analogRead(inPin);
  Serial.println(val, DEC);
  delay(100);
}
