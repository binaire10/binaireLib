#pragma once
#include "CFunction.h"

#if defined __cplusplus
#include "IFunction.hpp"
#include "../MyMemory/SmartPtr.hpp"
#include "class/TMember.hpp"
#include "function/TFunction.hpp"
#include "lambda/TFonctor.hpp"
namespace binaire
{
        template<typename Return_t, typename... Arg_t>
        CFunction<Return_t, Arg_t...>::CFunction(TAnyFunction &Fonc) noexcept : m_Function(&Fonc, false)
        {}

        template<typename Return_t, typename... Arg_t>
        template<typename Obj_t>
        CFunction<Return_t, Arg_t...>::CFunction(Obj_t &Obj) noexcept : m_Function(new TFonctor<Obj_t>(Obj))
        {}

        template<typename Return_t, typename... Arg_t>
        template<typename Obj_t>
        CFunction<Return_t, Arg_t...>::CFunction(Obj_t &Obj, Return_t (Obj_t::*Member)(Arg_t...)) noexcept : m_Function(new TMember<Return_t (Obj_t::*)(Arg_t...)>(Obj, Member))
        {}

        template<typename Return_t, typename... Arg_t>
        CFunction<Return_t, Arg_t...>::CFunction(Return_t (*Function)(Arg_t...)) noexcept : m_Function(new TFunction<Return_t (*)(Arg_t...)>(Function))
        {}

        template<typename Return_t, typename... Arg_t>
        CFunction<Return_t, Arg_t...> &CFunction<Return_t, Arg_t...>::operator=(TAnyFunction &Fonc) noexcept
        {
            m_Function = SmartPtr<TAnyFunction>(&Fonc, false);
            return *this;
        }

        template<typename Return_t, typename... Arg_t>
        CFunction<Return_t, Arg_t...> &CFunction<Return_t, Arg_t...>::setFunction(TAnyFunction &Fonc) noexcept
        {
            m_Function = SmartPtr<TAnyFunction>(&Fonc, false);
            return *this;
        }

        template<typename Return_t, typename... Arg_t>
        template<typename Obj_t>
        CFunction<Return_t, Arg_t...> &CFunction<Return_t, Arg_t...>::setFunction(Obj_t &Obj) noexcept
        {
             m_Function = SmartPtr<TAnyFunction>(new TFonctor<Obj_t>(Obj));
             return *this;
        }

        template<typename Return_t, typename... Arg_t>
        template<typename Obj_t>
        CFunction<Return_t, Arg_t...> &CFunction<Return_t, Arg_t...>::setFunction(Obj_t &Obj, Return_t (Obj_t::*Member)(Arg_t...)) noexcept
        {
            m_Function = SmartPtr<TAnyFunction>(new TMember<Return_t (Obj_t::*)(Arg_t...)>(Obj, Member));
            return *this;
        }

        template<typename Return_t, typename... Arg_t>
        CFunction<Return_t, Arg_t...> &CFunction<Return_t, Arg_t...>::setFunction(Return_t (*Function)(Arg_t...)) noexcept
        {
            m_Function = SmartPtr<TAnyFunction>(new TFunction<Return_t (*)(Arg_t...)>(Function));
            return *this;
        }

        // VFunction interface
        template<typename Return_t, typename... Arg_t>
        Return_t CFunction<Return_t, Arg_t...>::operator ()(Arg_t... arg)
        {
            return (*m_Function)(arg...);
        }

        template<typename Return_t, typename... Arg_t>
        Return_t CFunction<Return_t, Arg_t...>::operator ()(Arg_t... arg) const
        {
            return (*m_Function)(arg...);
        }
}
#endif
