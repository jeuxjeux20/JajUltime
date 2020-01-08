// 
// 
// 

#include "PassiveBuzzer.h"

PassiveBuzzer::PassiveBuzzer(const int pin) : pin(pin)
{
}

void PassiveBuzzer::playMelody(Note notes[], const int count) const
{
	for (int i = 0; i < count; i++)
	{;
	Serial.write("playing now! \n");
		Note& note = notes[i];
		tone(this->pin, note.frequency, note.duration);
		delay(note.duration + note.delay);
	}
}
