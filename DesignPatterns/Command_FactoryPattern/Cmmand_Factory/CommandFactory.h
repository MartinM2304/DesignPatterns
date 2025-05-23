#pragma once
#include "Command.h"
#include "TextProcessor.h"
#include "LowerCaseCommand.h"
#include "UpperCaseCommand.h"
#include "ReverseCommand.h"

class CommandFactory
{
	TextProcessor* textProcessor;

public:
	CommandFactory(TextProcessor* textprocessor):textProcessor(textProcessor){}

	Command* getCommand(const std::string& commandString) {
        if (commandString == "UPPER") {
            return new UpperCaseCommand(textProcessor);
        }
        else if (commandString == "LOWER") {
            return new LowerCaseCommand(textProcessor);
        }
        else if (commandString == "REVERSE") {
            return new ReverseCommand(textProcessor);
        }
        else {
            return nullptr; 
        }
	}
};

