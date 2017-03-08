#pragma once

#include <string>
#include <CPtr.h>
#include <IFunction.h>
#include "../ParseRule.h"
#include <vector>

namespace binaire
{
    class SymboleRule : public ParseRule
    {
    public:
        template<typename... Arg_t>
        SymboleRule( const Arg_t&... arg) noexcept
        {
            m_Symbole.reserve(sizeof...(Arg_t));
            add(arg...);
        }
        std::string::const_iterator next(std::string::const_iterator begin, const std::string::const_iterator &end) override;
        std::string::const_iterator nextEnd(std::string::const_iterator begin, const std::string::const_iterator &) override;
        size_t beginSize() const noexcept override;

    private:
        inline void add(const std::string &str)
        {
            m_Symbole.push_back(str);
        }
        template<typename... Arg_t>
        inline void add(const std::string &str, Arg_t... arg)
        {
            m_Symbole.push_back(str);
            add(arg...);
        }

        std::vector<std::string> m_Symbole = defaultvalue;
        size_t m_CurrentSize = 0;
    };

    class SymboleRuleF : public ParseRule
    {
    public:
        SymboleRuleF(const CPtr< binaire::IFunction<bool, char> > &predicat) noexcept;
        std::string::const_iterator next(std::string::const_iterator begin, const std::string::const_iterator &end) override;
        std::string::const_iterator nextEnd(std::string::const_iterator begin, const std::string::const_iterator &end) override;
        size_t beginSize() const noexcept override;

    private:
        const CPtr< binaire::IFunction<bool, char> > m_perdicat = defaultvalue;
    };
}
