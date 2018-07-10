const int FORWARD_L = 8;
const int FORWARD_R = 12;
const int ENABLE_L = 9;
const int ENABLE_R = 10;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
//  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(FORWARD_L, HIGH);
  digitalWrite(FORWARD_R, HIGH);
  digitalWrite(ENABLE_L, HIGH);
  digitalWrite(ENABLE_R, HIGH);
  delay(7440); 
  digitalWrite(FORWARD_L, LOW);
  digitalWrite(FORWARD_R, LOW);
  digitalWrite(ENABLE_L, LOW);
  digitalWrite(ENABLE_R, LOW);
}
// the loop function runs over and over again forever
void loop() {
}
