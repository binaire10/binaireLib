#pragma once
#include "../../allDeclaration.h"
#include "../../binairelib_global.h"
#include "../../MySignal/CSignal.hpp"

namespace binaire
{
    namespace System
    {
        class BINAIRELIBSHARED_EXPORT IThread
        {
        public:
            IThread(SignalStack &) noexcept;
            virtual ~IThread() = default;
            virtual void Start(const IPtr< IFunction<void> > &) noexcept = 0;
            virtual void Join() noexcept = 0;
            virtual void Detach() noexcept = 0;
            Call::Signal<> isStarted;
            Call::Signal<> isClosed;
        };
    }
}
