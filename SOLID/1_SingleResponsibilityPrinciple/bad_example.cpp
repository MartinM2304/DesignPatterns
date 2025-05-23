#pragma once

#include <iostream>
#include <cstring>

class Person
{
private:
	static constexpr size_t ID_LENGTH = 10;

private:
	std::string id;
	std::string name;
	int age;

	bool isCapitalLetter(char ch) const;
	bool isLowerLetter(char ch) const;
	bool isDigit(char ch) const;

	bool isValidID(const char* id) const;
	bool isValidName(const char* name) const;
	bool isValidAge(int age) const;

public:
	Person();
	Person(const char* id, const char* name, int age);

	const std::string& getID() const;
	const std::string& getName() const;
	int getAge() const;

	void setID(const char* id);
	void setName(const char* name);
	void setAge(int age);

	friend std::ostream& operator<<(std::ostream& os, const Person& obj);
};

Person::Person() : id(""), name(""), age(0)
{
}

Person::Person(const char* id, const char* name, int age)
{
	setID(id);
	setName(name);
	setAge(age);
}

const std::string& Person::getID() const
{
	return this->id;
}

const std::string& Person::getName() const
{
	return this->name;
}

int Person::getAge() const
{
	return this->age;
}

void Person::setID(const char* id)
{
	if (!id || this->id == id)
	{
		throw std::runtime_error("nullptr id!");
	}

	if (!isValidID(id))
	{
		throw std::runtime_error("Invalid ID!");
	}

	this->id = id;
}

void Person::setName(const char* name)
{
	if (!name || this->name == name)
	{
		throw std::runtime_error("Nullptr name!");
	}

	if (!isValidName(name))
	{
		throw std::runtime_error("Invalid name!");
	}

	this->name = name;
}

void Person::setAge(int age)
{
	if (!isValidAge(age))
	{
		throw std::runtime_error("Invalid age!");
	}

	this->age = age;
}

std::ostream& operator<<(std::ostream& os, const Person& obj)
{
	return os << obj.getID() << " " << obj.getName() << " " << obj.getAge() << std::endl;
}

bool Person::isCapitalLetter(char ch) const
{
	return ch >= 'A' && ch <= 'Z';
}

bool Person::isLowerLetter(char ch) const
{
	return ch >= 'a' && ch <= 'z';
}

bool Person::isDigit(char ch) const
{
	return ch >= '0' && ch <= '9';
}

bool Person::isValidID(const char* id) const
{
	if (!id) return false;

	if (strlen(id) > ID_LENGTH) return false;

	while (*id)
	{
		if (!isDigit(*id))
		{
			return false;
		}

		id++;
	}

	return true;
}

bool Person::isValidName(const char* name) const
{
	if (!name) return false;

	if (!isCapitalLetter(*name)) return false;
	name++;

	while (*name)
	{
		if (!isLowerLetter(*name))
		{
			return false;
		}

		name++;
	}

	return true;
}

bool Person::isValidAge(int age) const
{
	return age >= 0 && age <= 120;
}