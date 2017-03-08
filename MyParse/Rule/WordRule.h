#pragma once

#include <string>
#include "../ParseRule.h"
#include "../../MyFunction/IFunction.h"
#include "../../MyMemory/CPtr.h"

namespace binaire
{
    class WordRule : public ParseRule
    {
    public:
        WordRule(const CPtr< binaire::IFunction<bool, char> > &predicat) noexcept;
        std::string::const_iterator next(std::string::const_iterator begin, const std::string::const_iterator &end) override;
        std::string::const_iterator nextEnd(std::string::const_iterator begin, const std::string::const_iterator &end) override;
        size_t beginSize() const noexcept override;

    private:
        CPtr< binaire::IFunction<bool, char> > m_Predicat = defaultvalue;
    };
}
