#pragma once

#include "ICall.h"
#include "../MyFunction/Argument.h"
#include "ISignalManager.h"
#include "ISignalCall.h"

namespace binaire
{
    template<typename... Arg_t>
    class SignalCallUnique: public ICall
    {
    public:
        SignalCallUnique(ISignalCall<Arg_t...> *emiter) noexcept : m_emiter(emiter)
        {}

        void creatSignalCall(ISignalManager *sigManager) override
        {
            if(!m_emited)
            {
                m_emited = true;
                sigManager->addCall(this);
            }

        }

        void setArgument(Arg_t... arg)
        {
            m_arg.setValue(arg...);
        }

        void call() override
        {
            m_arg.call(*m_emiter);
        }

        void destroy() override
        {
            m_emited = false;
        }

    private:
        bool m_emited = false;
        Argument<Arg_t...> m_arg;
        ISignalCall<Arg_t...> *m_emiter;
    };
}
