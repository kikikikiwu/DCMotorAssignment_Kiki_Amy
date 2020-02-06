const int trigPin = 2;
const int echoPin = 3;
const int enablePin = 4;
const int motorPin = 5;
const int motor2Pin = 6;
int minDis = 15; //min distance to stop the spinning
int amp = 10; //amplifier for the general speed change

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(enablePin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);

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
  Serial.print("distance, ");
  Serial.print(distance);
  Serial.println();
  
  // threshold
  if (distance > minDis && distance < 50) {
    int speed = (distance - minDis) * amp;
    //spin!
    digitalWrite(enablePin, HIGH);
    analogWrite(motorPin, speed);
    analogWrite(motor2Pin, LOW);
    }
    else {
      digitalWrite(enablePin, LOW);
      }

   //testing DC Motor
//   digitalWrite(enablePin, HIGH);
//   digitalWrite(motorPin, HIGH);
//   digitalWrite(motor2Pin, LOW);
  
   //analogWrite(motorPin, 80);
   //analogWrite(motor2Pin, 0);
  
}

long msTocm (long ms_) {
  return ms_ / 29 / 2;  
}
