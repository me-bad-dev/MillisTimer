#include "MillisTimer.h"
#include <Arduino.h>

// New timer in milliseconds
MillisTimer::MillisTimer(unsigned long _millisInterval) {
	millisPrevious = millis();
	millisInterval = _millisInterval;
	expired = false;
}

// New timer in milliseconds and sets and optionally sets the timer as expired.
MillisTimer::MillisTimer(unsigned long _millisInterval, bool _expired) {
	millisPrevious = millis();
	millisInterval = _millisInterval;
	expired = _expired;
}

// Sets timer interval in milliseconds and optionally resets the timer.
void MillisTimer::Set(unsigned long _millisInterval, bool _reset) {
	millisInterval = _millisInterval;
	if(_reset) millisPrevious = millis();
}

// Resets the timer
void MillisTimer::Reset() {
	millisPrevious = millis();
	expired = false;
}

// Expire the timer
void MillisTimer::Expire() {
	expired = true;
}

// Check the timer - returns true if expired (doesn't resets the timner).
bool MillisTimer::Expired() {
	if(expired) return true;
	else {
		if (millis() - millisPrevious >= millisInterval) {
			return true;
		}
		else return false;
	}
}

// Check the timer and optionally reset the timer expired timer.
bool MillisTimer::Expired(bool _reset)
{
	if(expired) {	
		if(_reset) expired = false;
			millisPrevious = millis();
		return true;
	}
	else if (millis() - millisPrevious >= millisInterval) {
		if(_reset) {
			millisPrevious = millis();
		}
		return true;
	}
	else return false;
}