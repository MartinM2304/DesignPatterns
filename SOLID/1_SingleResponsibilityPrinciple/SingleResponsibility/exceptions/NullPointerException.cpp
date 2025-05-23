#include "NullPointerException.h"

NullPointerException::NullPointerException(const std::string& message) : message(message)
{
}

const char* NullPointerException::what() const
{
	return message.c_str();
}
