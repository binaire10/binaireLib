#pragma once

#include "IFunction.h"

namespace binaire
{
    template<typename Return_t, typename... Arg_t>
    struct MyCaller
    {
        template<typename X,  typename... Last>
        static inline Return_t call(X Func, Arg_t... arg, Last...)
        {
            return Func(arg...);
        }
    };

    template<typename... Arg_t>
    struct MyCaller<void, Arg_t...>
    {
        template<typename X,  typename... Last>
        static inline void call(X Func, Arg_t... arg, Last...)
        {
            Func(arg...);
        }
    };

    template<typename Return_t, typename... Arg_t>
    struct MyCaller< Return_t (*)(Arg_t...) > : public MyCaller<Return_t, Arg_t...>
    {};

    template<typename Return_t, typename... Arg_t>
    struct MyCaller< IFunction<Return_t, Arg_t...> >  : public MyCaller<Return_t, Arg_t...>
    {};

    template<typename Function_t, typename... Last>
    inline void call(Function_t Func, Last... arg)
    {
        MyCaller<Function_t>::call(Func, arg...);
    }

    template<typename Function_t, typename Out_t, typename... Last>
    inline Out_t call(Function_t Func, Last... arg)
    {
        return MyCaller<Function_t>::call(Func, arg...);
    }

    template<typename...>
    class FunctionAdapter;

    template<typename Result_t, typename... Arg_t, typename... Arg2_t>
    class FunctionAdapter<IFunction<Result_t, Arg_t...>, IFunction<Result_t, Arg2_t...> > : public IFunction<Result_t, Arg_t...>
    {
    public:
        FunctionAdapter(IFunction<Result_t, Arg2_t...> *func) : m_func(func)
        {}

        Result_t call(Arg_t... arguments) const override
        {
            return _call(m_func, arguments...);
        }

    private:
        template<typename... etc_t>
        Result_t _call(Arg2_t... arg, etc_t...) const
        {
            return m_func->call(arg...);
        }
        IFunction<Result_t, Arg2_t...> *m_func;
    };

    template<typename... Arg_t, typename... Arg2_t>
    class FunctionAdapter<IFunction<void, Arg_t...>, IFunction<void, Arg2_t...> > : public IFunction<void, Arg_t...>
    {
    public:
        FunctionAdapter(IFunction<void, Arg2_t...> *func) : m_func(func)
        {}

        void call(Arg_t... arguments) const override
        {
            _call(m_func, arguments...);
        }

    private:
        template<typename... etc_t>
        void _call(Arg2_t... arg, etc_t...) const
        {
            m_func->call(arg...);
        }

        IFunction<void, Arg2_t...> *m_func;
    };
}
