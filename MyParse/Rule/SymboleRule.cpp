#include "SymboleRule.h"

using namespace binaire;

std::string::const_iterator SymboleRule::next(std::string::const_iterator begin, const std::string::const_iterator &end)
{
    const std::string::const_iterator start(begin);

    while(begin != end)
    {
        for(const std::string &iLiteral : m_Symbole)
            if(existAt(begin, end, iLiteral.begin(), iLiteral.end()))
            {
                m_CurrentSize = iLiteral.size();
                return begin;
            }
        ++begin;
    }
    return end;
}

std::string::const_iterator SymboleRule::nextEnd(std::string::const_iterator begin, const std::string::const_iterator &)
{
    return begin + m_CurrentSize;
}

size_t SymboleRule::beginSize() const noexcept
{
    return 0;
}

SymboleRuleF::SymboleRuleF(const CPtr<IFunction<bool, char> > &predicat) noexcept : m_perdicat(predicat)
{}

std::string::const_iterator SymboleRuleF::next(std::string::const_iterator begin, const std::string::const_iterator &end)
{
    while(begin != end && !(m_perdicat->call(*begin)))
    {
        ++begin;
    }
    return begin;
}

std::string::const_iterator SymboleRuleF::nextEnd(std::string::const_iterator begin, const std::string::const_iterator &)
{
    return begin;
}

size_t SymboleRuleF::beginSize() const noexcept
{
    return 1;
}
