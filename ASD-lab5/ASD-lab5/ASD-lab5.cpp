#include <stdio.h>

void introduction(void);
void menu(void);

int main(void)
{
	introduction();
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