#include <MillisTimer.h>

#define LED_PIN 2

// Create a timer and with interval in milliseconds
MillisTimer timerLed(1000); 

void setup() {
  pinMode(LED_PIN,OUTPUT);
}

void loop() {

  // Check if timer expired and resets the timer
  timerLed.Expired(true) {
    // Reverse the leds digital output state
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
}
