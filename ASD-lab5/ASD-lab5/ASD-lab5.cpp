#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

const double calcPerSec = 1e7; // Count of elementary operation per second perform by computer

void introduction(void);
void menu(void);
double integration(double(*) (double), double, double);

int main(void)
{
	while (true)
	{
		introduction();
		menu();

		char ch = _getch();
		switch(ch)
		{
		case '1' : 
		case '2' :
		case 'q' :
		case 'Q' : return 0;
		}
	}
}


// Printing head of program (name, number)
void introduction(void)
{
	printf("Algorithms and Data Structures\n");
	printf("Labwork #5\n");
	printf("Author: Sasha Zarichkovyi\n");
	printf("Variant: %d\n\n", 5106%21 + 1);
}

// Printing main menu
void menu(void)
{
	printf("Make your choise.\n");
	printf("Menu:\n1 : Integrate sh(x)\n2 : Integrate cos(x)\nQ : Exit\n");
}

/************************
Integration of <function>
for <left> to <right>
*************************/
double integration(double(*function) (double), double left, double right)
{
	double long step = (right - left) / calcPerSec; // Chosing a step of integration

	double integrationResult = 0.0;

	while (left < right)
	{
		// Calculation of square figure using by Trapezoidal rule
		integrationResult += (function(left) + function(left + step)) / 2 * step;
		left += step;
	}

	return integrationResult;
}