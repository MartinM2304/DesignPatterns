#pragma once

#include <iostream>
#include <cstring>

#include "PersonUtility.h"

#include "exceptions/NullPointerException.h"
#include "exceptions/InvalidIDException.h"
#include "exceptions/InvalidNameException.h"
#include "exceptions/InvalidAgeException.h"

class Person
{
private:
	std::string id;
	std::string name;
	int age;

public:
	Person();
	Person(const char* id, const char* name, int age);

	const std::string& getID() const;
	const std::string& getName() const;
	int getAge() const;

	void setID(const char* id);
	void setName(const char* name);
	void setAge(int age);
};
