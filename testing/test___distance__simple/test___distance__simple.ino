//  counts revolutions of the motor
const int left_feedback_pin = 2;
const int right_feedback_pin = 3;

const int FORWARD_L = 8;
const int FORWARD_R = 12;
const int ENABLE_L = 9;
const int ENABLE_R = 10;
void left_pulse_interrupt()
{  
  Serial.println("Left Pin Pulse!");
}
void right_pulse_interrupt()
{  
  Serial.println("Right Pin Pulse!");
}
void setup() {
  Serial.begin(115200);
  
  pinMode(left_feedback_pin, INPUT_PULLUP);
  pinMode(right_feedback_pin, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(right_feedback_pin), right_pulse_interrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(left_feedback_pin), left_pulse_interrupt, RISING);

  digitalWrite(FORWARD_L, HIGH);
  digitalWrite(FORWARD_R, HIGH);
  digitalWrite(ENABLE_L, HIGH);
  digitalWrite(ENABLE_R, HIGH);
  delay(10000); 
  digitalWrite(FORWARD_L, LOW);
  digitalWrite(FORWARD_R, LOW);
  digitalWrite(ENABLE_L, LOW);
  digitalWrite(ENABLE_R, LOW);
}
// the loop function runs over and over again forever
void loop() {
}
