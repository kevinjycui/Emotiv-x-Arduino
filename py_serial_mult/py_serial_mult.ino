int lights [] = {13, 12, 11, 10, 9, 8, 7};

void setup() {
    for (int i=13; i<6; i++) {
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW); 
  }
  Serial.begin(9600);
}

void loop() {
    int data = Serial.read(); 
    for (int i=0; i<7; i++) {
      int data = Serial.read(); 
      if (data=='1') 
      {
        digitalWrite(lights[i],HIGH);
      }
      else if (data=='0')
      {
        digitalWrite(lights[i],LOW);  
      }
    }
    delay(10000);
  }
}
