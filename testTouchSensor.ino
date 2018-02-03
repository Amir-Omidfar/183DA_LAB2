
 int touchPin =5; // pin D1
 int Buzzer = 15; //pin D8
 int delay_t=1000;
 int counter=1;
void setup() 
{
 
  Serial.begin(9600); 
  pinMode(touchPin, INPUT);
  pinMode(Buzzer,OUTPUT);
}
 
void loop() 
{
  int touchValue = digitalRead(touchPin);
  if (touchValue == HIGH)
  {
    
    Serial.println("TOUCHED");
    digitalWrite(Buzzer,HIGH);
    //delay(delay_t);
    delay(500);
    digitalWrite(Buzzer,LOW);
  }
  else
  {
    Serial.println("not touched");
  } 
  delay(500);
 
}
