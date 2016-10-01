#pragma once
#include "../IFunction.hpp"
namespace binaire
{
    template<typename Return_t, typename... Arg_t>
    class TFunction : public virtual IFunction<Return_t, Arg_t...>
    {
    public:
        typedef IFunction<Return_t, Arg_t...> Parent_t;
        typedef Return_t (*Function_t)(Arg_t...);
        TFunction() noexcept = default;
        explicit TFunction(Function_t Func) noexcept : m_Function(Func)
        {}
        virtual ~TFunction() noexcept = default;

        Return_t operator()(Arg_t... arg) final
        {return m_Function(arg...);}

        Return_t operator()(Arg_t... arg) const final
        {return m_Function(arg...);}

    private:
        Function_t m_Function;
    };

    template<typename Return_t, typename... Arg_t>
    class TFunction<Return_t (*)(Arg_t...)> : public TFunction<Return_t, Arg_t...>
    {
    public:
        typedef IFunction<Return_t, Arg_t...> Parent_t;
        typedef TFunction<Return_t, Arg_t...> TParent_t;
        typedef Return_t (*Function_t)(Arg_t...);
        TFunction() noexcept = default;
        explicit TFunction(Function_t Func) noexcept : TParent_t(Func)
        {}
        virtual ~TFunction() noexcept = default;
    };
}
