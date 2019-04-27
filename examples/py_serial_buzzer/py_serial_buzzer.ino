const int buzzerMel = 13;
const int musicSpeed = 1.7;

#define NOTE_A2 110
#define NOTE_AS2 116
#define NOTE_B2  123
#define NOTE_C3  130
#define NOTE_CS3 138
#define NOTE_D3  146
#define NOTE_DS3 155
#define NOTE_E3  164
#define NOTE_F3  174
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 207
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  246
#define NOTE_C4  261
#define NOTE_CS4 277
#define NOTE_D4  293
#define NOTE DS4 311
#define NOTE_E4  329
#define NOTE_F4  349
#define NOTE_FS4 369
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  215
#define NOTE_AS4 466
#define NOTE_B4  493
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 739
#define NOTE_G5  783
#define NOTE_GS5 830
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  987

int melodyNotes [] = { NOTE_D4, NOTE_D4, NOTE_D5, NOTE_A4, NOTE_GS4, 0, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_C4, NOTE_D5, NOTE_A4, NOTE_GS4, NOTE_G4, 0, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_B3, NOTE_B3, NOTE_D5, NOTE_A4, NOTE_GS4, NOTE_G4, 0, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_AS3, NOTE_AS3, NOTE_D5, NOTE_A4, NOTE_GS4, NOTE_G4, 0, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_C4, NOTE_D5, NOTE_A4, NOTE_GS4, NOTE_G4, 0, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4};

int melodyDurations [] = {
  125, 125, 255, 300, 255, 125, 125, 255, 125, 125, 125,

  125, 125, 255, 300, 255, 125, 125, 255, 125, 125, 125,

  125, 125, 255, 300, 255, 125, 125, 255, 125, 125, 125,

  125, 125, 255, 300, 255, 125, 125, 255, 125, 125, 125,
 };

void setup() {
  Serial.begin(9600);
}

void loop() {
  int counter = 0;
  while (counter<sizeof(melodyNotes)) {
    int data = Serial.read(); 
    if (data=='1') 
    {    
      tone(buzzerMel, melodyNotes[counter], melodyDurations[counter]*musicSpeed);
      counter++;
      delay(melodyDurations[i]*musicSpeed);
    }
    else 
    {
      delay(125);
    }
  }
}
