#pragma once
#include "Command.h"
#include "TextProcessor.h"

class UpperCaseCommand :
    public Command
{
    TextProcessor* receiver;
public:
    UpperCaseCommand(TextProcessor* r) : receiver(r) {}
    void execute(std::string& text) override {
        receiver->toUpperCase(text);
    }
};

