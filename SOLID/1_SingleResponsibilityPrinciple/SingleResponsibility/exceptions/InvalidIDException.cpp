#include "InvalidIDException.h"

InvalidIDException::InvalidIDException(const std::string& message) : message(message)
{
}

const char* InvalidIDException::what() const
{
	return message.c_str();
}
