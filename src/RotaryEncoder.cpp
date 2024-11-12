#include "RotaryEncoder.h"
#include <Arduino.h>

// Encoder 
RotaryEncoder::RotaryEncoder(uint8_t _clk, uint8_t _dt) {
	CLK = _clk;
    DT = _dt;

    pinMode(CLK, INPUT_PULLDOWN);
    pinMode(DT,  INPUT_PULLDOWN);
}

RotaryEncoder::RotaryEncoder(uint8_t _clk, uint8_t _dt, int _min, int _max, bool _loop) {
	CLK = _clk;
    DT = _dt;

    advconfig = true;

    min = _min;
    max = _max;
    loop = _loop;

    pinMode(CLK, INPUT_PULLDOWN);
    pinMode(DT,  INPUT_PULLDOWN);
}


uint8_t RotaryEncoder::InterruptPin() {
	return DT;
};

void IRAM_ATTR RotaryEncoder::Process() {
    if(advconfig)
    {
        currentStateCLK = digitalRead(CLK);
        if (currentStateCLK != lastStateCLK && currentStateCLK == 1)
        {
            if (digitalRead(DT) != currentStateCLK)
            {
                //ENCODER STEP UP
                if(value >= max)
                {
                    if (loop) value = min;
                }
                else value++;
            }
            else
            {           
                //ENCODER STEP DOWN     
                if(value <= min)
                {
                    if (loop) value = max;
                }
                else value--;
            }
            updated = true;
        }
        lastStateCLK = currentStateCLK;
    }
    else
    {
        currentStateCLK = digitalRead(CLK);
        if (currentStateCLK != lastStateCLK && currentStateCLK == 1)
        {
            if (digitalRead(DT) != currentStateCLK)
            {
            value++;
            }
            else
            {
            value--;
            }
            updated = true;
        }
        lastStateCLK = currentStateCLK;
    }
};

bool RotaryEncoder::Updated() {
    if(updated)
    {
        updated = false;
        return true;
    }
    else return false;
};

int RotaryEncoder::Value() {
	return value;
};