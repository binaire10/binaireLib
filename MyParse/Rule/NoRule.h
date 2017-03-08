#pragma once

#include "../ParseRule.h"

namespace binaire
{
    class NoRule : public ParseRule
    {
    public:
        NoRule() = default;
        std::string::const_iterator next(std::string::const_iterator begin, const std::string::const_iterator &end) override;
        std::string::const_iterator nextEnd(std::string::const_iterator begin, const std::string::const_iterator &end) override;
        size_t beginSize() const noexcept override;
    };
}
