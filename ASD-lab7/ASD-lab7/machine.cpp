#include "machine.h"

State matrState[nS+1][nSg] = {
	{S2, S2, S2},//0
	{S6, S6, S6},//1
	{S5, S3, S5},//2
	{S5, S3, S5},//3
	{S6, S6, S6},//4
	{S1, S4, S7},//5
	{S2, S2, nS},//6
	{S1, S1, S1},//7
	{nS, nS, nS},//n
};

void newState(int& state, char signal) {
	state = matrState[state][mkSignal(signal)];
}

int mkSignal(char ch) {
	if (isalpha(ch)) return 0;
	if (isspace(ch)) return 1;
	return 2;
}