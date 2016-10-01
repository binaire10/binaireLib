#pragma once
#include "../binairelib_global.h"
#include "LexicalParseur.h"

namespace binaire
{
    class BINAIRELIBSHARED_EXPORT LimitedSequenceParse : public LexicalParseur::SequenceParse
    {
    public:
        LimitedSequenceParse(const std::string &beg, const std::string &end, const std::list<SequenceParse *> &SequenceAllow = std::list<SequenceParse *>()) noexcept;
        virtual ~LimitedSequenceParse() = default;

    protected:
        const std::string m_Begin;
        const std::string m_End;
        std::list<SequenceParse *> m_SequenceurList;

        // SequenceParse interface
    public:
        std::string::const_iterator nextBegin(std::string::const_iterator, const std::pair<std::string::const_iterator, std::string::const_iterator> &) const override;
        std::string::const_iterator nextEnd(std::string::const_iterator, const std::pair<std::string::const_iterator, std::string::const_iterator> &) const override;
        std::list<SequenceParse *> &SequenceurList() noexcept;
        const std::list<SequenceParse *> &SequenceurList() const noexcept;
    };
}
