#pragma once

#include <utility>
#include <list>
#include "../MyMemory/CPtr.h"
#include "Parser.h"
#include "ParseRule.h"
#include "Rule/NoRule.h"
namespace binaire
{
    class DynamicParser : public Parser
    {
    public:
        DynamicParser() = default;
        DynamicParser(const StringRef &input) noexcept;
        const StringRef &getOutput() const noexcept override;
        bool next() noexcept override;
        void setOutput(const StringRef &output) noexcept override;
        void setInput(const StringRef &src) noexcept override;
        StringRef getInput() const noexcept override;
        const std::list<CPtr<ParseRule> > &getParseurTab() const noexcept;
        void addParseur(const CPtr<ParseRule> &parse) noexcept;
        std::string getResult() const noexcept override;

    private:
        std::list< CPtr<ParseRule> > m_ParseurTab = defaultvalue;
        std::pair<std::string::const_iterator, std::string::const_iterator> m_Input = defaultvalue;
        std::pair<std::string::const_iterator, std::string::const_iterator> m_Output = defaultvalue;
        NoRule m_default = defaultvalue;
    };
}
