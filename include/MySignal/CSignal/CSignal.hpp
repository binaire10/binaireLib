#pragma once
#include <vector>
#include "../../binairelib_global.h"
#include "CSignal.h"

#if defined __cplusplus
#include "../../MyMemory/RefPtr.hpp"
#include "../../MyFunction/IFunction.hpp"
#include "../../MyArgument/Message.hpp"
#include "../SignalStack.h"
#include <algorithm>

namespace binaire
{
    namespace System
    {
        namespace Call
        {
            template<typename... Arg_t>
            Signal<Arg_t...>::Signal(SignalStack &k, const unsigned &id) noexcept : m_EventStack(&k), m_Slots(), m_Id(id)
            {}


            template<typename... Arg_t>
            void Signal<Arg_t...>::moveEventStack(SignalStack &k) noexcept
            {
                m_EventStack = &k;
            }

            template<typename... Arg_t>
            void Signal<Arg_t...>::emitSig(const Arg_t&... arg)
            {
                m_EventStack->sendMessage(SmartPtr<FastCall>(new Message<Arg_t...>(RefPtr< IFunction<void, Arg_t...> >(this), arg..., m_Id)));
            }

            template<typename... Arg_t>
            SignalStack &Signal<Arg_t...>::getStackSig()
            {
                return *m_EventStack;
            }


            template<typename... Arg_t>
            void Signal<Arg_t...>::operator()(Arg_t... arg) const
            {
                for(SmartPtr<Signal<Arg_t...>::Slots_t> Slots : m_Slots)
                    (*Slots)(arg...);
            }

            template<typename... Arg_t>
            void Signal<Arg_t...>::addSlot(const SmartPtr<Signal<Arg_t...>::Slots_t> &Slot)
            {
                m_Slots.push_back(Slot);
            }

            template<typename... Arg_t>
            void Signal<Arg_t...>::removeSlot(const SmartPtr<Slots_t> &Slot)
            {
                typename std::vector< SmartPtr<Slots_t> *>::iterator Pos = std::find(m_Slots.begin(), m_Slots.end(), Slot);
                delete *Pos;
                m_Slots.erase(Pos);
            }

        }
    }
}
#endif
