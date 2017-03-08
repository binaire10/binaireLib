#include "WordRule.h"

using namespace binaire;

WordRule::WordRule(const CPtr<IFunction<bool, char> > &predicat) noexcept : m_Predicat(predicat)
{}

std::string::const_iterator WordRule::next(std::string::const_iterator begin, const std::string::const_iterator &end)
{
    std::string::const_iterator offset(begin);
    while(offset != end && !m_Predicat->call(*offset))
        ++offset;
    return offset;
}

std::string::const_iterator WordRule::nextEnd(std::string::const_iterator begin, const std::string::const_iterator &end)
{
    while(begin != end && m_Predicat->call(*begin))
        ++begin;
    return begin;
}

size_t WordRule::beginSize() const noexcept
{
    return 1;
}
