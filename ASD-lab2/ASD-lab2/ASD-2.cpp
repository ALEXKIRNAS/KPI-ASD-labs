#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "table.h"
#pragma warning(disable : 4996)

const int  Nmax = 100; // ����������� ������� ������
int MAX = 9000;

CTable table[Nmax];
int count = 0;

void textOutput(void); // ��������� ����

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
		default: printf("������� �������!\n");
		}

		system("pause");
	}
}

void textOutput(void)
{
	system("cls");
	printf("************************************\n");
	std::cout << "������ �������:\n"
		<< "���i������ ���������\n"
		<< "����� I�-51\n"
		<< "��� ����������� ������ �2\n"
		<< "���������� ��������i� ������� �����\n"
		<< "�� ����������� i ���������� ���i�\n"
		<< "��i���� �� ���i���� �����\n"
		<< "���i���: " << 5106 % 24 + 1 << "\n";
	printf("************************************\n\n");

	printf("����i�� �i�:\n");
	printf("1: ������ ����� ������� �� ������i\n");
	printf("2: ����������� �������� �� ������i\n");
	printf("3: �������� ������� � ������i\n");
	printf("4: �������� �������\n");
	printf("5: �i���������� �������\n");
	printf("6: �����i��� sum < max\n");
	printf("0: ���i�\n");
}