#pragma once

#include <string>
#include "../ParseRule.h"

namespace binaire
{
    template<char beginChar , char endChar , char prtc>
    class StringRuleT: public ParseRule
    {
    public:
        std::string::const_iterator next(std::string::const_iterator begin, const std::string::const_iterator &end) override
        {
            while(begin != end && *begin != beginChar)
                ++begin;

            return begin;
        }

        std::string::const_iterator nextEnd(std::string::const_iterator begin, const std::string::const_iterator &end) override
        {
            while(begin != end && *begin != endChar)
            {
                if(*begin == prtc)
                    ++begin;
                if(begin != end)
                    ++begin;
            }
            return begin != end?begin+1:end;
        }
        size_t beginSize() const noexcept override
        {
            return 1;
        }
    };

    class StringRule: public ParseRule
    {
    public:
        StringRule(char beginChar, char endChar, char prtc) noexcept;
        std::string::const_iterator next(std::string::const_iterator begin, const std::string::const_iterator &end) override;
        std::string::const_iterator nextEnd(std::string::const_iterator begin, const std::string::const_iterator &end) override;
        size_t beginSize() const noexcept override;

    private:
        char m_beginChar = defaultvalue;
        char m_endChar = defaultvalue;
        char m_prtc = defaultvalue;
    };
}
