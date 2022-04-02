#pragma once
#include "userStack.h"

class menu
{
public:
	explicit menu() = default;
	// Main menu
	bool OpenMenu();
	~menu();
private:

	// Filling arrays with data
	void Initialization();
	// Data processing according to the individual option
	void InvertingStack();
	// Displaying arrays on the screen
	void OutputOfAllStack();
	// Symbol display method: 0 - main menu, 1 - initialization, 2 - changing arrays according to individual option, 3 - initialization of an array with float data type, 4 - initialization of an array with char data type, 5 - program termination
	void RendererMenu(uint16_t);
	// Entering and changing a float stack
	void InitializationFloat();
	// Entering and changing a char stack
	void InitializationChar();
	// Checking for the input of a real number
	void CheckingCorrectInputFloat(std::string&);

	Stack<float> floatArray;
	Stack<char, List> charList;
};