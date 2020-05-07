#include "pitches.h"
int melody[] ={
  NOTE_G4, NOTE_G4, NOTE_A5, NOTE_A5, 
  NOTE_G4, NOTE_G4, NOTE_E4, NOTE_G4, 
  NOTE_G4, NOTE_E4, NOTE_E4, NOTE_D4, 
  0,
  NOTE_G4, NOTE_G4, NOTE_A5, NOTE_A5, 
  NOTE_G4, NOTE_G4, NOTE_E4, NOTE_G4, 
  NOTE_E4, NOTE_D4, NOTE_E4, NOTE_C4, 
  0
};

int noteDurations[]= {
  1,1,1,1,1,1,2,1,1,1,3,1,
  1,1,1,1,1,1,2,1,1,1,3,1
};
void setup() {
  int noteDuraion, pause;
  for(int node=0; node<26; node++){
    noteDuraion=250*noteDurations[node];
    tone(8, melody[node],noteDuraion);
    int pause=noteDuraion*1.3;
    delay(pause);
    noTone(8);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
