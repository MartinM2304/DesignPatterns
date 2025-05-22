#include "ImmutableString.h"

StringPool ImmutableString::pool;

ImmutableString::ImmutableString() : ImmutableString("")
{
}

ImmutableString::ImmutableString(const char* str)
{
	this->size = strlen(str);
	this->data = pool.getString(str);
}

ImmutableString::ImmutableString(const ImmutableString& other)
{
	this->size = other.size;
	this->data = pool.getString(other.c_str());
}

ImmutableString& ImmutableString::operator=(const ImmutableString& other)
{
	if (this != &other)
	{
		pool.removeString(data);
		data = pool.getString(other.c_str());
		size = other.size;
	}

	return *this;
}

const char& ImmutableString::operator[](size_t idx) const
{
	return this->data[idx];
}

const char* ImmutableString::c_str() const
{
	return this->data;
}

size_t ImmutableString::getSize() const
{
	return this->size;
}

bool ImmutableString::isEmpty() const
{
	return this->size == 0;
}

ImmutableString::~ImmutableString() noexcept
{
	pool.removeString(this->data);
	this->data = nullptr;
	this->size = 0;
}

bool operator==(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const ImmutableString& other)
{
	return os << other.c_str() << std::endl;
}