#include "table.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable : 4996)

const int Rmax = 1000;
const int Gmax = 1000;
const int Bmax = 1000;

CTable::CTable(int r, int g, int b)
{
	R_feeld = r;
	G_feeld = g;
	B_feeld = b;
}

void add(CTable* table, int& count) //Добавити елемент до таблиці
{
	int r, g, b;

	printf("Введiть R-значення кольору:\t");
	scanf("%d", &r);
	printf("Введiть G-значення кольору:\t");
	scanf("%d", &g);
	printf("Введiть B-значення кольору:\t");
	scanf("%d", &b);

	if (!isCorrect(r, g, b))
	{
		printf("Помилка введення. Значення кольорiв не вiдповiдають зазначеному дiапазону.\n");
		return;
	}

	table[count++] = CTable(r, g, b);
}

void erasse(CTable* table, int& count) // Видалити елемент
{
	printf(table, count);
	if (count == 0) return;

	printf("Виберiть номер запису, який потрiбно видалити.\n");

	int num;
	scanf("%d", &num);

	if (num>count || num <= 0)
	{
		printf("Такий номер вiдсутнiй.\n");
		return;
	}

	count--;
	for (num--; num<count; num++)
		table[num] = table[num + 1];

	printf(table, count);
}

void sort(CTable* table, int& count) // Сортувати таблицю
{
	if (count == 0)
	{
		printf("Записи вiдсутнi.\n");
		return;
	}

	for (int i = 0; i<count; i++)
	{
		int min = i;
		for (int z = i + 1; z<count; z++)
			if (cmp(table[min], table[z]) > 0) min = z;

		swap(table[i], table[min]);
	}

	printf(table, count);
}

void printf(CTable* table, int& count)// Виведення таблиці
{
	if (count == 0)
	{
		printf("Записи вiдстунi.\n");
		return;
	}

	printf("%3s%11s%11s%11s\n", "№", "R-поле", "G-поле", "B-поле");
	for (int i = 0; i<count; i++)
		printf("%3d%11d%11d%11d\n", i + 1, table[i].R_feeld, table[i].G_feeld, table[i].B_feeld);
}

bool isCorrect(int& r, int& g, int& b) // Перевірка не коректність введених даних
{
	return (r >= 0 && r <= Rmax && g >= 0 && g <= Gmax && b >= 0 && b <= Bmax);
}

int cmp(CTable& a, CTable& b) // Компаратор
{
	if (a.R_feeld != b.R_feeld) return a.R_feeld - b.R_feeld;
	if (a.G_feeld != b.G_feeld) return a.G_feeld - b.G_feeld;
	return a.B_feeld - b.B_feeld;
}

void swap(CTable& a, CTable& b)// Поміняти місцями елементи
{
	CTable c = a;
	a = b;
	b = c;
}

void add_gen(CTable* table, int& count, const int& Nmax) // Генератор
{
	printf("Введiть кiлькiсть елементiв на генерацiю\n");
	int num;
	scanf("%d", &num);

	if (num<0)
	{
		printf("Помилка введення.\n");
		return;
	}

	if (count + num > Nmax)
	{
		printf("Масив переповнений! Буде згенеровоно %d елементiв.\n", Nmax - count);
		num = Nmax - count;
	}

	for (int i = 0; i<num; i++)
		table[count++] = CTable(rand() % (Rmax + 1), rand() % (Gmax + 1), rand() % (Bmax + 1));
}

void sum_func(CTable* table, int& count, int& max) // Підсумовує значення в рядах
{
	printf(table, count);
	printf("\n\n");

	bool f = 1;

	int Rsum = 0, Bsum = 0, Gsum = 0;
	for (int i = 0; i<count; i++)
	{
		Rsum += table[i].R_feeld;
		Gsum += table[i].G_feeld;
		Bsum += table[i].B_feeld;
	}

	if (Rsum > max)
	{
		printf("Сума елементiв R-поля бiльша за MAX.\n");
		f = 0;
	}

	if (Gsum > max)
	{
		printf("Сума елементiв G-поля бiльша за MAX.\n");
		f = 0;
	}

	if (Bsum > max)
	{
		printf("Сума елементiв B-поля бiльша за MAX.\n");
		f = 0;
	}

	if (f) printf("Значення у всiх стовпцях меншi за MAX.\n");
}