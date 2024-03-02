#include <Servo.h>
Servo servo;
// declare all the pins
int const trigPin = 6;
int const echoPin = 5;

void setup(){
  pinMode(trigPin, OUTPUT); // emits ultrasonic pulse
  pinMode(echoPin, INPUT); // recieves ultrasonic pulse
  servo.attach(3);
}

void loop(){
  int duration, distance;
  digitalWrite(trigPin,HIGH);
  delay(1);

  digitalWrite(trigPin, LOW); // measure the pulse input in echo pin
  
  duration = pulseIn(echoPin, HIGH); // distance is half the duration divided by 29.1

  distance = (duration/2) / 29.1; // if distance < 0.5m && distance > 0
  if (distance <= 10 && distance >= 0){
    servo.write(50);
    delay(3000);

  }

  servo.write(160);
}