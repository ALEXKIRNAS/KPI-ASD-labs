#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cmath>

const double calcPerSec = 1e5; // Count of elementary operation per second perform by computer
const double left = 0; // Left edge of integration
const double right = exp(1); // Right edge of integrarion

void introduction(void);
void menu(void);
double integration(double(*) (double), double, double);
void checkOfResult(double, double(*) (double), double, double);

int main(void)
{
	while (true)
	{
		system("cls");

		introduction();
		menu();

		double(*function) (double) = nullptr; // Corrent function
		double(*infunction) (double) = nullptr; // Corrent function after integration

		char ch = _getch();
		bool f = 0; // Flag of correct input
		switch(ch)
		{
		case '1': function = sinh; infunction = cosh; break;
		case '2': function = cos; infunction = sin; break;
		case 'q':
		case 'Q' : return 0;
		default: f = 1;
		}

		if (f)
		{
			printf("Input error!\n");
			system("pause");
			continue;
		}

		double result = integration(function, left, right);
		checkOfResult(result, infunction, left, right);
		system("pause");
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

// Analizing of real results with expected
void checkOfResult(double result, double(*function) (double), double left, double right)
{
	printf("My integration calculation give: %.10Lf\n", result);
	printf("Expected result: %.10Lf\n", function(right) - function(left));
	printf("Delta: %.10Lf\n", abs(function(right) - function(left) - result));
}