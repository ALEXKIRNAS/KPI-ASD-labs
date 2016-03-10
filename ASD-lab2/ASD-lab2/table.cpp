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

void add(CTable* table, int& count) //�������� ������� �� �������
{
	int r, g, b;

	printf("����i�� R-�������� �������:\t");
	scanf("%d", &r);
	printf("����i�� G-�������� �������:\t");
	scanf("%d", &g);
	printf("����i�� B-�������� �������:\t");
	scanf("%d", &b);

	if (!isCorrect(r, g, b))
	{
		printf("������� ��������. �������� ������i� �� �i����i����� ����������� �i�������.\n");
		return;
	}

	table[count++] = CTable(r, g, b);
}

void erasse(CTable* table, int& count) // �������� �������
{
	printf(table, count);
	if (count == 0) return;

	printf("�����i�� ����� ������, ���� ����i��� ��������.\n");

	int num;
	scanf("%d", &num);

	if (num>count || num <= 0)
	{
		printf("����� ����� �i�����i�.\n");
		return;
	}

	count--;
	for (num--; num<count; num++)
		table[num] = table[num + 1];

	printf(table, count);
}

void sort(CTable* table, int& count) // ��������� �������
{
	if (count == 0)
	{
		printf("������ �i�����i.\n");
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

void printf(CTable* table, int& count)// ��������� �������
{
	if (count == 0)
	{
		printf("������ �i�����i.\n");
		return;
	}

	printf("%3s%11s%11s%11s\n", "�", "R-����", "G-����", "B-����");
	for (int i = 0; i<count; i++)
		printf("%3d%11d%11d%11d\n", i + 1, table[i].R_feeld, table[i].G_feeld, table[i].B_feeld);
}

bool isCorrect(int& r, int& g, int& b) // �������� �� ���������� �������� �����
{
	return (r >= 0 && r <= Rmax && g >= 0 && g <= Gmax && b >= 0 && b <= Bmax);
}

int cmp(CTable& a, CTable& b) // ����������
{
	if (a.R_feeld != b.R_feeld) return a.R_feeld - b.R_feeld;
	if (a.G_feeld != b.G_feeld) return a.G_feeld - b.G_feeld;
	return a.B_feeld - b.B_feeld;
}

void swap(CTable& a, CTable& b)// ������� ������ ��������
{
	CTable c = a;
	a = b;
	b = c;
}

void add_gen(CTable* table, int& count, const int& Nmax) // ���������
{
	printf("����i�� �i���i��� �������i� �� �������i�\n");
	int num;
	scanf("%d", &num);

	if (num<0)
	{
		printf("������� ��������.\n");
		return;
	}

	if (count + num > Nmax)
	{
		printf("����� ������������! ���� ����������� %d �������i�.\n", Nmax - count);
		num = Nmax - count;
	}

	for (int i = 0; i<num; i++)
		table[count++] = CTable(rand() % (Rmax + 1), rand() % (Gmax + 1), rand() % (Bmax + 1));
}

void sum_func(CTable* table, int& count, int& max) // ϳ������� �������� � �����
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
		printf("���� �������i� R-���� �i���� �� MAX.\n");
		f = 0;
	}

	if (Gsum > max)
	{
		printf("���� �������i� G-���� �i���� �� MAX.\n");
		f = 0;
	}

	if (Bsum > max)
	{
		printf("���� �������i� B-���� �i���� �� MAX.\n");
		f = 0;
	}

	if (f) printf("�������� � ��i� �������� ����i �� MAX.\n");
}