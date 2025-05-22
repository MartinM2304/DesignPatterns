#include "PersonUtility.h"

bool PersonUtility::isCapitalLetter(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

bool PersonUtility::isLowerLetter(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

bool PersonUtility::isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

bool PersonUtility::isValidID(const char* id)
{
	if (!id) return false;
	if (strlen(id) > ID_LENGTH) return false;

	while (id)
	{
		if (!isDigit(*id))
		{
			return false;
		}

		id++;
	}

	return true;
}

bool PersonUtility::isValidName(const char* name)
{
	if (!name) return false;
	if (!isCapitalLetter(*name)) return false;

	while (name)
	{
		if (!isLowerLetter(*name))
		{
			return false;
		}

		name++;
	}

	return true;
}

bool PersonUtility::isValidAge(int age)
{
	return age >= 0 && age <= 120;
}
