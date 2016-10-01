#pragma once
#include "../../allDeclaration.h"
#include "../../MyFunction/IFunction.hpp"

namespace binaire
{
    namespace System
    {
        namespace Call
        {
            template<typename Function, typename... Arg_t>
            class CSlot : public IFunction<void, Arg_t...>
            {
            private:
                Function m_Fonc;

            public:
                CSlot() = default;
                CSlot(Function Fonc) noexcept;
                virtual ~CSlot() noexcept = default;
                void operator()(Arg_t... arg) final;
                void operator()(Arg_t... arg) const final;
            };
        }
    }
}

