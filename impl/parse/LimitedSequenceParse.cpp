#include "../../include/MyParse/LimitedSequenceParse.h"

using namespace std;
using namespace binaire;


LimitedSequenceParse::LimitedSequenceParse(const string &beg, const string &end, const std::list<SequenceParse *> &SequenceAllow) noexcept : SequenceParse(false), m_Begin(beg), m_End(end), m_SequenceurList(SequenceAllow)
{}

string::const_iterator LimitedSequenceParse::nextBegin(string::const_iterator begin, const std::pair<string::const_iterator, string::const_iterator> &Str) const
{
    while (begin != Str.second && !isInsideStr1At(Str, begin, m_Begin))
        ++begin;
    return begin;
}

string::const_iterator LimitedSequenceParse::nextEnd(string::const_iterator offset, const std::pair<std::string::const_iterator, std::string::const_iterator> &Str) const
{
    offset += m_Begin.size();

    const SequenceParse *currentLog;
    string::const_iterator near, nearValue;

    while (offset != Str.second)
    {
        nearValue = offset;
        near = Str.second;
        currentLog = nullptr;


        if(m_SequenceurList.size() != 0)
        {
            for(const SequenceParse * const &Seq : m_SequenceurList)
            {
                string::const_iterator nearSeq = Seq->nextBegin(offset, Str);
                if(nearSeq <= near)
                {
                    near = nearSeq;
                    currentLog = Seq;
                }
            }
        }

        while (nearValue != Str.second && !isInsideStr1At(Str, nearValue, m_End))
            ++nearValue;

        if(nearValue <= near)
            return nearValue + m_End.size();

        if(nearValue == Str.second)
            return Str.second;

        offset = currentLog->nextEnd(near, Str);
    }

    return offset;
}

std::list<LexicalParseur::SequenceParse *> &LimitedSequenceParse::SequenceurList() noexcept
{
    return m_SequenceurList;
}


const std::list<LexicalParseur::SequenceParse *> &LimitedSequenceParse::SequenceurList() const noexcept
{
    return m_SequenceurList;
}
