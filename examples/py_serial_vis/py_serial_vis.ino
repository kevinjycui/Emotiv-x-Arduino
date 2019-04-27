int LED = 13;
int choice;

int lights [] = {13, 12, 11, 10, 9, 8, 7};

void setup() 
{
  for (int i=13; i<6; i++) {
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW); 
  }
  Serial.begin(9600);
  while (true) {
    if (Serial.read()=='s') {
      choice = true;
      break;
    } else if (Serial.read()=='m') {
      choice = false;
      break;
    }
  }
}

void loop() 
{
  if (choice) {
    int data = Serial.read(); 
    if (data=='1') 
    {
      digitalWrite(LED,HIGH);
      delay(10000);
    }
    else
    {
      digitalWrite(LED,LOW);  
    }
  } else {
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
