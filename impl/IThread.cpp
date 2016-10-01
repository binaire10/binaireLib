#include "../include/MySystem/Thread/IThread.hpp"
#include "../include/MySignal/SignalStack.h"
#include "../include/MySignal/CSignal.hpp"
#include "../include/MyArgument/Message.hpp"

binaire::System::IThread::IThread(binaire::SignalStack &ST) noexcept : isStarted(ST), isClosed(ST)
{}
