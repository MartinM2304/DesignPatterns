#pragma once

#include <cstring>
#include <stdexcept>

class InvalidNameException : public std::runtime_error
{
private:
	std::string message;

public:
	InvalidNameException(const std::string& message);

	const char* what() const;
};
