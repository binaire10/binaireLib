#ifndef TOOL
#define TOOL
#include <vector>
#include <map>
#include "smarvar.h"

namespace binaire
{
    typedef unsigned uint_t;
    namespace expiremental
    {
        template<typename X>
        class vectorRef : public std::vector< SmartReference<X> >
        {};

        template<typename Y>
        vectorRef<Y> smartRefOf(std::vector<Y> &Tab, const size_t &width, const size_t &begin=0)
        {
            const size_t end(begin+width);
            typename std::vector<Y>::iterator Iter;
            vectorRef<Y> tab;
            tab.resize(width);

            Iter = Tab.begin() + begin;
            for(size_t i(begin) ; i<end ; ++i, ++Iter)
                tab[i-begin].set(*Iter);
            return tab;
        }
    }
}

#endif // TOOL
