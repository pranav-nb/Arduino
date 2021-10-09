# ArduinoBased_SocialDistancingAlerter
A basic device to alert violators of social distancing using Arduino Uno, ultrasonic sensor and a buzzer.
</n>
Assuming the speed of sound in air is 340m/s, distance is calculated by using the time delay of the signal travelling between the transmitter and reciever of the ultrasonic signal. The distance is kept as 182cm. Anything that comes below 182cm will 'ON' the buzzer. 

### Drawbacks: 
The fundamental drawback of this setup is that it cannot differentiate between humans and other objects. So it needs to be kept in mind especially while using this indoors.
