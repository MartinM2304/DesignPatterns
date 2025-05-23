#pragma once
#include <vector>
#include <memory>
#include "Command.h"
#include "CommandFactory.h"


class CommandInvoker
{
	CommandFactory* commandFactory;

public:
	CommandInvoker(CommandFactory* factory):commandFactory(factory) {

	}
	void execute(const std::string& commandString,const std::string& text) {
		Command* cmd = commandFactory->getCommand(commandString);
		cmd->execute(text);
	}
};

