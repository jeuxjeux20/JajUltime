// #include <DS3231.h>
#include "PassiveBuzzer.h"
#include "Devices.h"
#include "CalculatorView.h"
#include "View.h"
#include "Button.h"

View* currentView;
const int noteCount = 7;
const int duration = 200;
Note notes[noteCount] = {
	NOTE(E5, duration - 25, 25),
	NOTE(E5, duration - 25, 25),
	NOTE(E5, duration, 75),
	NOTE(C5, duration, 75),
	NOTE(E5, duration, 150),
	NOTE(G5, duration, 250),
	NOTE(G3, 250, 0)
};
void setup() {
	Devices::setup();
  Devices::buzzer.playMelody(notes, noteCount);
	Serial.begin(9600);
	currentView = new CalculatorView();
}
bool enableClockDisplay = true;
void loop() {
	using namespace Devices;

	currentView->render();
	
	const auto date = realTimeClock.getDateTime();
	const auto timeStr = realTimeClock.dateFormat("Hi", date); // H = Hour (00-24), i = Minutes (00-60)
	clockDisplay.setChars(timeStr);

	if (toggleClockButton.isClicked())
	{
		enableClockDisplay = !enableClockDisplay;
	}
	if (!enableClockDisplay) clockDisplay.blank();
	
	update();

	if (toggleLedButton.isClicked())
	{
		lightLed.toggle();
	}
}
