//setup left side 
const int FORWARD_L = 8;
const int BACKWARD_L = 7;
//setup right side
const int FORWARD_R = 12;
const int BACKWARD_R = 11;
//enable both sides
const int ENABLE_L = 9;
const int ENABLE_R = 10;

//const int turnTime = 880;
int turnTime = 890;
//int turnTime = 820;
//const int turnTime = 950;

const int delayBetween = 500;

//Makes all the things LOW
void stopRover() {
  digitalWrite(FORWARD_L, LOW);
  digitalWrite(FORWARD_R, LOW);
  digitalWrite(BACKWARD_L, LOW);
  digitalWrite(BACKWARD_R, LOW);
  digitalWrite(ENABLE_L, LOW);
  digitalWrite(ENABLE_R, LOW);
}

// 1 = clockwise, 0 = anti clockwise
void turnRover(int turnDirection) {
  stopRover();
  digitalWrite(ENABLE_L, HIGH);
  digitalWrite(ENABLE_R, HIGH);
  
  if (turnDirection == 1) {
    digitalWrite(FORWARD_R, HIGH);
    digitalWrite(BACKWARD_L, HIGH);
  } else if (turnDirection == 0) {
    digitalWrite(FORWARD_L, HIGH);
    digitalWrite(BACKWARD_R, HIGH);
  }
  
  delay(turnTime);
  stopRover();
}

// moveDirection:
// 1 = forward, 0 = backwards.
void moveRover(int moveTime, int moveDirection) {
  stopRover();
  digitalWrite(ENABLE_L, HIGH);
  digitalWrite(ENABLE_R, HIGH);
  if (moveDirection == 1) {
    digitalWrite(FORWARD_L, HIGH);
    digitalWrite(FORWARD_R, HIGH);
  } else if (moveDirection == 0) {
    digitalWrite(BACKWARD_L, HIGH);
    digitalWrite(BACKWARD_R, HIGH);
  }
  delay(moveTime);
  stopRover();
}



// the setup function runs once when you press reset or power the board
void setup() {
//  while (true) {
//    turnRover(1);
//    delay(2000);
//  }
  moveRover(1900, 1);
  delay(delayBetween);
  turnRover(1);
  delay(delayBetween);
  stopRover();
  moveRover(2100, 1);
  delay(delayBetween);
  turnRover(1);
  delay(delayBetween);
  stopRover();
  moveRover(2100, 1);
  delay(delayBetween);
  turnRover(1);
  delay(delayBetween);
  stopRover();
  moveRover(2250, 1);
  delay(delayBetween);
//  turnRover(0);
  stopRover();
}




// the loop function runs over and over again forever
void loop() {
}
