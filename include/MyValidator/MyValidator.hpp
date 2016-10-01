#pragma once
#include "MyPredicat.hpp"

namespace binaire
{
    template<typename Validator, typename... Validators>
    struct find_in
    {
        template<typename X>
        static inline bool isTrue(const X &value, const Validator &predicat, Validators... arg)
        {
            return predicat(value) || find_in<Validators...>::isTrue(value, arg...);
        }
    };

    template<typename Validator>
    struct find_in<Validator>
    {
        template<typename X>
        static inline bool isTrue(const X &value, const Validator &predicat)
        {
            return predicat(value);
        }
    };

    template<bool(&Func)(const char&), typename Iter_t>
    bool allSame(Iter_t begin, const Iter_t &end)
    {
        while(begin!=end && Func(*begin)) ++begin;
        return begin==end;
    }

    template<bool(&Func)(const char&), typename Iter_t>
    bool hasInto(Iter_t begin, const Iter_t &end)
    {
        while(begin!=end && !Func(*begin)) ++begin;
        return begin!=end;
    }

    template<typename Iter_t, typename... Validator>
    bool hasInto(Iter_t begin, const Iter_t &end, Validator... vald)
    {
        while(begin!=end && !find_in<Validator...>::isTrue(*begin, vald...)) ++begin;
        return begin!=end;
    }

    template<typename Iter_t>
    bool isNumber(Iter_t begin, const Iter_t &end)
    {
        while(begin!=end && isNum(*begin)) ++begin;
        return begin==end;
    }

    template<typename Iter_t>
    bool isDecimalNumber(Iter_t begin, const Iter_t &end)
    {
        if(begin!=end && *begin == '-')
            ++begin;
        while(begin!=end && isNum(*begin)) ++begin;
        if(begin!=end && *begin == '.')
            ++begin;
        while(begin!=end && isNum(*begin)) ++begin;
        return begin==end;
    }

    template<typename Iter_t>
    bool hasNumber(Iter_t begin, const Iter_t &end)
    {
        while(begin!=end && !isNum(*begin)) ++begin;
        return begin!=end;
    }

    template<typename Iter_t>
    bool isAlpha(Iter_t begin, const Iter_t &end)
    {
        while(begin!=end && isAlpha(*begin)) ++begin;
        return begin==end;
    }
}
