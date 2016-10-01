#pragma once
#include "../MyFunction/IFunction.hpp"

namespace binaire
{
    namespace System
    {
        namespace Call
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
                return MyCaller<Function_t>::call(Func, arg...);
            }

            template<typename Function_t, typename Out_t, typename... Last>
            inline Out_t call(Function_t Func, Last... arg)
            {
                return MyCaller<Function_t>::call(Func, arg...);
            }
        }
    }
}
