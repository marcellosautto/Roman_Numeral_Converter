#include "roman.h"


bool roman::mainLoop() //main loop of functions
{ 

	userInput();
	convertToDecimal();
	addSubtract();
	return output(); //returns true or false to romanDriver depending on if they want to enter another roman numeral or not
}

void roman::userInput() //takes in roman numeral input by user
{
	

	cout << endl << "Enter A Roman Numeral: " << endl;
	
	while (ch = _getch())
	{
		if (ch == 13) //if user presses ENTER
		{
			cout << endl;
			break;
		}

		else if (ch == 'M' || ch == 'D' || ch == 'C' || ch == 'L' || ch == 'X' || ch == 'V' || ch == 'I') //only inputs roman numeral characters into vector
		{
			cout << ch;
			romanNumerals.push_back(ch);
		}
	}

}

void roman::convertToDecimal() //interates through vector and converts the roman numeral letters individually into their respective decimal numbers
{
	for (auto iter = romanNumerals.begin(); iter != romanNumerals.end(); iter++)
	{
		if (*iter == 'M')
			romanDecimals.push_back(1000);

		else if (*iter == 'D')
			romanDecimals.push_back(500);

		else if (*iter == 'C')
			romanDecimals.push_back(100);

		else if (*iter == 'L')
			romanDecimals.push_back(50);

		else if (*iter == 'X')
			romanDecimals.push_back(10);

		else if (*iter == 'V')
			romanDecimals.push_back(5);

		else if (*iter == 'I')
			romanDecimals.push_back(1);
	}
	cout << endl;

	for (char x : romanNumerals) //takes the roman numeral from the vector and puts it into a string
		romanNumeralString += x;
}


void roman::addSubtract() //convert the roman numeral into a decimal number
{
	auto iter1 = romanDecimals.begin();
	auto iter2 = romanDecimals.begin() + 1;

	while (iter2 != romanDecimals.end()) //if the second iterator is at the end, break the loop (Without Subtraction)
	{
		if (*iter1 < *iter2) //if the first iterator is less than the second iterator, iterator 1 equals the difference of iterator 2 and iterator 1
		{
			*iter1 = *iter2 - *iter1;
			romanDecimals.erase(iter2); //delete extra index of the vector
		}

		iter1++;
		if (iter1 == romanDecimals.end()) //if the first iterator is at the end, break the loop (With Subtraction)
			break;
		iter2++;
	}

	cout << endl;
	for (int numbers : romanDecimals)
		result += numbers;

}

bool roman::output() //output the conversion
{
	char repeat;
	cout << "The Roman Numeral " << romanNumeralString << " In Decimal Form Is " << result << endl;
	cout << "Would You Like to Enter Another Roman Numeral? (Y/N)" << endl;
	cin >> repeat;

	if (repeat == 'Y' || repeat == 'y')
		return true;
	else if (repeat == 'N' || repeat == 'n')
	{
		cout << "Thank you!";
		return false;
	}
		
}
