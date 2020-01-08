// Devices.h

#ifndef _DEVICES_h
#define _DEVICES_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <Keypad.h>
#include <LiquidCrystal.h>
#include "Button.h"
#include "PassiveBuzzer.h"
#include <SevSeg.h>
#include "SimpleLed.h"
#include <DS3231.h>
namespace Devices {
	extern LiquidCrystal lcd;
	extern Button eraseButton;
	extern Button toggleClockButton;
	extern Keypad keypad;
	extern Button toggleLedButton;
	extern SevSeg clockDisplay;
	extern PassiveBuzzer buzzer;
	extern SimpleLed lightLed;
	extern DS3231 realTimeClock;
	
	extern void setup();
	extern void update();
}
#endif
