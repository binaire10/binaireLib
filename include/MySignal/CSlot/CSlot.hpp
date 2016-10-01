#pragma once
#include "CSlot.h"
#include "../FonctionAdapter.hpp"

#if defined __cplusplus
template<typename Function, typename... Arg_t>
binaire::System::Call::CSlot<Function, Arg_t...>::CSlot(Function Fonc) noexcept : m_Fonc(Fonc)
{}

template<typename Function, typename... Arg_t>
void binaire::System::Call::CSlot<Function, Arg_t...>::operator()(Arg_t... arg)
{
    binaire::System::Call::call(m_Fonc, arg...);
}

template<typename Function, typename... Arg_t>
void binaire::System::Call::CSlot<Function, Arg_t...>::operator()(Arg_t... arg) const
{
    binaire::System::Call::call(m_Fonc, arg...);
}
#endif
