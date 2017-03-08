#pragma once

namespace binaire
{
    class ICall;
    class ISignalManager
    {
    public:
        virtual void addCall(ICall *call) = 0;
        virtual void exec() = 0;
    };
}
