#pragma once
#include "../class/TMember.hpp"

namespace binaire
{
    template<typename Fonctor_t>
    class TFonctor : public TMember<decltype(&Fonctor_t::operator())>
    {
    public:
    protected:
        typedef TMember<decltype(&Fonctor_t::operator())> Parent_t;
            Fonctor_t m_Fonctor;
    public:
        TFonctor(const Fonctor_t &Lambda) noexcept : Parent_t(nullptr, &Fonctor_t::operator()), m_Fonctor(Lambda)
        {
            this->setBaseObject(&m_Fonctor);
        }
    };
}
