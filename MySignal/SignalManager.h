#pragma once

#include "ISignalManager.h"
#include "ICall.h"
#include <vector>

namespace binaire
{
    class SignalManager: public ISignalManager
    {
    public:
        void addCall(ICall *call) override
        {
            m_signals.push_back(call);
        }

        void exec() override
        {
            for(ICall * const iCall : m_signals)
            {
                iCall->call();
                iCall->destroy();
            }
            m_signals.clear();
            m_signals.reserve(m_reserveStack);
        }

    private:
        unsigned m_reserveStack = 10;
        std::vector<ICall *> m_signals;
    };
}
