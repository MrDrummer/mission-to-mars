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
//const int turnTime = 890;
int turnTime = 820;
//const int turnTime = 950;

const int delayBetween = 500;

const int RHIGH = 255;
const int RLOW = 0;


//Makes all the things RLOW
void stopRover() {
  analogWrite(FORWARD_L, RLOW);
  analogWrite(FORWARD_R, RLOW);
  analogWrite(BACKWARD_L, RLOW);
  analogWrite(BACKWARD_R, RLOW);
  analogWrite(ENABLE_L, RLOW);
  analogWrite(ENABLE_R, RLOW);
}

// 1 = clockwise, 0 = anti clockwise
void turnRover(int turnDirection, int turnTimeF = turnTime) {
//  if (turnTimeF != "") {
//    turnTime = turnTimeF;
//  }
  stopRover();
  analogWrite(ENABLE_L, RHIGH);
  analogWrite(ENABLE_R, RHIGH);
  
  if (turnDirection == 1) {
    analogWrite(FORWARD_R, RHIGH);
    analogWrite(BACKWARD_L, RHIGH);
  } else if (turnDirection == 0) {
    analogWrite(FORWARD_L, RHIGH);
    analogWrite(BACKWARD_R, RHIGH);
  }
  
  delay(turnTime);
  stopRover();
}

// moveDirection:
// 1 = forward, 0 = backwards.
void moveRover(int moveTime, int moveDirection) {
  stopRover();
  analogWrite(ENABLE_L, RHIGH);
  analogWrite(ENABLE_R, RHIGH);
  if (moveDirection == 1) {
    analogWrite(FORWARD_L, RHIGH);
    analogWrite(FORWARD_R, RHIGH);
  } else if (moveDirection == 0) {
    analogWrite(BACKWARD_L, RHIGH);
    analogWrite(BACKWARD_R, RHIGH);
  }
  delay(moveTime);
  stopRover();
}



// the setup function runs once when you press reset or power the board
void setup() {
  moveRover(2000, 1);
  delay(delayBetween);
  turnRover(0);
  delay(delayBetween);
  stopRover();
  moveRover(2100, 1);
  delay(delayBetween);
  turnRover(0);
  delay(delayBetween);
  stopRover();
  moveRover(2200, 1);
  delay(delayBetween);
  turnRover(0);
  delay(delayBetween);
  stopRover();
  moveRover(2050, 1);
  delay(delayBetween);
//  turnRover(0);
  stopRover();
}




// the loop function runs over and over again forever
void loop() {
}
