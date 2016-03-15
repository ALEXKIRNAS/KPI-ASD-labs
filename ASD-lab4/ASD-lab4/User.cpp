#include "User.h"
#include <string.h>

const int Char_Max = 255;

CUser::CUser(char* name, char* password)
{
	this->name = new char[strlen(name)];
	strcpy(this->name, name);

	this->password = new char[strlen(password)];
	strcpy(this->password, password);
}

CUser::~CUser()
{
	delete[] name;
	delete[] password;
}

// Making hesh for all strings
int CUser::getHesh(int mod)
{
	return (strHesh(name, mod) + strHesh(password, mod)) % mod;
}

// Making a hesh for one string
int CUser::strHesh(char* str, int& mod)
{
	int hesh = 0;
	int k = 1;

	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		if (k == 0) break;
		hesh = (hesh + k*str[i]) % mod;
		
		k = (k*Char_Max) % mod;
	}

	return hesh;
}