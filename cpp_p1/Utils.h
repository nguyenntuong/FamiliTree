#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Utils
{
public:
	static vector<string> Split(char* original, char c, bool hasFinal);
	static vector<string> Split(string original, char c, bool hasFinal);
};

