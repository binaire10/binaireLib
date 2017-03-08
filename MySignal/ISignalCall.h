#pragma once

#include "../MyFunction/Function.h"

namespace binaire
{
    template<typename... Args_t>
    class ISignalCall  : public IFunction<void, Args_t...>
    {
        virtual void addListener(IFunction<void, Args_t...> *listener) = 0;
        virtual void removeListener(IFunction<void, Args_t...> *listener) = 0;
        virtual void emitCall(Args_t... arguments) = 0;
    };
}
