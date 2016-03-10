#pragma once

struct CTable
{
	int R_feeld; // R - поле
	int G_feeld; // G - поле
	int B_feeld; // B - поле

	CTable(int = 0, int = 0, int = 0); // Конструктор
};

void add(CTable*, int&); //Добавити елемент до таблиці
void erasse(CTable*, int&); // Видалити елемент
void sort(CTable*, int&); // Сортувати таблицю
void printf(CTable*, int&); // Виведення таблиці
bool isCorrect(int&, int&, int&); // Перевірка не коректність введених даних
int cmp(CTable&, CTable&); // Компаратор
void swap(CTable&, CTable&); // Поміняти місцями елементи
void add_gen(CTable*, int&, const int&); // Генератор
void sum_func(CTable*, int&, int&); // Підсумовує значення в стовпцях