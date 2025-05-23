#pragma once

#include <cstring>
#include <stdexcept>

class InvalidIDException : public std::runtime_error
{
private:
	std::string message;

public:
	InvalidIDException(const std::string& message);

	const char* what() const;
};
