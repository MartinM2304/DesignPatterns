#include "TextProcessor.h"
#include <iostream>

void TextProcessor::toUpperCase(std::string& text)
{
    for (int i = 0;i<text.length();i++) {
        char c = text[i];
        c = toupper(c);
    }
    std::cout << "Text converted to uppercase: " << text << std::endl;
}

void TextProcessor::toLowerCase(std::string& text)
{
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        c = tolower(c);
    }
    std::cout << "Text converted to lowercase: " << text << std::endl;
}

void TextProcessor::reverseText(std::string& text)
{
    std::reverse(text.begin(), text.end());
}
