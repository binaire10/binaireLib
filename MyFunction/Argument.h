/**
 * Project Universe
 */

#pragma once
#include "IFunction.h"
#include "MetaTemplate/MetaType.hpp"

namespace binaire
{
    template<typename... >
    class Argument;

    template<typename X, typename... Arg_t >
    class Argument<X, Arg_t...> : private Argument<Arg_t...>
    {
    private:
        typedef typename binaire::remove_all_access<X>::type Value_t;
    public:
        Argument() = default;
        template<typename... rest_t>
        Argument(Value_t value, rest_t&&... arg) : Argument<Arg_t...>(arg...)
        {
            m_value = value;
        }

        template<typename Func_t>
        void call(Func_t &func)
        {
            Argument<Arg_t...>::_call(func, m_value);
        }

        template<typename Func_t, typename Result_t>
        Result_t call(Func_t &func)
        {
            return Argument<Arg_t...>::_call(func, m_value);
        }

        template<typename... rest_t>
        void setValue(Value_t value, rest_t&&... arg)
        {
            Argument<Arg_t...>::setValue(arg...);
            m_value = value;
        }

    protected:
        template<typename Func_t, typename... arg_t>
        inline void _call(Func_t &func, arg_t... arg)
        {
            Argument<Arg_t...>::_call(func, arg..., m_value);
        }

        template<typename Func_t, typename Result_t, typename... arg_t>
        inline Result_t _call(Func_t &func, arg_t... arg)
        {
            return Argument<Arg_t...>::_call(func, arg..., m_value);
        }

    private:
        Value_t m_value;
    };

    template<>
    class Argument<>
    {
    public:
        Argument() = default;
        template<typename Func_t, typename... arg_t>
        inline void call(Func_t &func, arg_t... arg)
        {
            func(arg...);
        }

        template<typename Func_t, typename Result_t, typename... arg_t>
        inline Result_t call(Func_t &func, arg_t... arg)
        {
            return func(arg...);
        }

        void setValue()
        {}

    protected:
        template<typename Func_t, typename... arg_t>
        inline void _call(Func_t &func, arg_t... arg)
        {
            func(arg...);
        }

        template<typename Func_t, typename Result_t, typename... arg_t>
        inline Result_t _call(Func_t &func, arg_t... arg)
        {
            return func(arg...);
        }

    };
}
