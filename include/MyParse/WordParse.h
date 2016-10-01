#pragma once
#include "../binairelib_global.h"
#include <string>
#include "LexicalParseur.h"

namespace binaire
{
    class BINAIRELIBSHARED_EXPORT WordParse : public LexicalParseur::SequenceParse
    {
    public:
        typedef bool(Predica_t)(const char&);
        WordParse() noexcept;
        WordParse(Predica_t *WordDef, Predica_t *SymboleDef) noexcept;
        // SequenceParse interface

        std::string::const_iterator nextBegin(std::string::const_iterator begin, const std::pair<std::string::const_iterator, std::string::const_iterator> &Str) const override;
        std::string::const_iterator nextEnd(std::string::const_iterator begin, const std::pair<std::string::const_iterator, std::string::const_iterator> &Str) const override;
    private:
        Predica_t *m_IsWord;
        Predica_t *m_IsSymbole;
    };
}
