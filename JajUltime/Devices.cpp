#include "Devices.h"


const byte kRows = 4;
const byte kCols = 4;
char kKeys[kRows][kCols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte kRowPins[kRows] = { 9, 8, 7, 6 };
byte kColPins[kCols] = { 5, 4, 3, 2 };

byte cdNumDigits = 4;
byte cdDigitPins[] = { 43, 42, 41, 40 };
byte cdSegmentPins[] = { A8, A9, A10, A11, A12, A13, A14, A15 };

namespace Devices {
	LiquidCrystal lcd(26, 25, 24, 23, 22, 27);
	Button eraseButton(19);
	Keypad keypad(makeKeymap(kKeys), kRowPins, kColPins, kRows, kCols);
	SevSeg clockDisplay;
	Button toggleClockButton(A7);
	Button toggleLedButton(49);
	PassiveBuzzer buzzer(12);
	SimpleLed lightLed(14);
	DS3231 realTimeClock; // The clock is already configured with the correct time.

	void setup() {
		realTimeClock.begin(); // The clock is already configured with the right time.
		clockDisplay.begin(COMMON_CATHODE, cdNumDigits, cdDigitPins, cdSegmentPins, true);
		clockDisplay.setBrightness(100);
		lcd.begin(16, 2);
		// lightLed.turnOn();
	}

	void update()
	{
		eraseButton.update();
		toggleClockButton.update();
		toggleLedButton.update();
		
		clockDisplay.refreshDisplay();
	}
}
