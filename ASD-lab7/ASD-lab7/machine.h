#pragma once
#include <ctype.h>
typedef int State;

enum Signals { sg0, sg1, sg2, nSg }; // ������ ������
enum States { S0 = 0, S1, S2, S3, S4, S5, S6, S7, nS }; // ������ �����

void newState(int &, char); // �������� ������� �������� �� ����� �����
int mkSignal(char);