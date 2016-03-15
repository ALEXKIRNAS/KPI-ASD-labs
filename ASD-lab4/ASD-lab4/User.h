#pragma once

class CUser
{
private:
	char* name;
	char* password;
	int strHesh(char*, int&);
public:
	CUser(char*, char*);
	~CUser(void);
	int getHesh(int);
};