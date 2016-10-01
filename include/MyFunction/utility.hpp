#pragma once

#include "utility.h"
#include "class/TMember.hpp"
#include "lambda/TFonctor.hpp"
#include "function/TFunction.hpp"
#include "../MyMemory/SmartPtr.hpp"

#if defined __cplusplus

namespace binaire
{
    namespace SmartCall
    {
        template<typename Return_t, typename Obj_t, typename... Arg_t>
        TMember<Return_t (Obj_t::*)(Arg_t...)> make_IFunction(Obj_t &Obj, Return_t (Obj_t::*Member)(Arg_t...))
        {
            return TMember<Return_t (Obj_t::*)(Arg_t...)>(Obj, Member);
        }

        template<typename Return_t, typename Obj_t, typename... Arg_t>
        TMember<Return_t (Obj_t::*)(Arg_t...) const> make_IFunction(Obj_t &Obj, Return_t (Obj_t::*Member)(Arg_t...) const)
        {
            return TMember<Return_t (Obj_t::*)(Arg_t...) const>(Obj, Member);
        }

        template<typename Return_t, typename... Arg_t>
        TFunction<Return_t (*)(Arg_t...)> make_IFunction(Return_t (*Function)(Arg_t...))
        {
            return TFunction<Return_t (*)(Arg_t...)>(Function);
        }

        template<typename ReturnType, typename Fonctor_t>
        TFonctor<Fonctor_t> make_IFunction(Fonctor_t Fonctor)
        {
            return TFonctor<Fonctor_t>(Fonctor);
        }

        template<typename Return_t, typename Obj_t, typename... Arg_t>
        SmartPtr< TMember<Return_t (Obj_t::*)(Arg_t...)> > make_SFunction(Obj_t &Obj, Return_t (Obj_t::*Member)(Arg_t...))
        {
            return make_SmartPtr(new TMember<Return_t (Obj_t::*)(Arg_t...)>(Obj, Member));
        }

        template<typename Return_t, typename Obj_t, typename... Arg_t>
        SmartPtr< TMember<Return_t (Obj_t::*)(Arg_t...) const> > make_SFunction(Obj_t &Obj, Return_t (Obj_t::*Member)(Arg_t...) const)
        {
            return make_SmartPtr(new TMember<Return_t (Obj_t::*)(Arg_t...) const>(Obj, Member));
        }

        template<typename Return_t, typename Obj_t, typename... Arg_t>
        SmartPtr< TMember<Return_t (Obj_t::*)(Arg_t...) const> > make_SFunction(Obj_t *&Obj, Return_t (Obj_t::*Member)(Arg_t...) const)
        {
            return make_SmartPtr(new TMember<Return_t (Obj_t::*)(Arg_t...) const>(Obj, Member));
        }

        template<typename Return_t, typename... Arg_t>
        SmartPtr< TFunction<Return_t (*)(Arg_t...)> > make_SFunction(Return_t (*Function)(Arg_t...))
        {
            return make_SmartPtr(new TFunction<Return_t (*)(Arg_t...)>(Function));
        }

        template<typename Fonctor_t>
        SmartPtr< TFonctor<Fonctor_t> > make_SFunction(Fonctor_t Fonctor)
        {
            return make_SmartPtr(new TFonctor<Fonctor_t>(Fonctor));
        }
    }
}
#endif
