#include "../../include/MyParse/SymboleParse.h"

using namespace std;
using namespace binaire;

SymboleParse::SymboleParse(const unsigned &size, const std::list<string> &value) noexcept : SequenceParse(true), m_UniqSymbole(value), m_Found(), m_size(size)
{}

string::const_iterator SymboleParse::nextBegin(string::const_iterator begin, const std::pair<std::string::const_iterator, std::string::const_iterator> &Str) const
{
    while(begin != Str.second)
    {
        for(const std::string &Value : m_UniqSymbole)
        {
            assert(Value.size() == m_size);
            if(isInsideStr1At(Str, begin, Value))
                return begin;
        }
        ++begin;
    }
    return begin;
}

string::const_iterator SymboleParse::nextEnd(string::const_iterator offset, const std::pair<std::string::const_iterator, std::string::const_iterator> &) const
{return offset + m_size;}

const std::list<string> &SymboleParse::UniqSymbole() const noexcept
{return m_UniqSymbole;}

std::list<string> &SymboleParse::UniqSymbole() noexcept
{return m_UniqSymbole;}
