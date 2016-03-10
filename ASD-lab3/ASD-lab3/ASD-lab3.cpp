#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
#include "table.h"

using std::cout;

const int Nmax = 65536; // Максимальна кількість записів
Engine* table[Nmax + 1]; // Таблиця двигунів
int count = 0; // Поточна кількість двигунів

void textOutput(void); // Виведення меню

int main(void)
{
	srand(time(NULL));
	setlocale(LC_CTYPE, "RUSSIAN");
	bool isSorted = 0; // Признак відсорованості

	while (true)
	{
		textOutput();
		char ch = _getch();

		system("cls");
		switch (ch)
		{
		case '1': addNewEngine(table, count); isSorted = 0; break;
		case '2': addNewEngineByGen(table, count, Nmax); isSorted = 0; break;
		case '3': deleteEngine(table, count); break;
		case '4': showEngineTable(table, count); break;
		case '5': sortByPower(table, count); isSorted = 1; break;
		case '6': sortByName(table, count); isSorted = 0; break;
		case '7': updateEngine(table, count); break;
		case '8': searchDirect(table, count); break;
		case '9': searchLine(table, count); break;
		case '0': searchBinary(table, count, isSorted); break;
		case 'q': return 0; break;
		case 'Q': return 0; break;
		default: printf("Помилка введеня!\n");
		}

		printf("\n");
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
		<< "АСД Лабораторна робота №3\n"
		<< "Модульне програмування та\n"
		<< "його використання для побудови\n"
		<< "програм обробки таблиць\n"
		<< "Варiант: " << 5106 % 20 + 1 << "\n";
	printf("************************************\n\n");

	printf("Оберiть дiю:\n");
	printf("1: Додати новий елемент до таблицi\n");
	printf("2: Згенерувати елементи до таблицi\n");
	printf("3: Видалити елемент з таблицi\n");
	printf("4: Показати таблицю\n");
	printf("5: Вiдсортувати таблицю за потужнicтю\n");
	printf("6: Вiдсортувати таблицю за iменами\n");
	printf("7: Обновити елемент таблицi\n");
	printf("8: Вибiрка за прямою адресою\n");
	printf("9: Вибiрка лiнiйним пошуком\n");
	printf("0: Вибiрка бiнарним пошуком\n");
	printf("Q: Вихiд.\n");
}