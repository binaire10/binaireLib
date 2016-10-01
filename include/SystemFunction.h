#pragma once
#include "MySystem/Mutex/IMutex.h"
#include "MySystem/Thread/IThread.hpp"
#include "MyMemory/SmartPtr.hpp"
#include "binairelib_global.h"
namespace binaire
{
    class SignalStack;
}

extern "C" {
BINAIRELIBSHARED_EXPORT binaire::SmartPtr<binaire::System::IMutex> CreatMutex();
BINAIRELIBSHARED_EXPORT binaire::SmartPtr<binaire::System::IThread> CreatThread(binaire::SignalStack &);
}


BINAIRELIBSHARED_EXPORT int test();
