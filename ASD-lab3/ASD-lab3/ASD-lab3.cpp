#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
#include "table.h"

using std::cout;

const int Nmax = 65536; // ����������� ������� ������
Engine* table[Nmax + 1]; // ������� �������
int count = 0; // ������� ������� �������

void textOutput(void); // ��������� ����

int main(void)
{
	srand(time(NULL));
	setlocale(LC_CTYPE, "RUSSIAN");
	bool isSorted = 0; // ������� ������������

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
		default: printf("������� �������!\n");
		}

		printf("\n");
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
		<< "��� ����������� ������ �3\n"
		<< "�������� ������������� ��\n"
		<< "���� ������������ ��� ��������\n"
		<< "������� ������� �������\n"
		<< "���i���: " << 5106 % 20 + 1 << "\n";
	printf("************************************\n\n");

	printf("����i�� �i�:\n");
	printf("1: ������ ����� ������� �� ������i\n");
	printf("2: ����������� �������� �� ������i\n");
	printf("3: �������� ������� � ������i\n");
	printf("4: �������� �������\n");
	printf("5: �i���������� ������� �� ������ic��\n");
	printf("6: �i���������� ������� �� i������\n");
	printf("7: �������� ������� ������i\n");
	printf("8: ���i��� �� ������ �������\n");
	printf("9: ���i��� �i�i���� �������\n");
	printf("0: ���i��� �i������ �������\n");
	printf("Q: ���i�.\n");
}