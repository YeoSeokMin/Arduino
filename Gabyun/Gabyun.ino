int vResistor=A0; //가변 저항 연결
int led_pin[]={5,6,9,10};
int arrlen;
 
void setup() {
  Serial.begin(9600);
  pinMode(vResistor, INPUT);
  arrlen=sizeof(led_pin)/sizeof(int);
  for(int i=0; i<arrlen; i++){
    pinMode(led_pin[i], OUTPUT);
  }
}

void loop() {
  int value=map(analogRead(vResistor,0,1023,0,255));
  for(int i=0: i<arrlen: i++) {
    analogWrite(led_pin[i], value);
  }
  
  Serial.println(value);
  delay(1000);
}
