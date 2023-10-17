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

// Contains the math that adds 2 arrays.
void solveNum(int array1[], int array2[], int arraysum[]);


int main()
{
	// TODO: Write code for the main function
	int num1[MAXSIZE];
	int num2[MAXSIZE];
	int sum[MAXSIZE];

	

	initArray(num1); //triggers the init array function, changing the array values.

	initArray(num2);

	getNum(num1);

	getNum(num2);

	solveNum(num1, num2, sum);

	cout << endl;

	return 0;

}


void initArray(int array[])
{
	
	for (int i = 0; i < MAXSIZE; i++)
		array[i] = 0; 
}


void printNum(int array[])
{
	bool leadZero = true;

	printf("The large sum is: ");

	for (int i = 0; i < MAXSIZE; i++)
	{
		if (array[i] != 0)
		{
			leadZero = false;
		}
		if(leadZero == false)
		{
			printf("%d", array[i]);
		}
	}
}


void getNum(int array[])
{
	char input[MAXSIZE + 1]; // + 1 for '\0'
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
	
	//ari solved the getnum!!!! remember for credit
	int end = 0;
	int temp[MAXSIZE];

	for (int i = 0; input[i] != '\0'; i++)
	{
		temp[i] = input[i] - '0';
		end = i + 1;
	}

	int start = MAXSIZE - (end);

	for (int i = 0; start < MAXSIZE; start++)
	{
		array[start] = temp[i];
		i++;
	}
}


void solveNum(int array1[],int array2[],int arraysum[])
{
	bool counter = false;
	bool overflow = false;
	
	for (int i = MAXSIZE - 1; i >= 0; i--) 
	{
		if (counter == true)
		{
			arraysum[i] = array1[i] + array2[i] + 1;
			counter = false;
		}
		else
		{
			arraysum[i] = array1[i] + array2[i];
		}

		if (arraysum[i] > 9 && i == 0)
		{
			printf("Overflow error");
			overflow = true;
		}

		if (arraysum[i] > 9)
		{
			arraysum[i] = arraysum[i] % 10;
			counter = true;
		}
	}

	if (overflow == false)
	{
		printNum(arraysum);
	}
}