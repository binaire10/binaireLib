#include "DynamicParser.h"

using namespace std;
using namespace binaire;

DynamicParser::DynamicParser(const StringRef &input) noexcept : m_ParseurTab(), m_Input(input), m_Output(input.first, input.first)
{}

const StringRef &DynamicParser::getOutput() const noexcept
{
    return m_Output;
}

bool DynamicParser::next() noexcept
{
    if(m_Input.first == m_Input.second)
        return false;

    ParseRule *selectedParse(&m_default);
    string::const_iterator nearRule = m_Input.second;
    for(CPtr<ParseRule> &iParseRule : m_ParseurTab)
    {
        string::const_iterator iPos = iParseRule->next(m_Input.first, m_Input.second);
        if(nearRule < iPos)
            continue;
        selectedParse = iParseRule.getPtr();
        nearRule = iPos;
    }

    if(nearRule <  m_default.next(m_Input.first, m_Input.second))
    {
        m_Output.first = nearRule;
        m_Input.first = m_Output.second = selectedParse->nextEnd(nearRule + selectedParse->beginSize(), m_Input.second);

        return m_Output.first != m_Output.second;
    }

    m_Output.first = m_default.next(m_Input.first, m_Input.second);
    m_Input.first = m_Output.second = m_default.nextEnd(m_Output.first + m_default.beginSize(), m_Input.second);

    return m_Output.first != m_Output.second;
}

void DynamicParser::setOutput(const StringRef &output) noexcept
{m_Output = output;}

void DynamicParser::setInput(const StringRef &input) noexcept
{
    m_Input = input;
    m_Output = {input.first, input.first};
}

void DynamicParser::addParseur(const CPtr<ParseRule> &parse) noexcept
{m_ParseurTab.push_back(parse);}

string DynamicParser::getResult() const noexcept
{
    return string(m_Output.first, m_Output.second);
}

StringRef DynamicParser::getInput() const noexcept
{
    return m_Input;
}

const std::list<CPtr<ParseRule> > &DynamicParser::getParseurTab() const noexcept
{
    return m_ParseurTab;
}
