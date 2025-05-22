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

const String& Person::getID() const
{
    return this->id;
}

const String& Person::getName() const
{
    return this->name;
}

int Person::getAge() const
{
    return this->age;
}

void Person::setID(const char* id)
{
    if (!id || this->id == id) return;

    if (!PersonUtility::isValidID(id)) return;

    this->id = id;
}

void Person::setName(const char* name)
{
    if (!name || this->name == name) return;

    if (!PersonUtility::isValidName(name)) return;

    this->name = name;
}

void Person::setAge(int age)
{
    if (!PersonUtility::isValidAge(age)) return;

    this->age = age;
}
