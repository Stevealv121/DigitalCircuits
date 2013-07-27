
long cm;
long duration;

long distance;


int echoPin = 2;
int triggerPin = 3;

void setup()
{
 pinMode(echoPin,INPUT);
 pinMode(triggerPin,OUTPUT);
 Serial.begin(9600);
}

void loop()
{ 
  distance = getDistance();
  Serial.println(distance);
  delay(10);
  
}

long getDistance()
{
   //We are telling the ultrasonic module to send a short pulse
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(80);
  digitalWrite(triggerPin,LOW);  
  
  duration = pulseIn(echoPin,HIGH);  // What does this line do? How long we waited for the ultrasonics's Echo
  
  //How many microseconds does it take for sound to go 1cm? Ans: around 28 seconds
  cm = duration/57;
  if (cm < 1000)  
  {
    return cm;
  }
  else
  {
    return -1;
  }
}
