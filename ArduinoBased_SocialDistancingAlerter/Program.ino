const int trigPin = 9; //trigger pin of sensor is connected to pin 9 of arduino
const int echoPin = 10; //echo pin of sensor is connected to pin 10 of arduino
const int buzzPin = 2; //input to buzzer is connected to pin 2 of arduino
int dist;
long duration;

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT); 
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000); 
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  dist = duration*0.034/2; //assuming speed of sound in air is 340m/s (340m/s == 0.034cm/us) 

  if(dist <= 182 && dist >=0)
  {
    digitalWrite(buzzPin, HIGH);
    tone(2, 500, 120); //tone(pin, frequency(in Hz), duration(in ms)
  }
  else
  {
    digitalWrite(buzzPin, LOW);
  }
}
  
