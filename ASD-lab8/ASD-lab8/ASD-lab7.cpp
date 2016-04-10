#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct tree
{
	string value;
	tree* lefr = nullptr;
	tree* right = nullptr;

	tree() {};
};

tree* leaf (string str)
{
	tree* res = new tree();
	res->value = str;
	return res;
}

tree* exp (string str)
{
	int balance = 0;
	bool flag = false;
	tree* result = new tree();

	if (str.find('=') != string::npos) {
		int pos = str.find('=');
		result->value = "=";
		result->lefr = exp(str.substr(0, pos));
		result->right = exp(str.substr(pos + 1));
		return result;
	}

	for (int i = 0; i < str.length(); i++)
		switch (str[i])
		{
		case '(': balance++; break;
		case ')': balance--; break;
		case '*': if(balance == 0) {
			result->value = str[i]; 
			result->lefr = exp(str.substr(0, i)); 
			result->right = exp(str.substr(i + 1));
			flag = true;
		}
		default: break;
		}

	if (flag) return result;
	else 
	{
		if (str.find("sin") == 0) {
			result->value = "sin";
			int pos1 = str.find('(');
			int pos2 = str.find(')');
			result->lefr = exp(str.substr(pos1+1, pos2-pos1-1));
			return result;
		}

		return leaf(str);
	}
}

tree* parser(string str)
{
	tree* result = new tree();

	if (str.find(";") != string::npos) {
		int pos = str.find(";");
		result->value = "Condition operator";
		result->lefr = parser(str.substr(0, pos));
		result->right = parser(str.substr(pos + 1, str.length() - pos -2));
		return result;
	}

	if (str.find("if") != string::npos)
	{
		int pos1 = 1;
		result->value = "if";
		
		int pos2 = pos1;
		int balance = 0;

		do
		{
			pos2++;
			if (str[pos2] == '(') balance++;
			if (str[pos2] == ')') balance--;
		} while (balance);

		pos1++;

		result->lefr = exp(str.substr(pos1+1, pos2 - pos1 - 1));
		result->right = exp(str.substr(pos2 + 1));
	}
	else
	{
		result->value = "else";
		result->lefr = exp(str.substr(4));
	}

	return result;
}

string eatspaces(string str) 
{
	string res;
	for (int i = 0; i < str.length(); i++) 
		if (str[i] != ' ') res.append(str, i, 1);
	
	return res;
}

void dfs(tree* element, int& count)
{
	if (element->lefr != nullptr) dfs(element->lefr, count);
	cout << "Current vertex " << (++count) << " - " << element->value << endl;
	if (element->right != nullptr) dfs(element->right, count);
}

int main(void) {
	string toParse = "if(c) b=sin(2*a); else b=2*a;";
	tree* parse = parser(eatspaces(toParse));
	int count = 0;
	dfs(parse, count);
}