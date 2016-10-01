#pragma once
#include "../binairelib_global.h"
#include "LexicalParseur.h"
#include <cassert>

namespace binaire
{
    class BINAIRELIBSHARED_EXPORT SymboleParse : public LexicalParseur::SequenceParse
    {
    public:
        SymboleParse(const unsigned &size, const std::list<std::string> & = std::list<std::string>()) noexcept;
        virtual ~SymboleParse() = default;

    protected:
        std::list<std::string> m_UniqSymbole;
        unsigned m_Found;
        unsigned m_size;

        // SequenceParse interface
    public:
        std::string::const_iterator nextBegin(std::string::const_iterator begin, const std::pair<std::string::const_iterator, std::string::const_iterator> &Str) const override;

        std::string::const_iterator nextEnd(std::string::const_iterator offset, const std::pair<std::string::const_iterator, std::string::const_iterator> &) const override;

        const std::list<std::string> &UniqSymbole() const noexcept;

        std::list<std::string> &UniqSymbole() noexcept;
    };
}
