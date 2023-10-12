 // This program adds two large integers, and prints the result to the screen

#include <cctype>
#include <iostream>
using namespace std;

// Max number of digits in the large integer
const int MAXSIZE = 25;

// Initializes an integer array so that all positions are holding the value zero.
void initArray(int array[]);

// Gets a large integer from the keyboard and stores each individual digit
// into the array.
void getNum(int array[]);

// Prints a large integer to the screen. Leading zeros are not printed.
void printNum(int array[]);


int main()
{
	// TODO: Write code for the main function

	cout << endl;
	return 0;
}


void initArray(int array[])
{
	// TODO: Write code for the function
}


void printNum(int array[])
{
	// TODO: Write code for the function
}


void getNum(int array[])
{
	char input[MAXSIZE + 1];
	int length;
	bool inputOkay;

	do
	{
		inputOkay = true;

		cout << "Enter an integer: ";
		cin.getline(input, MAXSIZE + 1);

		// If user entered more than the max number of digits
		// then make them enter the large integer again
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Integer too long\n";
			cout << "Enter an integer: ";
			cin.getline(input, MAXSIZE + 1);
		}

		// Check to ensure that the user did not enter any non-digit values
		length = strlen(input);
		for (int x = 0; x < length && inputOkay; x++)
		{
			if (!isdigit(input[x]))
			{
				inputOkay = false;
				cout << "Invalid input\n";
			}
		}

	} while (!inputOkay);


	// TODO: Write code for the remaining portion of the function

}