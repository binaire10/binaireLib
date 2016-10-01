#include "../../include/MyParse/WordParse.h"
#include "../../include/MyValidator/MyPredicat.hpp"

using namespace std;
using namespace binaire;

WordParse::WordParse() noexcept : SequenceParse(true), m_IsWord(IsInWord), m_IsSymbole(IsSymbol)
{}

WordParse::WordParse(WordParse::Predica_t *WordDef, WordParse::Predica_t *SymboleDef) noexcept : SequenceParse(true), m_IsWord(WordDef), m_IsSymbole(SymboleDef)
{

}

string::const_iterator WordParse::nextBegin(string::const_iterator begin, const std::pair<std::string::const_iterator, std::string::const_iterator> &Str) const
{
    if(m_IsSymbole(*begin))
        return begin;
    while (begin != Str.second && !(m_IsWord(*begin) || m_IsSymbole(*begin)))
    {
        if(m_IsSymbole(*begin))
            return begin+1;
        ++begin;
    }
    return begin;
}

string::const_iterator WordParse::nextEnd(string::const_iterator begin, const std::pair<std::string::const_iterator, std::string::const_iterator> &Str) const
{
    if(m_IsSymbole(*begin))
        return begin+1;

    while (begin != Str.second && m_IsWord(*begin))
        ++begin;
    return begin;
}
