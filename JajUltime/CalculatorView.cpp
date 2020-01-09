// 
// 
// 

#include "CalculatorView.h"
#include "Devices.h"
#include <math.h>

using namespace Devices;

String CalculatorView::numToString(const CalcNumber number, const int decimals = 2, const int scientificLimit = 8)
{
	const int numberCount = int(log10(abs(number)));
	const bool isLimited = numberCount > scientificLimit;
	if (!isLimited)
	{
		return String(number, decimals);
	}
	const auto scientificNumber = CalcNumber(number / pow(10, numberCount - 1));
	return String(scientificNumber, 4) + 'E' + numberCount;
}

void CalculatorView::render()
{
	bool operationChanged;
	if (updateInput(&operationChanged)) {
		if (operationChanged)
		{
			lcd.clear();
		}
		const CalcNumber currentInput = *getCurrentInput();
		const auto currentInputStr = numToString(currentInput, max(decimalPlaces, 2));
		if (operation != Unset)
		{
			lcd.setCursor(0, 0);
			lcd.print(numToString(input));
			lcd.setCursor(13, 0);
			lcd.print(' ');
			lcd.print(operationChar(operation));
			lcd.print(' ');
		}
		lcd.setCursor(15 - currentInputStr.length(), 1);
		lcd.print(currentInputStr);
	}

	if (operation == Unset) {
		lcd.setCursor(0, 0);
		lcd.print("Calculette");
	}
}

char CalculatorView::operationChar(const Operation operation)
{
	switch (operation)
	{
	case Plus:
		return '+';
	case Minus:
		return '-';
	case Times:
		return '*';
	case Divide:
		return '/';
	default: return '?';
	}
}

bool CalculatorView::updateInput(bool* operationChanged)
{
	const char keypadInput = keypad.getKey();
	if (keypadInput) {
		{
			const int inputNumber = keypadInput - '0';
			if (inputNumber >= 0 && inputNumber <= 9) {
				CalcNumber* currentInput = getCurrentInput();
				if (decimalPlaces == 0) {
					*currentInput *= 10;
					*currentInput += inputNumber;
				}
				else
				{
					*currentInput += inputNumber / pow(10, decimalPlaces);
					decimalPlaces++;
				}
				return true;
			}
		}
		switch (keypadInput)
		{
		case Plus:
			return changeOperation(Plus, operationChanged);
		case Minus:
			return changeOperation(Minus, operationChanged);
		case Times:
			return changeOperation(Times, operationChanged);
		case Divide:
			return changeOperation(Divide, operationChanged);
		case '#':
			showFinalResult();
			return true;
		case '*':
			if (decimalPlaces == 0) {
				this->decimalPlaces = 1;
				return true;
			}
			break;
		default: break;
		}
	}
	if (eraseButton.isClicked())
	{
		eraseAll(operationChanged);
		return true;
	}
	return false;
}

bool CalculatorView::changeOperation(const Operation op, bool* operationChanged)
{
	if (this->operation != Unset)
	{
		// There if we have:
		// 250        +
		//           20
		// And then the user presses an operation, for example *
		// The result will be:
		// 270        *
		//            0
		calculate(this->operation);
	}
	else
	{
		resetUserInput();
	}
	this->operation = op;
	*operationChanged = true;
	return true;
}

void CalculatorView::calculate(Operation op)
{
	switch (op)
	{
	case Plus:
		input += secondInput;
		break;
	case Minus:
		input -= secondInput;
		break;
	case Times:
		input *= secondInput;
		break;
	case Divide:
		input /= secondInput;
		break;
	}
	resetUserInput();
}

void CalculatorView::showFinalResult()
{
	calculate(operation);
	operation = Unset;
}

void CalculatorView::eraseAll(bool* operationChanged)
{
	CalcNumber* currentInput = getCurrentInput();
	if (*currentInput == 0)
	{
		operation = Unset;
		input = 0;
		if (operationChanged != nullptr)
			*operationChanged = true;
	}
	else
	{
		*currentInput = 0;
	}
	resetUserInput();
}

void CalculatorView::resetUserInput()
{
	decimalPlaces = 0;
	secondInput = 0;
}

auto CalculatorView::getCurrentInput() -> CalcNumber*
{
	return operation == Unset ? &input : &secondInput;
}
