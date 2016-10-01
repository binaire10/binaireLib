#pragma once
#include <vector>
#include "../allDeclaration.h"
#include "../MySystem/Mutex/IMutex.h"
#include "../MyMemory/SmartPtr.hpp"
#include "../binairelib_global.h"

namespace binaire
{
    class BINAIRELIBSHARED_EXPORT SignalStack
    {
    private:
        std::vector< IPtr<FastCall> *> m_Stack;
        SmartPtr<System::IMutex> m_Mutex;
    public:
        SignalStack() noexcept;
        SignalStack(const SignalStack&) = delete;
        SignalStack &operator=(const SignalStack&) = delete;
        virtual ~SignalStack();
        void sendMessage(const IPtr<FastCall> &Msg);
        void eraseSignal(const unsigned &Id);
        void exec();
    };
}
