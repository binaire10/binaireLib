#include "../include/MySignal/SignalStack.h"
#include "../include/MyArgument/Message.hpp"
#include "../include/MyMemory/SmartPtr.hpp"
#include "../include/SystemFunction.h"

binaire::SignalStack::SignalStack() noexcept :  m_Stack(0), m_Mutex(CreatMutex())
{}

binaire::SignalStack::~SignalStack()
{
    for(IPtr<FastCall> *&Sig : m_Stack)
    {
        delete Sig;
    }
}

void binaire::SignalStack::sendMessage(const IPtr<FastCall> &Msg)
{
    m_Mutex->lock();
    m_Stack.push_back(Msg.clone());
    m_Mutex->release();
}

void binaire::SignalStack::eraseSignal(const unsigned &Id)
{
    m_Mutex->lock();
    std::vector< IPtr<FastCall> *>::iterator i(m_Stack.begin());
    while(i != m_Stack.end())
        if((**i)->getId() == Id)
            i = m_Stack.erase(i);
    m_Mutex->release();
}

void binaire::SignalStack::exec()
{
    m_Mutex->lock();
    for(IPtr<FastCall> *&Sig : m_Stack)
    {
        (*Sig)->call();
        delete Sig;
    }
    m_Stack.clear();
    m_Mutex->release();
}
