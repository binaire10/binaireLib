#include "../../include/MyParse/CharParse.h"
#include <algorithm>

using namespace std;
using namespace binaire;

CharParse::CharParse(const string &Uniq) noexcept : LexicalParseur::SequenceParse(true), m_UniqChar(Uniq)
{

}

string &CharParse::UniqChar() noexcept
{
    return m_UniqChar;
}

string::const_iterator CharParse::nextBegin(string::const_iterator begin, const std::pair<std::string::const_iterator, std::string::const_iterator> &Str) const
{
    while(begin != Str.second && std::find(m_UniqChar.cbegin(), m_UniqChar.cend(), *begin)==m_UniqChar.cend())
    {
        ++begin;
    }
    return begin;
}

string::const_iterator CharParse::nextEnd(string::const_iterator begin, const std::pair<std::string::const_iterator, std::string::const_iterator> &) const
{
    return begin + 1;
}

const string &CharParse::UniqChar() const noexcept
{
    return m_UniqChar;
}
