/**
 * Project Universe
 */


#pragma once

#include "Methode.h"

namespace binaire
{
    template<typename Functor_t>
    class Functor : public _Methode<decltype(&Functor_t::operator())>::Target_t
    {
        public:
        typedef typename _Methode<decltype(&Functor_t::operator())>::Target_t short_t;
        Functor(const Functor_t &str) : short_t(nullptr, &Functor_t::operator()), copy(str)
        {
            this->setObject(&copy);
        }
        private:
        Functor_t copy;
    };
}
