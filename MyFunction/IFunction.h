/**
 * Project Universe
 */


#pragma once

namespace binaire
{
    template<typename Result_t , typename... Args_t >
    class IFunction {
    public:
        typedef IFunction<Result_t, Args_t...> Parent_t;
        IFunction() = default;
        virtual ~IFunction() = default;
        virtual Result_t call(Args_t... arguments) const = 0;
        Result_t operator()(Args_t... arguments) const
        { return call(arguments...); }
    };
}
