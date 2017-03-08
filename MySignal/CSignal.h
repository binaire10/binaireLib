#pragma once

#include <vector>
#include <algorithm>
#include "ISignalCall.h"
#include <IFunction.h>
#include "ISignalManager.h"
#include "SignalCallBox.h"
#include "SignalCallUnique.h"

namespace binaire
{
    template<bool staticCall, typename... Args_t>
    class CSignal;

    template<typename... Args_t>
    class CSignal<false, Args_t...> : public ISignalCall<Args_t...>
    {
    public:
        CSignal(ISignalManager *manager) : m_manager(manager)
        {}

        void addListener(IFunction<void, Args_t...> *listener) override
        { m_receptor.push_back(listener); }

        void removeListener(IFunction<void, Args_t...> *listener) override
        { m_receptor.erase(std::find(m_receptor.begin(), m_receptor.end(), listener)); }

        void emitCall(Args_t... arguments) override
        {
            SignalCallBox<Args_t...> *sig = new SignalCallBox<Args_t...>(this, arguments...);
            sig->creatSignalCall(m_manager);
        }

        void call(Args_t... arguments) const
        {
            for(IFunction<void, Args_t...> *iReceptor : m_receptor)
                iReceptor->call(arguments...);
        }

    private:
        std::vector<IFunction<void, Args_t...> *> m_receptor;
        ISignalManager *m_manager;
    };

    template<typename... Args_t>
    class CSignal<true, Args_t...> : public ISignalCall<Args_t...>
    {
    public:
        CSignal(ISignalManager *manager) : m_manager(manager)
        {}

        void addListener(IFunction<void, Args_t...> *listener) override
        { m_receptor.push_back(listener); }

        void removeListener(IFunction<void, Args_t...> *listener) override
        { m_receptor.erase(std::find(m_receptor.begin(), m_receptor.end(), listener)); }

        void emitCall(Args_t... arguments) override
        {
            m_staticCall->setArgument(arguments...);
            m_staticCall->creatSignalCall(m_manager);
        }

        void call(Args_t... arguments) const
        {
            for(IFunction<void, Args_t...> *iReceptor : m_receptor)
                iReceptor->call(arguments...);
        }

    private:
        SignalCallUnique<Args_t...> *m_staticCall = new SignalCallUnique<Args_t...>(this);
        std::vector<IFunction<void, Args_t...> *> m_receptor;
        ISignalManager *m_manager;
    };
}
