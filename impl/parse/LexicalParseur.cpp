#include "../../include/MyParse/LexicalParseur.h"
#include "../../include/MyParse/WordParse.h"
#include "../../include/MetaTemplate/MetaReturn.hpp"
#include <algorithm>
#include <stdexcept>

using namespace std;
using namespace binaire;

LexicalParseur::SequenceParse::SequenceParse(const bool &isIterable) noexcept : m_isIterable(isIterable)
{}

LexicalParseur::LexicalParseur(string &Src, LexicalParseur::SequenceParse *Basic) noexcept : m_SequenceurList(), m_Source(), m_privBegin(), m_offset()
{
    m_SequenceurList.push_back(Basic);
    setSource(Src);
}

LexicalParseur::LexicalParseur(const std::list<LexicalParseur::SequenceParse *> &list) noexcept : m_SequenceurList(list), m_Source(), m_privBegin(), m_offset()
{}


void LexicalParseur::Next() noexcept
{
    if(m_SequenceurList.size()==0 || AtEnd())
        return;

    const SequenceParse *currentLog(nullptr);
    string::const_iterator nearValue(m_Source.second), newValue;

    for(const SequenceParse * const &Seq : m_SequenceurList)
    {
        newValue = Seq->nextBegin(m_offset, m_Source);
        if(newValue <= nearValue)
        {
            nearValue = newValue;
            currentLog = Seq;
        }
    }

    if(nearValue == m_Source.second || currentLog == nullptr)
    {
        m_offset = m_Source.second;
        m_privBegin = m_Source.second;
        return;
    }

    m_offset = currentLog->nextEnd(nearValue, m_Source);
    m_privBegin = nearValue;
}

pair<string::const_iterator, string::const_iterator> LexicalParseur::getCurrent() noexcept
{
    if(m_offset == m_Source.first)
        Next();
    return pair<string::const_iterator, string::const_iterator>(m_privBegin, m_offset);
}

pair<string::const_iterator, string::const_iterator> LexicalParseur::getSource() noexcept
{
    return m_Source;
}

bool LexicalParseur::LastWord() noexcept
{
    if(m_SequenceurList.size()==0 || m_offset == m_Source.second)
        return true;

    const SequenceParse *currentLog = *m_SequenceurList.begin();
    string::const_iterator nearValue(currentLog->nextBegin(m_offset, m_Source)), it;

    for(const SequenceParse * const &Seq : m_SequenceurList)
    {
        it = Seq->nextBegin(m_offset, m_Source);
        if(it<nearValue)
            nearValue = it;
    }
    return nearValue ==  m_Source.second;
}

bool LexicalParseur::AtEnd() const noexcept
{
    return m_offset == m_Source.second && m_privBegin == m_Source.second;
}

void LexicalParseur::setSource(const string &Source) noexcept
{
    m_Source.first = Source.begin();
    m_Source.second = Source.end();
    m_offset = m_Source.first;
    m_privBegin = m_Source.first;
}

void LexicalParseur::setSource(const std::pair<string::const_iterator, string::const_iterator> &ping) noexcept
{
    m_Source = ping;
    m_offset = m_Source.first;
    m_privBegin = m_Source.first;
}

void LexicalParseur::setSource(const string::const_iterator &beg, const string::const_iterator &end) noexcept
{
    m_Source.first = beg;
    m_Source.second = end;
    m_offset = m_Source.first;
    m_privBegin = m_Source.first;
}

void LexicalParseur::setOutput(const string::const_iterator &beg, const string::const_iterator &end)
{
    if(!isInside(m_Source.first, m_Source.second, beg))
        throw std::runtime_error("No Input");

    if(!isInside(m_Source.first, m_Source.second, end))
        throw std::runtime_error("No Input");

    m_offset = beg;
    m_privBegin = end;
}

void LexicalParseur::setOutput(const std::pair<string::const_iterator, string::const_iterator> &i)
{
    if(!isInside(m_Source.first, m_Source.second, i.first))
        throw std::runtime_error("No Input");

    if(!isInside(m_Source.first, m_Source.second, i.second))
        throw std::runtime_error("No Input");

    m_offset = i.second;
    m_privBegin = i.first;
}

std::list<LexicalParseur::SequenceParse *> &LexicalParseur::SequenceurList() noexcept
{
    return m_SequenceurList;
}


const std::list<LexicalParseur::SequenceParse *> &LexicalParseur::SequenceurList() const noexcept
{
    return m_SequenceurList;
}

bool LexicalParseur::SequenceParse::isInsideStr1At(const std::pair<string::const_iterator, string::const_iterator> &Str1, string::const_iterator At, const string &Str2) noexcept
{
    string::const_iterator i = Str2.begin();
    while(At != Str1.second && i != Str2.end())
    {
        if(*At != *i)
            return false;
        ++At;
        ++i;
    }
    return i==Str2.end();
}

bool LexicalParseur::SequenceParse::isInsideStr1At(const std::pair<string::const_iterator, string::const_iterator> &Str1, const string &Str2) noexcept
{
    string::const_iterator i = Str2.begin();
    string::const_iterator At = Str1.first;
    while(At != Str1.second && i != Str2.end())
    {
        if(*At != *i)
            return false;
        ++At;
        ++i;
    }
    return i==Str2.end();
}

bool LexicalParseur::SequenceParse::equal(const std::pair<string::const_iterator, string::const_iterator> &Str1, const string &Str2) noexcept
{
    if(binaire::lenght<unsigned>(Str1.first, Str1.second) != Str2.size())
        return false;
    return isInsideStr1At(Str1, Str2);
}

bool LexicalParseur::SequenceParse::equal(const std::pair<string::const_iterator, string::const_iterator> &Str1, const std::pair<string::const_iterator, string::const_iterator> &Str2) noexcept
{
    if(binaire::lenght<unsigned>(Str1.first, Str1.second) !=binaire::lenght<unsigned>(Str2.first, Str2.second))
        return false;

    string::const_iterator i1 = Str1.first;
    string::const_iterator i2 = Str2.first;
    while(i1 != Str1.second && i2 != Str2.second && *i1 == *i2)
    {
        ++i1;
        ++i2;
    }

    return i1 == Str1.second && i2 == Str2.second;
}

