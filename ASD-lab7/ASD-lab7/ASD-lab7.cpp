#include <iostream>
#include <string.h>
#include "machine.h"

#define Nmax 1000


using namespace std;

int main() {
	int signal, state = S0;
	char ch[Nmax];

	printf("State: %3d\n", state);
	int i = 0;

	while (true) {
		printf("Input next char: ");
		gets_s(ch);
		newState(state, ch[0]);
		printf("State: %3d\n", state);
	}
	system("pause");
}