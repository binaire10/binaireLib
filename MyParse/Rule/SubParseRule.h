#pragma once

#include <list>
#include <algorithm>
#include "../../MyMemory/CPtr.h"
#include "../ParseRule.h"
#include "StringRule.h"

namespace binaire
{
    template<typename LikeRule>
    class SubParseRule : public ParseRule
    {
    public:
        struct EndContext
        {
            ParseRule *selectedParse = nullptr;
            void *SubContext = nullptr;
            std::string::const_iterator nearRule = defaultvalue;
            std::string::const_iterator iPos = defaultvalue;
            std::string::const_iterator iWPos = defaultvalue;
        };

        template<typename... Arg_t>
        SubParseRule(Arg_t... arg) : m_Parseur(arg...)
        {}

        SubParseRule(const SubParseRule &) = default;
        SubParseRule &operator =(const SubParseRule &) = default;

        std::string::const_iterator next(std::string::const_iterator begin, const std::string::const_iterator &end) override
        {
            std::string::const_iterator result(m_Parseur.next(begin, end));
            return result;
        }

        std::string::const_iterator nextEnd(std::string::const_iterator begin, const std::string::const_iterator &end) override
        {
            begin += beginSize();
            if(begin == end)
                return end;
            ParseRule *selectedParse;

            do {
                selectedParse = &m_Parseur;
                std::string::const_iterator nearRule = end;
                for(CPtr<ParseRule> &iParseRule : m_ParseurTab)
                {
                    std::string::const_iterator iPos = iParseRule->next(begin, end);
                    if(nearRule < iPos)
                        continue;
                    selectedParse = iParseRule.getPtr();
                    nearRule = iPos;
                }
                std::string::const_iterator iPos = m_Parseur.nextEnd(nearRule, end);
                std::string::const_iterator iWPos = selectedParse->nextEnd(nearRule + selectedParse->beginSize(), end);

                if(iWPos < iPos || selectedParse == this)
                {
                    begin = iWPos;
                    continue;
                }
                break;
            } while(begin != end && selectedParse != &m_Parseur);

            return m_Parseur.nextEnd(begin, end);
        }

        size_t beginSize() const noexcept
        {
            return m_Parseur.beginSize();
        }

        const std::list<CPtr<ParseRule> > &getParseurTab() const noexcept
        {
            return m_ParseurTab;
        }
        void addParseur(const CPtr<ParseRule> &parse) noexcept
        {
            m_ParseurTab.push_back(parse);
        }

        void addParseur(const std::list< CPtr<ParseRule> > &parse) noexcept
        {
            m_ParseurTab.insert(m_ParseurTab.end(), parse.begin(), parse.end());
        }

    private:
        LikeRule m_Parseur;
        std::list< CPtr<ParseRule> > m_ParseurTab = defaultvalue;
        size_t m_Len = 0;
        // EndContext saveContex;
    };
}
