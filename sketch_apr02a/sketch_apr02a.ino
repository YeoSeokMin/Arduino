#define RED 9
#define GREEN 10
#define BLUE 11
#define BUTTON 2

boolean lastButton=LOW;
boolean currentButton=LOW;

int ledMode=0;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(BUTTON, INPUT);

}

void loop() {
  currentButton=debounce(lastButton);
  if(lastButton == LOW && currentButton == HIGH) {
    ledMode++;
  }
  lastButton=currentButton;
  if(ledMode==8) {
    ledMode=0;
  } else {
    setMode(ledMode);
  }
}
boolean debounce(boolean last){
  boolean current=digitalRead(BUTTON); 
  if(last != current) {
    delay(5);
    current=digitalRead(BUTTON);
  }
  return current;
}
void setMode(int mode){
  if(mode==1) { // RED
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  } else if(mode==2) { //GREEN
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);
  } else if(mode==3) {//BLUE
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
  } else if(mode==4) { //PUPLE
    analogWrite(RED, 127);
    analogWrite(GREEN, 0);
    analogWrite(BLUE, 127);
  } else if(mode==5) { //TEAL
    analogWrite(RED, 0);
    analogWrite(GREEN, 127);
    analogWrite(BLUE, 127);
  } else if(mode==6) { //ORANGE
    analogWrite(RED, 127);
    analogWrite(GREEN, 127);
    analogWrite(BLUE, 0);
  } else if(mode==7) { //WHITE
    analogWrite(RED, 85);
    analogWrite(GREEN, 85);
    analogWrite(BLUE, 85);
  } else { //mode==0
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  }
}
