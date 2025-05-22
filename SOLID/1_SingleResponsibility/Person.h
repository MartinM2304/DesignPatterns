#pragma once

#include <iostream>

#include "PersonUtility.h"
#include "String.h"

class Person
{
private:
	String id;
	String name;
	int age;

public:
	Person();
	Person(const char* id, const char* name, int age);

	const String& getID() const;
	const String& getName() const;
	int getAge() const;

	void setID(const char* id);
	void setName(const char* name);
	void setAge(int age);
};
