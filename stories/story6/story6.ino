const int FORWARD_L = 8;
const int FORWARD_R = 12;
const int ENABLE_L = 9;
const int ENABLE_R = 10;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(FORWARD_L, OUTPUT);
    digitalWrite(FORWARD_L, HIGH);
  digitalWrite(FORWARD_R, HIGH);
  digitalWrite(ENABLE_L, HIGH);
  digitalWrite(ENABLE_R, HIGH);
  delay(15000);
  // Pause for 1 sec
  digitalWrite(FORWARD_L, LOW);
  digitalWrite(FORWARD_R, LOW);
  digitalWrite(ENABLE_L,LOW);
  digitalWrite(ENABLE_R, LOW);
  delay(1000);
}

// the loop function runs over and over again forever
void loop() {
  // Go fowards for 1 secs
}
