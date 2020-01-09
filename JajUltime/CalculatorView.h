// CalculatorView.h

#ifndef _CALCULATORVIEW_h
#define _CALCULATORVIEW_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "View.h"

class CalculatorView : public View
{
	using CalcNumber = double;
	
	enum Operation
	{
		Unset,
		Plus   = 'A',
		Minus  = 'B',
		Times  = 'C',
		Divide = 'D'
	};
	
public:
	void render() override;
private:
	CalcNumber input = 0;
	CalcNumber secondInput = 0;
	Operation operation = Unset;
	int decimalPlaces = 0;
	bool updateInput(bool* operationChanged);
	bool changeOperation(const Operation op, bool* operationChanged);
	void calculate(Operation op);
	void showFinalResult();
	void eraseAll(bool* operationChanged = nullptr);
	void resetUserInput();
	CalcNumber* getCurrentInput();
	static char operationChar(Operation operation);
	static String numToString(CalcNumber number, int decimals, int scientificLimit);
};

#endif

