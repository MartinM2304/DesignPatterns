#include "InvalidAgeException.h"

InvalidAgeException::InvalidAgeException(const std::string& message) : message(message)
{
}

const char* InvalidAgeException::what() const
{
	return message.c_str();
}
