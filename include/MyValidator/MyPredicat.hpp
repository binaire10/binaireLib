#pragma once
#include "../MetaTemplate/MetaReturn.hpp"

namespace binaire
{
    inline bool isUpper(const char &Value)
    {
        return isInBorne<char,0x41, 0x5A>(Value);
    }

    inline bool isLower(const char &Value)
    {
        return isInBorne<char,0x61, 0x7A>(Value);
    }

    inline bool isAlpha(const char &Value)
    {
        return isInBorne<char,0x41, 0x5A>(Value) || isInBorne<char,0x61, 0x7A>(Value);
    }

    inline bool isNum(const char &Value)
    {
        return isInBorne<char,0x30, 0x39>(Value);
    }

    inline bool isAlphaNum(const char &Value)
    {
        return isInBorne<char,0x30, 0x39>(Value) ||
               isInBorne<char,0x41, 0x5A>(Value) ||
               isInBorne<char,0x61, 0x7A>(Value);
    }

    inline bool IsInWord(const char &Value)
    {
        return  isAlphaNum(Value);
    }

    inline bool isPrintable(const char &Value)
    {
        return  isInBorne<char,0x21, 0x7E>(Value);
    }


    inline bool IsSymbol(const char &Value)
    {
        return  isInBorne<char, 0x21, 0x2F>(Value) ||
                isInBorne<char, 0x3A, 0x40>(Value) ||
                isInBorne<char, 0x5B, 0x60>(Value) ||
                isInBorne<char, 0x7B, 0x7E>(Value);
    }

    inline bool IsSpace(const char &Value)
    {
        return Value == ' ';
    }

    inline bool IsReturnLine(const char &Value)
    {
        return Value == '\n';
    }

}
