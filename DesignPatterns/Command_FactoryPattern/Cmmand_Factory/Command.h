#pragma once
#include <string>

class Command
{
public:
	virtual void execute(std::string& text) = 0;
	virtual ~Command() = default;
};

