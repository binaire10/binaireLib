#pragma once
#include "../allDeclaration.h"

namespace binaire
{
    namespace SmartCall
    {
        template<typename Return_t, typename Obj_t, typename... Arg_t>
        TMember<Return_t (Obj_t::*)(Arg_t...)> make_IFunction(Obj_t &Obj, Return_t (Obj_t::*Member)(Arg_t...));

        template<typename Return_t, typename Obj_t, typename... Arg_t>
        TMember<Return_t (Obj_t::*)(Arg_t...) const> make_IFunction(Obj_t &Obj, Return_t (Obj_t::*Member)(Arg_t...) const);

        template<typename Return_t, typename... Arg_t>
        TFunction<Return_t (*)(Arg_t...)> make_IFunction(Return_t (*Function)(Arg_t...));

        template<typename ReturnType, typename Fonctor_t>
        TFonctor<Fonctor_t> make_IFunction(Fonctor_t Fonctor);

        template<typename Return_t, typename Obj_t, typename... Arg_t>
        SmartPtr< TMember<Return_t (Obj_t::*)(Arg_t...)> > make_SFunction(Obj_t &Obj, Return_t (Obj_t::*Member)(Arg_t...));

        template<typename Return_t, typename Obj_t, typename... Arg_t>
        SmartPtr< TMember<Return_t (Obj_t::*)(Arg_t...) const> > make_SFunction(Obj_t &Obj, Return_t (Obj_t::*Member)(Arg_t...) const);

        template<typename Return_t, typename Obj_t, typename... Arg_t>
        SmartPtr< TMember<Return_t (Obj_t::*)(Arg_t...) const> > make_SFunction(Obj_t *&Obj, Return_t (Obj_t::*Member)(Arg_t...) const);

        template<typename Return_t, typename... Arg_t>
        SmartPtr< TFunction<Return_t (*)(Arg_t...)> > make_SFunction(Return_t (*Function)(Arg_t...));

        template<typename Fonctor_t>
        SmartPtr< TFonctor<Fonctor_t> > make_SFunction(Fonctor_t Fonctor);
    }
}

#include "utility.hpp"
