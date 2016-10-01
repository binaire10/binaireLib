#include "../../include/MyParse/StringParse.h"

using namespace std;
using namespace binaire;


StringParse::StringParse(const string &beg, const string &end, const char &EscapeValue) noexcept : SequenceParse(true), m_Begin(beg), m_End(end), m_EscapeValue(EscapeValue)
{}

string::const_iterator StringParse::nextBegin(string::const_iterator begin, const std::pair<string::const_iterator, string::const_iterator> &Str) const
{
    while (begin != Str.second && !isInsideStr1At(Str, begin, m_Begin))
        ++begin;
    return begin;
}

string::const_iterator StringParse::nextEnd(string::const_iterator begin, const std::pair<std::string::const_iterator, std::string::const_iterator> &Str) const
{
    begin += m_Begin.size();

    while (!isInsideStr1At(Str, begin, m_End))
    {
        if(*begin == m_EscapeValue)
        {
            ++begin;
            if(begin == Str.second)
                return begin;
        }
        ++begin;
        if(begin == Str.second)
            return begin;
    }
    return begin + m_End.size();
}

