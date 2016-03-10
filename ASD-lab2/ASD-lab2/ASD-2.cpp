#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "table.h"
#pragma warning(disable : 4996)

const int  Nmax = 100; // Максимальна кількість записів
int MAX = 9000;

CTable table[Nmax];
int count = 0;

void textOutput(void); // Виведення меню

int main(void)
{
	srand(time(NULL));

	setlocale(LC_CTYPE, "RUSSIAN");

	while (true)
	{
		textOutput();
		char ch = getch();

		system("cls");

		switch (ch)
		{
		case '1': add(table, count); break;
		case '2': add_gen(table, count, Nmax); break;
		case '3': erasse(table, count); break;
		case '4': printf(table, count); break;
		case '5': sort(table, count); break;
		case '6': sum_func(table, count, MAX); break;
		case '0': return 0; break;
		default: printf("Помилка введеня!\n");
		}

		system("pause");
	}
}

void textOutput(void)
{
	system("cls");
	printf("************************************\n");
	std::cout << "Роботу виконав:\n"
		<< "Зарiчковий Олександр\n"
		<< "Група IП-51\n"
		<< "АСД Лабораторна робота №2\n"
		<< "Визначення алгоритмiв обробки задач\n"
		<< "за структурами i агрегатами типiв\n"
		<< "вхiдних та вихiдних даних\n"
		<< "Варiант: " << 5106 % 24 + 1 << "\n";
	printf("************************************\n\n");

	printf("Оберiть дiю:\n");
	printf("1: Додати новий елемент до таблицi\n");
	printf("2: Згенерувати елементи до таблицi\n");
	printf("3: Видалити елемент з таблицi\n");
	printf("4: Показати таблицю\n");
	printf("5: Вiдсортувати таблицю\n");
	printf("6: Перевiрка sum < max\n");
	printf("0: Вихiд\n");
}