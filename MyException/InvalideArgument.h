#pragma once

#include "CodeException.h"

namespace binaire
{
    class InvalideArgument : public CodeException
    {
    public:
        InvalideArgument(const char *file, int line, const std::string &msg) noexcept;
        template<typename T>
        InvalideArgument(const char *file, int line, const std::string &msg, const T &obj) noexcept : CodeException(file, line, "InvalideArgument", msg, obj)
        {}
    };
}
