#pragma once

#include <cstring>
#include <stdexcept>

class InvalidAgeException : public std::runtime_error
{
private:
	std::string message;

public:
	InvalidAgeException(const std::string& message);

	const char* what() const;
};
