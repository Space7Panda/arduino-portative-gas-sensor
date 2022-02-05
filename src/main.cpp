#include <Arduino.h>
#include <arduino-timer.h>

auto timer = timer_create_default();

#define MQ2pinA (0)

#define diodeRed (2)
#define diodeYellow (3)
#define diodeGreen (4)

float sensorValue;

bool disableDiodeYellow(void *)
{
  digitalWrite(diodeRed, LOW);

  return false;
}

void setup()
{
  digitalWrite(diodeYellow, HIGH);

  timer.in(20000, disableDiodeYellow);
}

void loop()
{
  sensorValue = analogRead(MQ2pinA);

  if (sensorValue > 300)
  {
    digitalWrite(diodeRed, HIGH);
  }
  else
  {
    digitalWrite(diodeRed, LOW);
  }

  delay(200);
}
