#pragma once
#include "Command.h"
#include "TextProcessor.h"

class LowerCaseCommand :
    public Command
{
    TextProcessor* receiver;
public:
    LowerCaseCommand(TextProcessor* r) : receiver(r) {}

    void execute(std::string& text) override {
        receiver->toLowerCase(text);
    }
};

