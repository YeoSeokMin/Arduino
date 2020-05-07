const int POT=0;
int value=0;

void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  value=analogRead(POT);
  Serial.println(value);
  delay(500);
  if(1 < value < 255) {
    digitalWrite(2, HIGH);
  } else if (256 < value < 511) {
    digitalWrite(3, HIGH);
  } else if (512 < value < 767) {
    digitalWrite(4, HIGH);
  } else if (768 < value < 1023) {
    digitalWrite(5, HIGH);
  }
  

}
