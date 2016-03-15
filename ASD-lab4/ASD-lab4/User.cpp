#include "User.h"
#include <string.h>

const int Char_Max = 255;

CUser::CUser(char* name, char* password)
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);

	this->password = new char[strlen(password)+1];
	strcpy(this->password, password);
}

CUser::CUser(const CUser& elem)
{
	this->name = new char[strlen(elem.getName()) + 1];
	strcpy(this->name, elem.getName());

	this->password = new char[strlen(elem.getPassword()) + 1];
	strcpy(this->password, elem.getPassword());
}

CUser::~CUser()
{
	delete[] name;
	delete[] password;
}


// Making hesh for User Name
int CUser::getUserNameHash (int mod)
{
	return strHesh(name, mod);
}

// Making a hesh for one string
int CUser::strHesh(char* str, int& mod)
{
	int hesh = 0;
	int k = 1;

	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		if (k == 0) 
			break;
		hesh = (hesh + k*str[i]) % mod;
		
		k = (k*Char_Max) % mod;
	}

	return hesh;
}

// Compare <str> with corrent user <name>
bool CUser::namecmp(char* str)
{
	return !strcmp(str, name);
}

// Compare <password> with corrent user <password>
bool CUser::passwordcmp(char* password)
{
	return !strcmp(this->password, password);
}

char* CUser::getName(void) const 
{
	return name;
}

char*  CUser::getPassword(void) const 
{
	return password;
}

void CUser::setPassword(char* password)
{
	delete[] this->password;
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
}