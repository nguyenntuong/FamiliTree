#include "Utils.h"

vector<string> Utils::Split(char* original, char c, bool hasFinal)
{
	vector<string> op;
	string tmp = "";
	int j = 0;
	int i = 0;
	while (original[i] != '\0')
	{
		if (original[i] == c) {
			op.push_back(tmp);
			tmp = "";
		}
		else {
			tmp += original[i];
		}
		i++;
	}
	if (!hasFinal) {
		op.push_back(tmp);
	}
	return op;
}

vector<string> Utils::Split(string original, char c, bool hasFinal)
{
	vector<string> op;
	string tmp = "";
	int j = 0;
	int i = 0;
	while (original[i] != '\0')
	{
		if (original[i] == c) {
			op.push_back(tmp);
			tmp = "";
		}
		else {
			tmp += original[i];
		}
		i++;
	}
	if (!hasFinal) {
		op.push_back(tmp);
	}
	return op;
}

