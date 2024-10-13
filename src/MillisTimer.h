#ifndef MillisTimer_h
#define MillisTimer_h

#include <Arduino.h>

class MillisTimer {
	private:
		unsigned long millisInterval;
		unsigned long millisPrevious;
		bool expired;
	public:
		MillisTimer(unsigned long _millisInterval);
		MillisTimer(unsigned long _millisInterval, bool _expired);
		void Set(unsigned long _millisInterval, bool _reset);
		void Reset();
		void Expire();
		bool Expired();
		bool Expired(bool _reset);
};

#endif