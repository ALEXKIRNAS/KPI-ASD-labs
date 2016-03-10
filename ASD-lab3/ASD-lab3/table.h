#pragma once

// Cтруктрура, що містить інформацію про двигуни
struct Engine
{
	char* name; // Повна назва двигуна
	double efficiency; // ККД двигуна (функціональне поле)
	double fuelConsume; // Споживання пального на 100 км (функціональне поле)
	unsigned long power; // Потужність двигуна (в кінських силах)

	Engine(char*, unsigned long, double, double); // Конструктор нового елементу
};

void swap(Engine**, int, int); // Поміняти місцями два елементи в таблиці
void showEngineTable(Engine**, int&); // Виведення таблиці на екран
void addNewEngine(Engine**, int&); // Добавлення нового елементу в таблицю (вручну)
void addNewEngineByGen(Engine**, int&, int); // Генерація нових елементів
void deleteEngine(Engine**, int&); // Видалення елемента з таблиці
void updateEngine(Engine**, int&); // Обновити інформація про двигун
void sortByPower(Engine**, int&); // Відсортувати таблицю за потужністю
void sortByName(Engine**, int&); // Відсортувати таблицю за назвами двигунів
void searchDirect(Engine**, int&); // Пошук за прямою адресою
void searchLine(Engine**, int&); // Пошук за назвою
void searchBinary(Engine**, int&, bool&); // Пошук за потожністю