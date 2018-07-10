//  counts revolutions of the motor
const int left_feedback_pin = 2;
const int right_feedback_pin = 3;

const int FORWARD_L = 8;
const int FORWARD_R = 12;
const int ENABLE_L = 9;
const int ENABLE_R = 10;

volatile unsigned int left_count = 0;
volatile unsigned int right_count = 0;
unsigned long timer = millis();
void left_pulse_interrupt()
{  
  left_count++;
  Serial.print("\nleft_count (count) ");Serial.print(left_count);
}
void right_pulse_interrupt()
{  
  right_count++;
  Serial.print("\nright_count (count) ");Serial.print(right_count);
}

void setup() {
  Serial.begin(115200);

//  Enable both tracks
  digitalWrite(ENABLE_L, HIGH);
  digitalWrite(ENABLE_R, HIGH);
  
  digitalWrite(FORWARD_L, HIGH);
  digitalWrite(FORWARD_R, HIGH);
  
  pinMode(left_feedback_pin, INPUT_PULLUP);
  pinMode(right_feedback_pin, INPUT_PULLUP);
  
//  counts revolutions of the motor
  attachInterrupt(digitalPinToInterrupt(left_feedback_pin), left_pulse_interrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(right_feedback_pin), right_pulse_interrupt, RISING);

}





void loop() {
  
  delay(200);
  Serial.print("\nleft_count (loop) ");Serial.print(left_count); 
  Serial.print("\nright_count (loop) ");Serial.print(right_count);
  Serial.print("\ntimer (loop) "); Serial.print(timer);

  while (right_count > left_count) {
    Serial.print("\nleft_count (while1) ");Serial.print(left_count);
    Serial.print("\nright_count (while1) ");Serial.print(right_count);
    digitalWrite(FORWARD_L, HIGH);
    digitalWrite(FORWARD_R, LOW);
    delay(2000);
    digitalWrite(FORWARD_R, HIGH);
  }
  
  while (left_count > right_count) {
    Serial.print("\nleft_count (while2) ");Serial.print(left_count);
    Serial.print("\nright_count (while2) ");Serial.print(right_count);
    digitalWrite(FORWARD_L, LOW);
    digitalWrite(FORWARD_R, HIGH);
    delay(2000);
    digitalWrite(FORWARD_L, HIGH);
  }
}
