#pragma once
#include "MetaType.hpp"

namespace binaire
{
    template<typename VType, VType Min, VType Max>
    inline bool isInBorne(const VType &Value)
    {
        return Min<=Value && Value <= Max;
    }

    template<unsigned i, typename CurrentVal, typename... Arg_t>
    struct NType : public NType<i-1, Arg_t...>
    {
        static constexpr typename NType<i-1, Arg_t...>::type &get(CurrentVal, Arg_t... arg)
        { return NType<i-1, Arg_t...>::get(arg...); }
    };

    template<typename CurrentVal, typename... Arg_t>
    struct NType<0, CurrentVal,  Arg_t...>
    {
        typedef CurrentVal type;
        static constexpr CurrentVal &get(type &Input, Arg_t...)
        { return Input; }
    };

    template<typename Out,typename Iter_t>
    Out lenght(const Iter_t &begin, const Iter_t &end)
    {
        return end.base() - begin.base();
    }
}
