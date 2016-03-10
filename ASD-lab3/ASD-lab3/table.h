#pragma once

// C���������, �� ������ ���������� ��� �������
struct Engine
{
	char* name; // ����� ����� �������
	double efficiency; // ��� ������� (������������� ����)
	double fuelConsume; // ���������� �������� �� 100 �� (������������� ����)
	unsigned long power; // ��������� ������� (� ������� �����)

	Engine(char*, unsigned long, double, double); // ����������� ������ ��������
};

void swap(Engine**, int, int); // ������� ������ ��� �������� � �������
void showEngineTable(Engine**, int&); // ��������� ������� �� �����
void addNewEngine(Engine**, int&); // ���������� ������ �������� � ������� (������)
void addNewEngineByGen(Engine**, int&, int); // ��������� ����� ��������
void deleteEngine(Engine**, int&); // ��������� �������� � �������
void updateEngine(Engine**, int&); // �������� ���������� ��� ������
void sortByPower(Engine**, int&); // ³���������� ������� �� ���������
void sortByName(Engine**, int&); // ³���������� ������� �� ������� �������
void searchDirect(Engine**, int&); // ����� �� ������ �������
void searchLine(Engine**, int&); // ����� �� ������
void searchBinary(Engine**, int&, bool&); // ����� �� ���������