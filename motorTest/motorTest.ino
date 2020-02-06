//motorpins
const int enablePin = 4;
const int motor1Pin = 6;
const int motor2Pin = 5;
//const int motor3Pin = 10;
//const int motor4Pin = 11;
//const int enablePin2 = 12;

void setup() {
Serial.begin(9600);

pinMode(motor1Pin, OUTPUT);
pinMode(motor2Pin, OUTPUT);
pinMode(enablePin, OUTPUT);
//pinMode(motor3Pin, OUTPUT);
//pinMode(motor4Pin, OUTPUT);
//pinMode(enablePin2, OUTPUT);
}

void loop() {

leftForward();
//rightForward();
delay(1000);

//turn(); //check the turn function to see delay length

//leftForward();
//rightForward();
delay(1000);

leftStop();
//rightStop();
delay(1000);
}

void leftForward() {
digitalWrite(enablePin, HIGH);
digitalWrite(motor1Pin, LOW); //if you reverse this High and Low the motor will spin the other way
digitalWrite(motor2Pin, HIGH);
}

void leftStop() {
digitalWrite(enablePin, LOW);
}

//void rightForward() {
//digitalWrite(enablePin2, HIGH);
//digitalWrite(motor3Pin, LOW);
//digitalWrite(motor4Pin, HIGH);
//}
//
//void rightStop() {
//digitalWrite(enablePin2, LOW);
//}
//
//void turn() {
////Serial.println(“turn!”);
//digitalWrite(enablePin, HIGH);
//digitalWrite(enablePin2, LOW); //may want to get rid of that
//digitalWrite(motor1Pin, HIGH);
//digitalWrite(motor2Pin, LOW);
//delay(2000);
//}
