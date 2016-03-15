#pragma once

class CUser
{
private:
	char* name;
	char* password;
	int strHesh(char*, int&);
public:
	CUser(char*, char*);
	CUser(const CUser&);
	~CUser(void);

	int getUserNameHash (int);
	bool namecmp(char*);
	bool passwordcmp(char*);
	char* getName(void) const;
	char* getPassword(void) const;
};