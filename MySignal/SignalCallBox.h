#pragma once

#include "ICall.h"
#include "../MyFunction/Argument.h"
#include "ISignalManager.h"
#include "ISignalCall.h"

namespace binaire
{
    template<typename... Arg_t>
    class SignalCallBox : public ICall
    {
    public:
        SignalCallBox(ISignalCall<Arg_t...> *emiter, Arg_t... arg) noexcept : m_emiter(emiter), m_arg(arg...)
        {}

        void creatSignalCall(ISignalManager *sigManager) override
        {
            sigManager->addCall(this);
        }

        void call() override
        {
            m_arg.call(*m_emiter);
        }

        void destroy() override
        {
            delete this;
        }
    private:
        ISignalCall<Arg_t...> *m_emiter;
        Argument<Arg_t...> m_arg;
    };
}
