#include <MillisTimer.h>

#define LED_PIN 2

// Create a timer and with interval in milliseconds
// Second parameter specifies if the timer is expired when created or should epire after the interval is elapsed
MillisTimer timerLed(1000, true); 

void setup() {
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  // Check if timer expired
  timerLed.Expired() {
    // Reverse the led digital output state
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    // Resets the timer
    timerLed.Reset();
  }
}
