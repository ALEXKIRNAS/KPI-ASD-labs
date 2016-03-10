#include <iostream>
#include <Windows.h>
const int NotUsed = system("color F0");

// Перерахування кольорів веселки та присовоєння їм кодів кольорів консолі
enum rainbowColors
{
	RED = 0x4,
	ORANGE = 0x6,
	YELLOW = 0xE,
	GREEN = 0x2,
	BLUE = 0x1,
	INDIGO = 0x9,
	VIOLET = 0x5
};

// Структура збереження кольору в коді CMYK
struct colorCMYK
{
	unsigned char Cyan;
	unsigned char Magenta;
	unsigned char Yellow;
	unsigned char KeyColor;
};

// Cтруктура, що повязує колір та його CMYK-код
struct nameCMYK
{
	colorCMYK color;
	const char* name;
};

// Структура, що несе повну інформацію про колір
struct colorInfo
{
	int				paletteNumber;
	rainbowColors	rainbowColor;
	colorCMYK		cmykColor;
};

// Таблиця назв кольорів та їх CMYK-кодів
const nameCMYK colorNames[] =
{
	{ { 0x00, 0x64, 0x64, 0x14 }, "Червоний" },
	{ { 0x00, 0x23, 0x64, 0x64 }, "Oранжевий" },
	{ { 0x01, 0x0C, 0x64, 0x00 }, "Жовтий" },
	{ { 0x64, 0x00, 0x64, 0x00 }, "Зелений" },
	{ { 0x64, 0x64, 0x00, 0x00 }, "Синiй" },
	{ { 0x2A, 0x64, 0x00, 0x31 }, "Голубий" },
	{ { 0x24, 0x58, 0x00, 0x00 }, "Фiолетовий" }
};

// Функця виводу всіх доступних кольорів
void showColorPalette(void);

// Виведення повної інформація про колір
void showColorInfo(colorInfo);

// Функція перетворення числа в raindowColor
rainbowColors colorFromInput(int&);

int main(void)
{
	setlocale(LC_CTYPE, "RUSSIAN");
	colorInfo color;
	int num;

	while (true)
	{
		system("cls");

		printf("************************************\n");
		std::cout << "Роботу виконав:\n"
			<< "Зарiчковий Олександр\n"
			<< "Група IП-51\n"
			<< "АСД Лабораторна робота №1\n"
			<< "Створення та використання абстракцiй\n"
			<< "для вхiдних та вихiдних даних задач\n"
			<< "Варiант: " << 5106 % 24 + 1 << "\n";
		printf("************************************\n\n");


		std::cout << "Оберiть колiр:\n\n";
		showColorPalette();
		std::cout << "0: Вихiд\n\n";

		std::cin >> num;

		if (num == 0) return 0;
		if (num < 0 || num > sizeof(colorNames) / sizeof(colorNames[0]))
		{
			std::cout << "Помилка введення\n";
			system("pause");
			continue;
		}

		color.paletteNumber = num - 1;
		color.rainbowColor = colorFromInput(color.paletteNumber);
		color.cmykColor = colorNames[color.paletteNumber].color;


		showColorInfo(color);

	}
}

// Функця виводу всіх доступних кольорів
void showColorPalette(void)
{
	size_t colorLength = sizeof(colorNames) / sizeof(colorNames[0]);
	for (int i = 0; i < colorLength; i++)
		std::cout << i + 1 << ": " << colorNames[i].name << "\n";
}

// Виведення повної інформація про колір
void showColorInfo(colorInfo color)
{

	std::cout << "Назва кольору:\t" << colorNames[color.paletteNumber].name << "\n"
		<< "Номер в консолi: " << color.rainbowColor << "\n"
		<< "Номер кольору:\t" << color.paletteNumber + 1 << "\n";

	printf("CMYK-код:\tCyan = %#X Magenta = %#X Yellow = %#X Key Color = %#X\n",
		color.cmykColor.Cyan, color.cmykColor.Magenta, color.cmykColor.Yellow, color.cmykColor.KeyColor);

	std::cout << "Приклад:\t";

	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	/* SetConsoleTextAttribute(hcon, color.rainbowColor);
	std::cout << "****************" << "\n";*/

	SetConsoleTextAttribute(hConsole, (WORD)((color.rainbowColor << 4) | 0xF));
	printf("Hello world!\n");

	SetConsoleTextAttribute(hConsole, (WORD)((0xF << 4) | 0x0));
	system("pause");
}

// Функція перетворення числа в raindowColor
rainbowColors colorFromInput(int& number)
{
	switch (number) {
	case 0:
		return RED;
		break;
	case 1:
		return ORANGE;
		break;
	case 2:
		return YELLOW;
		break;
	case 3:
		return GREEN;
		break;
	case 4:
		return BLUE;
		break;
	case 5:
		return INDIGO;
		break;
	case 6:
		return VIOLET;
		break;
	}
}

/****************************************
Кольора консолі
enum ConsoleColor
{
Black         = 0x0,
Blue          = 0x1,
Green         = 0x2,
Cyan          = 0x3,
Red           = 0x4,
Magenta       = 0x5,
Brown         = 0x6,
LightGray     = 0x7,
DarkGray      = 0x8,
LightBlue     = 0x9,
LightGreen    = 0xA,
LightCyan     = 0xB,
LightRed      = 0xC,
LightMagenta  = 0xD,
Yellow        = 0xE,
White         = 0xF
};
****************************************/