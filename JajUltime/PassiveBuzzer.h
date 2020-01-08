// PassiveBuzzer.h

#ifndef _PASSIVEBUZZER_h
#define _PASSIVEBUZZER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Note.h"

class PassiveBuzzer
{
public:
	explicit PassiveBuzzer(int pin);
	void playMelody(Note notes[], int count) const;
private:
	const int pin;
};

#endif

