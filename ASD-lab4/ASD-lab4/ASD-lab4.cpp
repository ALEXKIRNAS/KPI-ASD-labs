#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "User.h"
using std::vector;

const int Nmax = 39233;

vector <CUser> dataBase [Nmax]; // Holding a User hesh for quich search

void printMenu(void); // Printing main menu to screen
void add(void); // Adding new member
void del(void); // Deleating member
CUser* search(CUser&); // Search member by hesh


int main(void)
{
	while (true)
	{
		system("cls");
		printMenu();
		char ch = _getch();

		switch (ch)
		{
		case '1': add(); break;
		case '2': del(); break;
		case 'q': return 0;
		}
		system("pause");
	}
}

// Printing main menu to screen
void printMenu(void)
{
	printf("Menu:\n");
	printf("1: Add new member.\n");
	printf("2: Delete member.\n");
	printf("3: View user names.\n");
	printf("4: View hesh of user names (administration only).\n");
	printf("5: Veiw user names and passowords (administration only).\n");
	printf("Q: Exit.\n");
}

// Adding new member
void add(void)
{
	const int lens = 51;
	char user[lens], password[lens];
	printf("Enter login (maximum 50 simbols): ");
	gets_s(user);
	char* empty = "12345";

	CUser temp = CUser(user, empty);
	if (search(temp) != nullptr)
	{
		printf("Ther is already user with that name. Try later!\n");
		return;
	}

	printf("Enter password (maximum 50 simbols): ");
	gets_s(password);
	
	
	CUser unit = CUser(user, password);
	dataBase[unit.getUserNameHash(Nmax)].push_back(unit);
	printf("User added sucsesful.\n");
}

// Search member by hesh
CUser* search(CUser& user)
{
	int hesh = user.getUserNameHash(Nmax);
	for (int i = 0; i < dataBase[hesh].size(); i++)
		if (dataBase[hesh][i].namecmp(user.getName())) return &dataBase[hesh][i];
	return nullptr;
}

// Deleating member
void del(void)
{
	const int lens = 51;
	char name[lens], password[lens];
	printf("Enter login (maximum 50 simbols): ");
	gets_s(name);

	CUser temp = CUser(name, "12345");
	
	if (search(temp) != nullptr)
	{
		printf("Enter password (maximum 50 simbols): ");
		gets_s(password);
		CUser unit = CUser(name, password);

		if (strcmp(search(temp)->getPassword(), password) == 0)
		{
			int index = unit.getUserNameHash(Nmax);
			for (int i = 0; i < dataBase[index].size(); i++) if (strcmp(unit.getName(), dataBase[index][i].getName()) == 0)
			{
				dataBase[index].erase(dataBase[index].begin() + i, dataBase[index].begin() + i + 1);
				printf("User deleated sucssecful!\n");
				break;
			}
		}
		else
		{
			printf("Error. Wrong password!\n");
			return;
		}

	}
	else printf("Error. No such user!\n");
}