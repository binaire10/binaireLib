#pragma once
#include <vector>
#include "../../allDeclaration.h"
#include "../../MyMemory/IPtr.hpp"
#include "../../MyFunction/IFunction.hpp"

namespace binaire
{
    namespace System
    {
        namespace Call
        {
            template<typename... Arg_t>
            class Signal : private IFunction<void, Arg_t...>
            {
            public:
                typedef IFunction<void, Arg_t...> Slots_t;
            private:
                SignalStack *m_EventStack;
                std::vector< SmartPtr<Slots_t> > m_Slots;
                const unsigned m_Id;
                void operator()(Arg_t... arg) const override;
            public:
                Signal(SignalStack &, const unsigned &id = 0) noexcept;
                Signal(const Signal &) = default;
                Signal &operator=(const Signal &) = default;
                void moveEventStack(SignalStack &) noexcept;
                void emitSig(const Arg_t&... arg);
                void addSlot(const SmartPtr<Slots_t> &Slot);
                void removeSlot(const SmartPtr<Slots_t> &Slot);
                const unsigned &idSignal() const;
                SignalStack &getStackSig();
            };
        }
    }
}
