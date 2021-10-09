// Includes the Servo library
#include <Servo.h>. 
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 4;
const int echoPin = 5;
const int buzzPin = 9;
const int ledPin = 13;
// Variables for the duration and the distance
long period;
int dist;
Servo myServo; // Creates a servo object for controlling the servo motor
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzzPin, OUTPUT); // Sets the buzzPin as an Output
  pinMode(ledPin, OUTPUT); //Sets the ledPin as an Output
  Serial.begin(9600); //Sets the baudrate for serial monitor
  myServo.attach(3); // Defines on which pin is the servo motor attached
}
void loop() {
  // rotates the servo motor from 15 to 170 degrees
  for(int i=20;i<=170;i++){  
  myServo.write(i);
  delay(20);
  dist = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
  if(dist <=30 && dist >0) //Turns the buzzer ON if an object is detected at a distance less than what is given 
  {
    digitalWrite(ledPin,HIGH);
    tone(buzzPin,1000);
    delay(1000);
    noTone(buzzPin);
  }
  else
  {
    digitalWrite(ledPin,LOW);
    digitalWrite(buzzPin,LOW);
  }
  
  Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(dist); // Sends the distance value into the Serial Port
  Serial.print(";"); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  // Repeats the previous lines from 170 to 15 degrees
  for(int i=170;i>20;i--){  
  myServo.write(i);
  delay(20);
  dist = calculateDistance();
  if( dist <=30 && dist >0)
  {
    digitalWrite(ledPin,HIGH);
    tone(buzzPin,1000);
    delay(1000);
    noTone(buzzPin);
  }
  else
  {
    digitalWrite(ledPin,LOW);
    digitalWrite(buzzPin,LOW);
  }
  Serial.print(i);
  Serial.print(",");
  Serial.print(dist);
  Serial.print(";");
  }
  
  
}
// Function for calculating the distance measured by the Ultrasonic sensor(in cm)
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  period = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  dist = period*0.034/2;
  return dist;
}
