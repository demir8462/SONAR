
float duration, distance;
bool isSignalSent = false;
void setup() {
  pinMode(10, INPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, 1);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT); // bosaltici
  Serial.begin(115200);
}
void  sendPulse()
{
  digitalWrite(8,0);
  digitalWrite(7,0);
  digitalWrite(6,1);
  delayMicroseconds(13);
  PORTB = B00000000;
  delayMicroseconds(13);
  PORTB = B00000001; 
  delayMicroseconds(13);
  PORTB = B00000000;
  delayMicroseconds(13);
  PORTB = B00000001; 
  delayMicroseconds(13);
  PORTB = B00000000;
  delayMicroseconds(13);
  PORTB = B00000001; 
  delayMicroseconds(13);
  PORTB = B00000000;
  delayMicroseconds(13);
  PORTB = B00000001; 
  delayMicroseconds(13);
  PORTB = B00000000;
  delayMicroseconds(13);
  PORTB = B00000001; 
  delayMicroseconds(13);
  PORTB = B00000000;
  delayMicroseconds(13);
  PORTB = B00000001; 
  delayMicroseconds(13);
  PORTB = B00000000;
  delayMicroseconds(13);
  PORTB = B00000001; 
  delayMicroseconds(13);
  PORTB = B00000000;
  delayMicroseconds(26);
  PORTB = B00000001; 
  delayMicroseconds(10);
  digitalWrite(7,1);
  digitalWrite(6,0);
  delayMicroseconds(10); 
  digitalWrite(9, 1);
  delayMicroseconds(1790); 
  digitalWrite(9, 0);
  isSignalSent = true;
  delayMicroseconds(1000);

}

long secondsCounter=0;
void reset()
{
  secondsCounter =0;
  digitalWrite(9, 1);
  isSignalSent = false;
  delay(1500);
}
void loop() {
  if(!isSignalSent)
  {
    sendPulse();
    return;
  }
  else
  {
    if(digitalRead(10))
    {
      Serial.print(((float)(secondsCounter+3031))/20000*330);
      Serial.println("cm");
      reset();
    }
    else
    {
      secondsCounter+=16;
      delayMicroseconds(10);
      if(secondsCounter >= 15000)
      {
        reset();
      }
    }
  }
  
  
}