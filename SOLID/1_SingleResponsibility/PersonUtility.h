#pragma once

#include <cstring>

class PersonUtility
{
private:
	static constexpr size_t ID_LENGTH = 10;

private:
	static bool isCapitalLetter(char ch);
	static bool isLowerLetter(char ch);
	static bool isDigit(char ch);

public:
	static bool isValidID(const char* id);

	static bool isValidName(const char* name);

	static bool isValidAge(int age);
};
