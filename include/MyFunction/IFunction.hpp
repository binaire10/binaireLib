#pragma once
#include "../MetaTemplate/MetaType.hpp"
#include "IFunction.h"

#if defined __cplusplus
template<typename Out_t, typename... Arg_t>
typename binaire::IFunction<Out_t, Arg_t...>::Return_t binaire::IFunction<Out_t, Arg_t...>::operator()(Arg_t... arg)
{
    const IFunction &K =(*this);
    return K(arg...);
}

template<typename Out_t, typename... Arg_t>
binaire::IFunction<Out_t, Arg_t...> &binaire::IFunction<Out_t, Arg_t...>::getIFunction() noexcept
{return *this;}

template<typename Out_t, typename... Arg_t>
const binaire::IFunction<Out_t, Arg_t...> &binaire::IFunction<Out_t, Arg_t...>::getIFunction() const noexcept
{return *this;}
#endif
