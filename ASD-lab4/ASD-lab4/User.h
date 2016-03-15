#pragma once

class CUser
{
private:
	char* name;
	char* password;
public:
	CUser(char*, char*);
	~CUser(void);
	int getHesh(int);
};