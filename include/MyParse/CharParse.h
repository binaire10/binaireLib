#pragma once
#include "../binairelib_global.h"
#include "LexicalParseur.h"

namespace binaire
{
    class BINAIRELIBSHARED_EXPORT CharParse : public LexicalParseur::SequenceParse
    {
    public:
        CharParse(const std::string &Uniq) noexcept;
        virtual ~CharParse() = default;

    protected:
        std::string m_UniqChar;

        // SequenceParse interface
    public:
        std::string::const_iterator nextBegin(std::string::const_iterator, const std::pair<std::string::const_iterator, std::string::const_iterator> &) const override;
        std::string::const_iterator nextEnd(std::string::const_iterator, const std::pair<std::string::const_iterator, std::string::const_iterator> &) const override;
        const std::string &UniqChar() const noexcept;
        std::string &UniqChar() noexcept;
    };
}
