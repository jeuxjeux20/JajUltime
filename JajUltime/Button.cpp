
#include "Button.h"

Button::Button(const int pin) : pin(pin)
{
	pinMode(pin, INPUT_PULLUP);
}

bool Button::isPushed() const
{
	return digitalRead(this->pin) == LOW;
}

bool Button::isClicked(const bool onRelease) const
{
	if (onRelease) return lastPushed && !currentPushed;
	else return !lastPushed && currentPushed;
}

void Button::update()
{
	this->lastPushed = this->currentPushed;
	this->currentPushed = isPushed();
}
