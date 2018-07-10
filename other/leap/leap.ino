#include <ArduinoUnit.h>

bool is_a_leap_year(int year)
{
  return ((year % 4 == 0 and year % 100 != 0)or year % 400 == 0);
}

test(a_typical_common_year_return_false)
{
  assertFalse(is_a_leap_year(2001));
}

test(a_typical_common_leap_year_return_true)
{
  assertTrue(is_a_leap_year(1996));
}

test(atypical_common_year_return_false)
{
  assertFalse(is_a_leap_year(1900));
}

test(atypical_common_leap_year_return_true)
{
  assertTrue(is_a_leap_year(2000));
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
Test::run();
}
