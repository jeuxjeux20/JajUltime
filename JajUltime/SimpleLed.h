// SimpleLed.h

#ifndef _SIMPLELED_h
#define _SIMPLELED_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class SimpleLed
{
public:
	explicit SimpleLed(int pin);
	void turnOn() const;
	void turnOff() const;
	void toggle() const;
	void turn(bool status) const;
	bool isOn() const;
private:
	const int pin;
};


#endif

