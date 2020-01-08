// View.h

#ifndef _VIEW_h
#define _VIEW_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class View
{
public:
	virtual ~View() = default;
public:
	virtual void render() = 0;
};
#endif

