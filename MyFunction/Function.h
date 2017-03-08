/**
 * Project Universe
 */

#pragma once

#include "IFunction.h"


namespace binaire
{
    template<typename Result_t , typename... Args_t >
    class Function : public IFunction<Result_t, Args_t...>
    {
    public:
        typedef Result_t (*Func_t)(Args_t...);
        typedef IFunction<Result_t, Args_t...> Parent_t;
        Function(Func_t func) : m_func(func)
        {}

        Result_t call(Args_t... arguments) const final
        {
            return m_func(arguments...);
        }
    private:
        Func_t m_func;
    };

    template<typename... Args_t >
    class Function<void, Args_t...> : public IFunction<void, Args_t...>
    {
    public:
        typedef IFunction<void, Args_t...> Parent_t;
        typedef void (*Func_t)(Args_t...);
        Function(Func_t func) : m_func(func)
        {}

        void call(Args_t... arguments) const final
        {m_func(arguments...);}
    private:
        const Func_t m_func;
    };

    template<typename Result_t, typename... Args_t >
    class Function<Result_t(*)(Args_t...)> : public Function<Result_t, Args_t...>
    {};
}
