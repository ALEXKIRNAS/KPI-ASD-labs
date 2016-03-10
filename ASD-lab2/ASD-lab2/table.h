#pragma once

struct CTable
{
	int R_feeld; // R - ����
	int G_feeld; // G - ����
	int B_feeld; // B - ����

	CTable(int = 0, int = 0, int = 0); // �����������
};

void add(CTable*, int&); //�������� ������� �� �������
void erasse(CTable*, int&); // �������� �������
void sort(CTable*, int&); // ��������� �������
void printf(CTable*, int&); // ��������� �������
bool isCorrect(int&, int&, int&); // �������� �� ���������� �������� �����
int cmp(CTable&, CTable&); // ����������
void swap(CTable&, CTable&); // ������� ������ ��������
void add_gen(CTable*, int&, const int&); // ���������
void sum_func(CTable*, int&, int&); // ϳ������� �������� � ��������