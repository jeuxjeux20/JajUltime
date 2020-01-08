#ifndef _NOTE_H
#define _NOTE_H

#include <pitches.h>
#define NOTE(of, duration, delay) Note(NOTE_##of, duration, delay)
#define NOTE0(of, duration) Note(NOTE_##of, duration)
struct Note
{
	explicit Note(const int frequency, const int duration, const int delay = 0) : frequency(frequency), duration(duration), delay(delay)
	{
	}
	
	int frequency;
	int duration;
	int delay;
};

#endif