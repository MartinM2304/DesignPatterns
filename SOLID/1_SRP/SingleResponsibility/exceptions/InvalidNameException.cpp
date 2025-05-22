#include "InvalidNameException.h"

InvalidNameException::InvalidNameException(const std::string& message) : message(message)
{
}

const char* InvalidNameException::what() const
{
	return message.c_str();
}
