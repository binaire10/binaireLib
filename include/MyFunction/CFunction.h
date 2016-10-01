#pragma once
#include "../allDeclaration.h"

namespace binaire
{
    template<typename Return_t, typename... Arg_t>
    class CFunction : public virtual IFunction<Return_t, Arg_t...>
    {
    public:
        CFunction() noexcept = default;
        typedef IFunction<Return_t, Arg_t...> TAnyFunction;

    private:
        SmartPtr<TAnyFunction> m_Function = SmartPtr<TAnyFunction>();

    public:
        CFunction(TAnyFunction &Fonc) noexcept;

        template<typename Obj_t>
        CFunction(Obj_t &Obj) noexcept;

        template<typename Obj_t>
        CFunction(Obj_t &Obj, Return_t (Obj_t::*Member)(Arg_t...)) noexcept;

        CFunction(Return_t (*Function)(Arg_t...)) noexcept;
        CFunction &operator=(TAnyFunction &Fonc) noexcept;
        CFunction &setFunction(TAnyFunction &Fonc) noexcept;

        template<typename Obj_t>
        CFunction &setFunction(Obj_t &Obj) noexcept;

        template<typename Obj_t>
        CFunction &setFunction(Obj_t &Obj, Return_t (Obj_t::*Member)(Arg_t...)) noexcept;
        CFunction &setFunction(Return_t (*Function)(Arg_t...)) noexcept;

        // VFunction interface
        Return_t operator ()(Arg_t... arg) final;
        Return_t operator ()(Arg_t... arg) const final;
    };
}
#include "CFunction.hpp"
