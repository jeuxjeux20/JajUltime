// ButtonDevice.h

#ifndef _BUTTONDEVICE_h
#define _BUTTONDEVICE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Button {
public:
	explicit Button(int pin);
	bool isPushed() const;
	bool isClicked(bool onRelease = true) const;
	void update();
private:
	const int pin;
	bool currentPushed = false;
	bool lastPushed = false;
};
#endif

