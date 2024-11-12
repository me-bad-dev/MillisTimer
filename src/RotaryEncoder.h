#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include <Arduino.h>

class RotaryEncoder {
	private:
		uint8_t CLK;  //A
		uint8_t DT;   //B

		bool currentStateCLK;
		bool lastStateCLK;

		int value;
		bool updated;

		bool advconfig = false;
		int min;
		int max;
		bool loop;
	public:
		RotaryEncoder(uint8_t _clk, uint8_t _dt);
		RotaryEncoder(uint8_t _clk, uint8_t _dt, int _min, int _max, bool _loop);
		void Process();
		uint8_t InterruptPin();
		bool Updated();
		int Value();
};

#endif