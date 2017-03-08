#pragma once

namespace binaire
{
    class ISignalManager;

    class ICall {
    public:
        virtual ~ICall() = default;
        virtual void creatSignalCall(ISignalManager *) = 0;
        virtual void destroy() = 0;
        virtual void call() = 0;
    };
}
