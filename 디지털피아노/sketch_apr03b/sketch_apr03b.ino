#define DO 262
#define RE 294
#define MI 330
#define PA 349
#define SOL 392

int pins[] = {2,3,4,5,6};
int note[] = {DO, RE, MI, PA, SOL};

void setup() {
  for(int i=0; i<5; i++){
    pinMode(pins[i], INPUT);
  }
}

void loop() {
  for(int i=0; i<5; i++){
    if(digitalRead(pins[i])==HIGH) {
      tone(8, note[i], 20);
    }
  }
}
