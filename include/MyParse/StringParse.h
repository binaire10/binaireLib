#pragma once
#include "../binairelib_global.h"
#include "LexicalParseur.h"

namespace binaire
{
    class BINAIRELIBSHARED_EXPORT StringParse : public LexicalParseur::SequenceParse
    {
    public:
        StringParse(const std::string &beg, const std::string &end, const char &EscapeValue) noexcept;
        virtual ~StringParse() = default;

    protected:
        const std::string m_Begin;
        const std::string m_End;
        char m_EscapeValue;

        // SequenceParse interface
    public:
        std::string::const_iterator nextBegin(std::string::const_iterator, const std::pair<std::string::const_iterator, std::string::const_iterator> &) const override;
        std::string::const_iterator nextEnd(std::string::const_iterator, const std::pair<std::string::const_iterator, std::string::const_iterator> &) const override;
    };
}
