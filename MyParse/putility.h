#pragma once
#include "ParseRule.h"

namespace binaire
{
    inline bool equal(const std::string &value, const std::pair<std::string::const_iterator, std::string::const_iterator> &str)
    {
        return ParseRule::existAt(str.first, str.second, value.begin(), value.end());
    }
}
