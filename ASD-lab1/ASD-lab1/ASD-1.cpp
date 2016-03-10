#include <iostream>
#include <Windows.h>
const int NotUsed = system("color F0");

// ������������� ������� ������� �� ���������� �� ���� ������� ������
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

// ��������� ���������� ������� � ��� CMYK
struct colorCMYK
{
	unsigned char Cyan;
	unsigned char Magenta;
	unsigned char Yellow;
	unsigned char KeyColor;
};

// C��������, �� ������ ���� �� ���� CMYK-���
struct nameCMYK
{
	colorCMYK color;
	const char* name;
};

// ���������, �� ���� ����� ���������� ��� ����
struct colorInfo
{
	int				paletteNumber;
	rainbowColors	rainbowColor;
	colorCMYK		cmykColor;
};

// ������� ���� ������� �� �� CMYK-����
const nameCMYK colorNames[] =
{
	{ { 0x00, 0x64, 0x64, 0x14 }, "��������" },
	{ { 0x00, 0x23, 0x64, 0x64 }, "O��������" },
	{ { 0x01, 0x0C, 0x64, 0x00 }, "������" },
	{ { 0x64, 0x00, 0x64, 0x00 }, "�������" },
	{ { 0x64, 0x64, 0x00, 0x00 }, "���i�" },
	{ { 0x2A, 0x64, 0x00, 0x31 }, "�������" },
	{ { 0x24, 0x58, 0x00, 0x00 }, "�i��������" }
};

// ������ ������ ��� ��������� �������
void showColorPalette(void);

// ��������� ����� ���������� ��� ����
void showColorInfo(colorInfo);

// ������� ������������ ����� � raindowColor
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
		std::cout << "������ �������:\n"
			<< "���i������ ���������\n"
			<< "����� I�-51\n"
			<< "��� ����������� ������ �1\n"
			<< "��������� �� ������������ ��������i�\n"
			<< "��� ��i���� �� ���i���� ����� �����\n"
			<< "���i���: " << 5106 % 24 + 1 << "\n";
		printf("************************************\n\n");


		std::cout << "����i�� ���i�:\n\n";
		showColorPalette();
		std::cout << "0: ���i�\n\n";

		std::cin >> num;

		if (num == 0) return 0;
		if (num < 0 || num > sizeof(colorNames) / sizeof(colorNames[0]))
		{
			std::cout << "������� ��������\n";
			system("pause");
			continue;
		}

		color.paletteNumber = num - 1;
		color.rainbowColor = colorFromInput(color.paletteNumber);
		color.cmykColor = colorNames[color.paletteNumber].color;


		showColorInfo(color);

	}
}

// ������ ������ ��� ��������� �������
void showColorPalette(void)
{
	size_t colorLength = sizeof(colorNames) / sizeof(colorNames[0]);
	for (int i = 0; i < colorLength; i++)
		std::cout << i + 1 << ": " << colorNames[i].name << "\n";
}

// ��������� ����� ���������� ��� ����
void showColorInfo(colorInfo color)
{

	std::cout << "����� �������:\t" << colorNames[color.paletteNumber].name << "\n"
		<< "����� � ������i: " << color.rainbowColor << "\n"
		<< "����� �������:\t" << color.paletteNumber + 1 << "\n";

	printf("CMYK-���:\tCyan = %#X Magenta = %#X Yellow = %#X Key Color = %#X\n",
		color.cmykColor.Cyan, color.cmykColor.Magenta, color.cmykColor.Yellow, color.cmykColor.KeyColor);

	std::cout << "�������:\t";

	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	/* SetConsoleTextAttribute(hcon, color.rainbowColor);
	std::cout << "****************" << "\n";*/

	SetConsoleTextAttribute(hConsole, (WORD)((color.rainbowColor << 4) | 0xF));
	printf("Hello world!\n");

	SetConsoleTextAttribute(hConsole, (WORD)((0xF << 4) | 0x0));
	system("pause");
}

// ������� ������������ ����� � raindowColor
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
������� ������
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