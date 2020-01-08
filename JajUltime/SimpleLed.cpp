// 
// 
// 

#include "SimpleLed.h"

SimpleLed::SimpleLed(int pin) : pin(pin)
{
	pinMode(14, OUTPUT);
}

void SimpleLed::turnOn() const
{
	turn(true);
}

void SimpleLed::turnOff() const
{
	turn(false);
}

void SimpleLed::toggle() const
{
	turn(!isOn());
}

void SimpleLed::turn(const bool status) const
{
	digitalWrite(this->pin, status);
}

bool SimpleLed::isOn() const
{
	return digitalRead(this->pin);
}
