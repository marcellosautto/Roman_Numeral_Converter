#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include "Windows.h"
#include <vector>
using namespace std;

class roman
{
	public:
		char ch; //contains each char the user enters to form the roman numeral
		int result = 0; //contains decimal form of roman numeral number
		string romanNumeralString; //contains complete roman numeral
		vector<char> romanNumerals; //vector which contains roman numeral components
		vector<int> romanDecimals; //vector which contains the roman numeral components in decimal form

		void userInput(),
			convertToDecimal(),
			addSubtract();

		bool mainLoop(),
			output();

	

};

