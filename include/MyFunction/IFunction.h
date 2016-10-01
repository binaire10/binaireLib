#pragma once
#include "../MetaTemplate/MetaType.hpp"

namespace binaire
{
    template<typename Out_t, typename... Arg_t>
    class IFunction
    {
    public:
        typedef Tuple<Arg_t...> PackArg_t;
        typedef Out_t        Return_t;

        IFunction() noexcept = default;
        virtual ~IFunction() = default;
        virtual Return_t operator()(Arg_t... arg);
        virtual Return_t operator()(Arg_t... arg) const = 0;
        IFunction &getIFunction() noexcept;

        const IFunction &getIFunction() const noexcept;
    };
}
#include "IFunction.hpp"
