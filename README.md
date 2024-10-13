Heres minimal code example to use this timer:

```cpp
#include <MillisTimer.h>
#define LED_PIN 2

// Create a timer with interval in milliseconds
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
```

## Function documentation
`Set` Change inverval of the timer<br />
`Reset` Resets the timer<br />
`Expire` Expire the timer before the timer has elapsed<br />
`Expired` Check it the timer has elapsed and optionally reset the timer<br />
