#pragma once

#include "Function.h"
#include "Methode.h"
#include "Functor.h"
#include <CPtr.h>

namespace binaire
{
    template<typename Object_t, typename Memeber_t>
    CPtr< typename _Methode<Memeber_t>::Target_t > make_FunctionPtr(Object_t Obj, Memeber_t member)
    {
        return CPtr< typename _Methode<Memeber_t>::Target_t >::instantiate(Obj, member);
    }

    template<typename Out_t, typename... Arg_t>
    CPtr< IFunction<Out_t, Arg_t...> > make_FunctionPtr(Out_t(*function)(Arg_t...))
    {
        return CPtr< Function<Out_t, Arg_t...> >::instantiate(function);
    }

    template<typename Functor_t>
    // auto is better becausse if I say the return type is CPtr<typename Functor<Functor_t>::Parent_t> the compiler use this definition if the parameter is a function
    auto make_FunctionPtr(const Functor_t &functor)
    {
        return CPtr< Functor<Functor_t> >(functor);
    }

    template<typename Object_t, typename Memeber_t>
    typename _Methode<Memeber_t>::Target_t make_Function(Object_t Obj, Memeber_t member)
    {
        typedef typename _Methode<Memeber_t>::Target_t Method;
        return Method(Obj, member);
    }

    template<typename Out_t, typename... Arg_t>
    Function<Out_t, Arg_t...> make_Function(Out_t(*function)(Arg_t...))
    {
        return Function<Out_t, Arg_t...>(function);
    }

    template<typename Functor_t>
    Functor<Functor_t> make_Function(const Functor_t functor)
    {
        return Functor<Functor_t>(functor);
    }
}
