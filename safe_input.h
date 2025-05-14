#ifndef SAFE_INPUT
#define SAFE_INPUT

#include <iostream>
#include <utility>
#include <string>
#include "ClearBuffer.h"

template <class T>
T safe_input(const std::string& error_message)
{
    T entered;
    
    while (true)
    {
        std::cin >> entered;
        if (std::cin.fail())
        {
            ClearBuffer();
            std::cout << "\n\n[INVALID INPUT ERROR] " << error_message << ": ";
            continue;
        }
        
        ClearBuffer();
        return entered;
    }
}

template <class T>
T safe_input_stream(std::istream& is, const std::string& error_message)
{
    T entered;

    while (true)
    {
        is >> entered;
        if (is.fail())
        {
            ClearBuffer();
            std::cout << "\n\n[INVALID INPUT ERROR] " << error_message << ": ";
            continue;
        }
        
        ClearBuffer();
        return entered;
    }
}

#endif