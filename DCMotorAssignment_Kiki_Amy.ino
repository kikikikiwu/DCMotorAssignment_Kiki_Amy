const int trigPin = 2;
const int echoPin = 3;
const int enablePin = 4;
const int motorPin = 5;
const int motor2Pin = 6;
int minDis = 20; //min distance to stop the spinning
int amp = 1; //amplifier for the general speed change

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  long duration, distance;
  //switching it on and off to receive signals
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  duration = pulseIn(echoPin, HIGH);
  distance = msTocm(duration);
  
  // threshold
  /*if (distance < 50) {
    int speed = (distance - minDis) * amp;
    //spin!
    digitalWrite(enablePin, HIGH);
    analogWrite(motorPin, speed);
    analogWrite(motor2Pin, LOW);
    }*/

   //testing DC Motor
   digitalWrite(enablePin, HIGH);
   analogWrite(motorPin, 60);
   analogWrite(motor2Pin, 0);
  
}

long msTocm (long ms_) {
  return ms_ / 29 / 2;  
}
