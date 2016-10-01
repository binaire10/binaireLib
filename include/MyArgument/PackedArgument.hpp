#pragma once
#include "../MetaTemplate/MetaType.hpp"
#include "../MyType/natiftype.h"
#include "../MyFunction/IFunction.hpp"

namespace binaire
{

    template<typename Type, typename... Arg_t>
    class PackedArgument : private PackedArgument<Arg_t...>
    {
    public:
        typedef typename remove_all_access<Type>::type NatifArgumentType;
        typedef PackedArgument<Arg_t...> Parent_t;

        PackedArgument() noexcept = default;

        PackedArgument(const NatifArgumentType &val, const Arg_t&... arg) : Parent_t(arg...), m_Value(val)
        {}

        const Parent_t &parent() const
        {
            return *this;
        }

        Parent_t &parent()
        {
            return *this;
        }

        const NatifArgumentType &XValue() const
        {
            return m_Value;
        }

        template<typename Function_t, typename Out, typename... Arg>
        Out call(Function_t &funct, Arg... arg) const
        {
            return Parent_t::call(funct, arg..., m_Value);
        }

        template<typename Function_t, typename... Arg>
        void call(Function_t &funct, Arg... arg) const
        {
            Parent_t::call(funct, arg..., m_Value);
        }

    private:
        NatifArgumentType m_Value;
    };

    template<typename Type>
    class PackedArgument<Type>
    {
    public:
        typedef typename remove_all_access<Type>::type NatifArgumentType;
        typedef PackedArgument<Type> Parent_t;

        PackedArgument() noexcept = default;
        PackedArgument(const NatifArgumentType &val) : m_Value(val)
        {}
        virtual ~PackedArgument() noexcept = default;

        const Parent_t &parent() const
        {
            return *this;
        }

        Parent_t &parent()
        {
            return *this;
        }

        const NatifArgumentType &XValue() const
        {
            return m_Value;
        }

        template<typename Function_t, typename Out, typename... Arg>
        Out call(Function_t &funct, Arg... arg) const
        {
            return funct(arg..., m_Value);
        }

        template<typename Function_t, typename... Arg>
        void call(Function_t &funct, Arg... arg) const
        {
            funct(arg..., m_Value);
        }

    private:
        NatifArgumentType m_Value;
    };
}
