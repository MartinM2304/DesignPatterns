#pragma once

#include <cstring>
#include <stdexcept>

class NullPointerException : public std::runtime_error
{
private:
	std::string message;

public:
	NullPointerException(const std::string& str);

	const char* what() const;
};

