#pragma once

#include "Parser.h"

namespace binaire
{
    template<typename... ParseRule >
    class StaticParse: public Parser
    {
    };
}
