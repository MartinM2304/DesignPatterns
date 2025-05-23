#pragma once
#include "Command.h"
#include "TextProcessor.h"

class ReverseCommand :
    public Command
{
private:
    TextProcessor* receiver;
public:
    ReverseCommand(TextProcessor* r) : receiver(r) {}
    void execute(std::string& text) override {
        receiver->reverseText(text);
    }
};

