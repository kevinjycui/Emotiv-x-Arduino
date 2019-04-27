int LED = 13;

void setup() 
{
  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW); 
  Serial.begin(9600);
}

void loop() 
{
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
}
