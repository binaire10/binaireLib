#pragma once
#include "../binairelib_global.h"
#include <string>
#include <list>
#include <utility>
#include "../MyFunction/IFunction.h"
#include "../MySystem/Input/IInput.h"
#include "../MyMemory/SmartPtr.hpp"


namespace binaire
{
    class BINAIRELIBSHARED_EXPORT LexicalParseur
    {
    public:
        typedef unsigned long long size_t;

        class BINAIRELIBSHARED_EXPORT SequenceParse
        {
        public:
            SequenceParse(const bool &isIterable) noexcept;
            virtual ~SequenceParse() = default;

            virtual std::string::const_iterator nextBegin(std::string::const_iterator, const std::pair<std::string::const_iterator, std::string::const_iterator> &) const = 0;
            virtual std::string::const_iterator nextEnd(std::string::const_iterator, const std::pair<std::string::const_iterator, std::string::const_iterator> &) const = 0;
            static bool isInsideStr1At(const std::pair<std::string::const_iterator, std::string::const_iterator> &Str1, std::string::const_iterator At, const std::string &Str2) noexcept;
            static bool isInsideStr1At(const std::pair<std::string::const_iterator, std::string::const_iterator> &Str1, const std::string &Str2) noexcept;
            static bool equal(const std::pair<std::string::const_iterator, std::string::const_iterator> &Str1, const std::string &Str2) noexcept;
            static bool equal(const std::pair<std::string::const_iterator, std::string::const_iterator> &Str1, const std::pair<std::string::const_iterator, std::string::const_iterator> &Str2) noexcept;
        protected:
            bool m_isIterable;
        };

        LexicalParseur(std::string &Src, SequenceParse *Basic) noexcept;
        LexicalParseur(const std::list<SequenceParse *> &) noexcept;
        void Next() noexcept;
        std::pair<std::string::const_iterator, std::string::const_iterator> getCurrent() noexcept;
        std::pair<std::string::const_iterator, std::string::const_iterator> getSource() noexcept;
        bool LastWord() noexcept;
        bool AtEnd() const noexcept;
        void setSource(const std::string &Source) noexcept;
        void setSource(const std::pair<std::string::const_iterator, std::string::const_iterator> &) noexcept;
        void setSource(const std::string::const_iterator &beg, const std::string::const_iterator &end) noexcept;

        void setOutput(const std::string::const_iterator &beg, const std::string::const_iterator &end);
        void setOutput(const std::pair<std::string::const_iterator, std::string::const_iterator> &);

        std::list<SequenceParse *> &SequenceurList() noexcept;
        const std::list<SequenceParse *> &SequenceurList() const noexcept;

    private:
        std::list<SequenceParse *> m_SequenceurList = std::list<SequenceParse *>();
        std::pair<std::string::const_iterator, std::string::const_iterator> m_Source;
        std::string::const_iterator m_privBegin;
        std::string::const_iterator m_offset;
    };

    inline std::string buildString(const std::pair<std::string::const_iterator, std::string::const_iterator> &str)
    {
        if(str.first >= str.second)
            return std::string();
        return std::string(str.first, str.second);
    }

    template<typename Iter_t, typename Iter2_t>
    bool isInside(Iter_t begin, const Iter_t &end, const Iter2_t &target)
    {
        while(begin != end)
        {
            if(begin == target)
                return true;
            ++begin;
        }
        return target == begin;
    }

}
