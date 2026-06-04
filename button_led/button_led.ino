#include "config.h"

// LED state
bool ledState = false;

// Button tracking
int buttonState = HIGH;
int lastButtonReading = HIGH;

// Debounce timing
unsigned long lastDebounceTime = 0;

void setup()
{
  pinMode(LED_PIN, OUTPUT);

  // Button connected to GND
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(LED_PIN, LOW);

  Serial.begin(9600);

  Serial.println("Day 2 - Button LED Toggle Started");
}

void loop()
{
  int reading = digitalRead(BUTTON_PIN);

  // Detect state change
  if (reading != lastButtonReading)
  {
    lastDebounceTime = millis();
  }

  // Debounce check
  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY)
  {
    if (reading != buttonState)
    {
      buttonState = reading;

      // Button pressed (LOW because INPUT_PULLUP)
      if (buttonState == LOW)
      {
        ledState = !ledState;

        digitalWrite(LED_PIN, ledState);

        Serial.print("Button Pressed -> LED ");

        if (ledState)
        {
          Serial.println("ON");
        }
        else
        {
          Serial.println("OFF");
        }
      }
    }
  }

  lastButtonReading = reading;
}
