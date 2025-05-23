#include "Person.h"

Person::Person() : name(""), age(0)
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
        throw NullPointerException("nullptr id");
    }

    if (!PersonUtility::isValidID(id))
    {
        throw InvalidIDException("invalid id");
    }

    this->id = id;
}

void Person::setName(const char* name)
{
    if (!name || this->name == name)
    {
        throw NullPointerException("nullptr name");
    }

    if (!PersonUtility::isValidName(name))
    {
        throw InvalidNameException("invalid name");
    }

    this->name = name;
}

void Person::setAge(int age)
{
    if (!PersonUtility::isValidAge(age))
    {
        throw InvalidAgeException("invalid age");
    }

    this->age = age;
}
