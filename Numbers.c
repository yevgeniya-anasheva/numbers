/*
Program Name: Numbers.c
Purpose: determines what type of number, a number is.
Version: 1.0.0
*/

#include <stdio.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0
bool isNegative = false;

/*
	Function name: rprint()
	Purpose: recursive function that gets the number acquired from getchar() and then outputs it using putchar()
	Accepts: long, representing the number
	Returns: nothing
*/
void rprint(long num)
{
	if (num != 0)
	{
		long temp = num % 10;
		num = (num - temp) / 10;
		rprint(num);
		putchar(temp + '0');
	}
}
/*
	Function name: print()
	Purpose: gets the number acquired from getchar(), checks if number is 0 or negative and then calls rprint() to convert the number
	Accepts: long, representing the number
	Returns: nothing
*/
void print(long num)
{
	if (num == 0)
		putchar('0');
	else if (isNegative) 
	{
		putchar('-');
	}
	rprint(num);
}

int main() 
{
	//declare variables
	int ch;
	long number = 0;
	bool isComposite = false;
	bool isTriangular = false;
	bool isFactorial = false;

	//get a number from keyboard
	puts("Enter a number and press ENTER: ");
	for (int i = 0; (ch = getchar()) != '\n'; ++i)
	{
		if (i == 0 && ch == '-') //checks for negative numbers
		{
			isNegative = true;
			continue;
		}
		else if (i == 0 && (ch > '9' || ch < '0'))//if the 1st symbol is not a number, quit
		{
			puts("You didn't enter a number. Quitting...");
			return -1;
		}
		else if (ch <= '9' && ch >= '0')//getting a number successfully 
		{
			number *= 10;
			number = number + (ch - '0');
		}
		else if (i != 0 && (ch > '9' || ch < '0'))//stop reading once the character is not a number
			break;
	}
	if (ch == '\n')//need to manually check for newline character if the user only presses enter, without any input
	{
		puts("You didn't enter a number. Quitting...");
		return -1;
	}
	puts("You entered...");
	print(number);
	putchar('\n');

	//processing

	//Natural or not natural condition
	if (!isNegative) { puts("The number is natural"); }
	else { puts("The number is an integer"); }

	//Odd or even
	if (number % 2 == 0) { puts("The number is even"); }
	else { puts("The number is odd"); }

	//Prime or composite number
	for (unsigned i = 2; i < number; ++i)//loop condition makes sure that the number is not divided by itself
	{
		if (number % i == 0)
		{
			isComposite = true;
			break;//here, if a number can be divided by at least one other number, we don't need to be in the loop anymore
		}
	}
	if (isComposite) { puts("The number is composite"); }
	else if (number == 1 || number == 0) { puts("The number is neither prime nor composite"); }
	else { puts("The number is prime"); }

	//triangular number
	int result = 0;
	for (unsigned j = 1; result <= number; ++j)
	{
		result = (j * j + j) / 2;
		if (result == number)
			isTriangular = true;
	}
	if (isTriangular && !isNegative) { puts("The number is triangular"); }
	else { puts("The number is not triangular"); }

	//square number
	double sqroot = sqrt(number);
	int wholeNumber = sqroot;
	if ((sqroot - wholeNumber) == 0 && !isNegative && number != 0) { puts("The number is square"); }
	else { puts("The number is not square"); }

	//a factorial
	int multiply = 1;
	for (int k = 1; multiply <= number; ++k)
	{
		multiply *= k;
		if (multiply == number) isFactorial = true;
	}
	if (isFactorial && !isNegative) { puts("The number is a factorial"); }
	else { puts("The number is not a factorial"); }

	//perfect, deficient or abundant
	if (isNegative)
		puts("The number is deficient");//all negative numbers are deficient
	else
	{
		long sumCounter = 0;//testing for perfect numbers here
		for (unsigned i = 1; i < number; ++i)
		{
			if (number % i == 0)
				sumCounter += i;
		}
		if (sumCounter == number)
			puts("The number is perfect");
		else if (sumCounter < number)
			puts("The number is deficient");
		else
			puts("The number is abundant");
	}
	//a power of two
	double powerOfTwo = number;
	for (int m = number; powerOfTwo > 1; m = m / 2)
		powerOfTwo = powerOfTwo / 2.0;
	if (powerOfTwo == 1 && !isNegative) { puts("The number is a power of two"); }
	else { puts("The number is not a power of two"); }

	return 0;
}