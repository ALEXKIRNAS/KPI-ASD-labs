#include "table.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#pragma warning(disable : 4996)

#define maxLengthOfName 24
#define MAX_POWER 10000
#define MAX_EFFICIENCY 100
#define MAX_FUEL_CONSUME 100
#define Rrand ((rand() % RAND_MAX)/(1.0 * RAND_MAX))

const int Nmax = 50; // Максимальна довжина назви доступної на обробку
const int index = 1000; // Максимальний індекс двигуна при генерації

						// Поміняти місцями два елементи в таблиці
void swap(Engine** table, int i, int z)
{
	Engine* temp = table[i];
	table[i] = table[z];
	table[z] = temp;
}

// Конструктор нового елементу
Engine::Engine(char* name, unsigned long power, double efficiency, double fuelConsume)
{
	this->name = name;
	this->power = power;
	this->efficiency = efficiency;
	this->fuelConsume = fuelConsume;
}

// Виведення таблиці на екран
void showEngineTable(Engine** table, int& count)
{
	if (count == 0)
	{
		printf("No elements in table!");
		return;
	}

	printf("%-3s%-*s%-10s%-15s%-15s\n", "№", maxLengthOfName + 1, "Name", "Power", "Efficiency", "Fuel consumtion");
	for (int i = 0; i<count; i++)
		printf("%-3d%-*s%-10d%-15.2Lf%-15.2Lf\n", i + 1, maxLengthOfName + 1, table[i]->name, table[i]->power, table[i]->efficiency, table[i]->fuelConsume);
}

// Добавлення нового елементу в таблицю (вручну)
void addNewEngine(Engine** table, int& count)
{
	char* name = new char[Nmax]; // Повна назва двигуна
	double efficiency; // ККД двигуна (функціональне поле)
	double fuelConsume; // Споживання пального на 100 км (функціональне поле)
	int power; // Потужність двигуна (в кінських силах)

	printf("Enter name of engine: ");
	std::cin.ignore();
	gets_s(name, Nmax);
	if (strlen(name) > maxLengthOfName)
	{
		printf("Error. Name is to long! Try later.");
		delete[] name;
		name = nullptr;
		return;
	}

	printf("Enter hourse power of engine: ");
	scanf("%d", &power);
	if (power <= 0)
	{
		printf("Error. Power must be positive integer! Try later.");
		delete[] name;
		name = nullptr;
		return;
	}

	printf("Enter engine efficiency: ");
	scanf("%lf", &efficiency);
	if (efficiency < 0.0 || efficiency > 100.0)
	{
		printf("Error. Efficiency of engine must be from 0 to 100 percent! Try later.");
		delete[] name;
		name = nullptr;
		return;
	}

	printf("Enter fuel consume of engine per 100 km: ");
	scanf("%Lf", &fuelConsume);
	if (fuelConsume <= 0.0)
	{
		printf("Error. Fuel consume of engine must be positive number! Try later.");
		delete[] name;
		name = nullptr;
		return;
	}

	table[count++] = new Engine(name, power, efficiency, fuelConsume);
}

// Генерація нових елементів
void addNewEngineByGen(Engine** table, int& count, int Nmax)
{
	const int patterns = 4;
	char* typicalNames[patterns] =
	{
		"Rolls-Royce Merlin ",
		"NASA X-",
		"Rolls_Royce Conway ",
		"Boeing 707-"
	};

	printf("Enter count of numbers to generate: ");
	int number;
	scanf("%d", &number);
	if (count + number > Nmax)
	{
		number = Nmax - count;
		printf("Table is overload! %d new recoed will be generated.", number);
	}

	for (int i = 0; i<number; i++)
	{
		char* name = new char[::Nmax];
		char buf[::Nmax];
		strcpy(name, typicalNames[rand() % patterns]);
		strcat(name, itoa(rand() % index + 1, buf, 10));

		unsigned long power = rand() % MAX_POWER + 1;
		double efficiency = Rrand * MAX_EFFICIENCY;
		double fuelConsume = Rrand * MAX_FUEL_CONSUME;

		table[count++] = new Engine(name, power, efficiency, fuelConsume);
	}
}

// Видалення елемента з таблиці
void deleteEngine(Engine** table, int& count)
{
	if (count == 0)
	{
		printf("No elements in table!");
		return;
	}

	printf("Befor:\n");
	showEngineTable(table, count);

	printf("Enter number of element to delete: ");
	int number;
	scanf("%d", &number);
	if (number <= 0 || number>count)
	{
		printf("Error! There is no number with number %d.", number);
		return;
	}

	number--;
	delete table[number];

	for (count--; number<count; number++)
		table[number] = table[number + 1];

	table[number] = nullptr;

	printf("After:\n");
	showEngineTable(table, count);
}

// Обновити інформація про двигун
void updateEngine(Engine** table, int& count)
{
	if (count == 0)
	{
		printf("No elements in table!");
		return;
	}

	showEngineTable(table, count);

	printf("Enter number of element for update: ");
	int number;
	scanf("%d", &number);
	if (number > count || number <= 0)
	{
		printf("Error! There is no number with number %d.", number);
		return;
	}

	number--;
	int lastCount = count;
	addNewEngine(table, count);
	if (lastCount != count)
	{
		delete table[number];
		count--;
		table[number] = table[count];
		table[count] = nullptr;
	}
}

// Відсортувати таблицю за потужністю
void sortByPower(Engine** table, int& count)
{
	if (count == 0)
	{
		printf("No elements in table!");
		return;
	}

	printf("Before:\n");
	showEngineTable(table, count);

	int min; // Індекс мінімального елементу
	for (int i = 0; i<count; i++)
	{
		min = i;
		for (int z = i + 1; z<count; z++)
			if (table[min]->power > table[z]->power) min = z;

		swap(table, i, min);
	}

	printf("After:\n");
	showEngineTable(table, count);
}

// Відсортувати таблицю за назвами двигунів
void sortByName(Engine** table, int& count)
{
	if (count == 0)
	{
		printf("No elements in table!");
		return;
	}

	printf("Before:\n");
	showEngineTable(table, count);

	int min; // Індекс мінімального елементу
	for (int i = 0; i<count; i++)
	{
		min = i;
		for (int z = i + 1; z<count; z++)
			if (strcmp(table[min]->name, table[z]->name) > 0) min = z;

		swap(table, i, min);
	}

	printf("After:\n");
	showEngineTable(table, count);
}

// Пошук за прямою адресою
void searchDirect(Engine** table, int& count)
{
	if (count == 0)
	{
		printf("No elements in table!");
		return;
	}

	showEngineTable(table, count);

	printf("Enter number of element to search DERECT: ");
	int number;
	scanf("%d", &number);
	if (number <= 0 || number >= count)
	{
		printf("Error! There is no number with number %d.", number);
		return;
	}

	number--;

	printf("%-*s%-10d%-15.2Lf%-15.2Lf\n", maxLengthOfName + 1, table[number]->name, table[number]->power, table[number]->efficiency, table[number]->fuelConsume);
}

// Пошук за назвою
void searchLine(Engine** table, int& count)
{
	showEngineTable(table, count);
	if (count == 0) return;

	char* name = new char[Nmax]; // Повна назва двигуна
	printf("Enter name of engine: ");
	gets_s(name, Nmax);
	if (strlen(name) > maxLengthOfName)
	{
		printf("Error. Name is to long! Try later.");
		delete[] name;
		name = nullptr;
		return;
	}

	for (int i = 0; i<count; i++)
		if (strcmp(table[i]->name, name) == 0)
		{
			printf("Direct number of Search (by LINE) element iS %d", i + 1);
			return;
		}

	printf("No such element as \"%s\"", name);
}

// Пошук за потожністю
void searchBinary(Engine** table, int& count, bool& isSorted)
{
	if (count == 0)
	{
		printf("No elements in table!");
		return;
	}

	if (!isSorted) {
		isSorted = 1;
		printf("Sorting:\n");
		sortByPower(table, count);
		printf("\n");
	}
	else showEngineTable(table, count);

	int power;
	printf("Enter power what you want to find: ");
	scanf("%d", &power);

	int l = 0, r = count - 1;
	while (l + 1 < r)
	{
		int m = (l + r) >> 1;
		if (table[m]->power >= power) r = m;
		else l = m;
	}

	if (table[l]->power == power) printf("Direct number of element is %d", l + 1);
	else if (table[r]->power == power) printf("Direct number of element is %d", r + 1);
	else printf("No such element.");
}