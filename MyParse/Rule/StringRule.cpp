#include "StringRule.h"

using namespace binaire;

StringRule::StringRule(char beginChar, char endChar, char prtc) noexcept : m_beginChar(beginChar), m_endChar(endChar), m_prtc(prtc)
{}

std::string::const_iterator StringRule::nextEnd(std::string::const_iterator begin, const std::string::const_iterator &end)
{
    while(begin != end && *begin != m_endChar)
    {
        if(*begin == m_prtc)
            ++begin;
        if(begin != end)
            ++begin;
    }
    return begin != end?begin+1:end;
}

size_t StringRule::beginSize() const noexcept
{
    return 1;
}

std::string::const_iterator StringRule::next(std::string::const_iterator begin, const std::string::const_iterator &end)
{
    while(begin != end && *begin != m_beginChar)
        ++begin;
    return begin;
}
