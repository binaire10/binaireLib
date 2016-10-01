#include "../include/SystemFunction.h"
#include "../CstCodErr.h"
#include "../include/MySignal/SignalStack.h"
#include "../include/MyFunction/utility.hpp"


#include <windows.h>
#include <process.h>

using namespace binaire;
using namespace System;

class Thread;
struct ArgThread
{
    IPtr< IFunction<void> > *Fonc;
    SignalStack *ThreadEvent;
    Thread *MyThread;
};

unsigned __stdcall Worker(void *ptr) noexcept;

class Thread : public IThread
{
public:
    Thread(SignalStack &z);
    Thread(const Thread &) = default;
    Thread &operator=(const Thread &) = default;
    ~Thread() override;
    void Start(const IPtr<IFunction<void> > &Data) noexcept override;
    void Join() noexcept override;
    void Detach() noexcept override;
private:
    HANDLE m_hThread = nullptr;
    unsigned m_threadID;
    bool m_isRunning = false;
    SmartPtr< IPtr< IFunction<void> > > m_Func;
    ArgThread *m_argPtr;
    SignalStack &m_EventSys;
    SmartPtr< IFunction<void> > WaitEndThread;
};

SmartPtr<IThread> CreatThread(SignalStack &Event)
{
    return SmartPtr<IThread>(new Thread(Event));
}


unsigned __stdcall Worker(void *ptr) noexcept
{
    ArgThread &Arg = *static_cast<ArgThread *>(ptr);
    IFunction<void> &Value = *(Arg.Fonc->GetPtr());
    Arg.MyThread->isStarted.emitSig();
    Value();
    Arg.MyThread->isClosed.emitSig();
    delete Arg.Fonc;

    _endthreadex(KNoError);
    return 0;
}

Thread::Thread(SignalStack &z) : IThread(z), m_hThread(nullptr), m_threadID(), m_Func(), m_argPtr(nullptr), m_EventSys(z), WaitEndThread(SmartCall::make_SFunction(*this, &Thread::Join))
{
    isClosed.addSlot(WaitEndThread);
}

Thread::~Thread()
{
    DWORD result;
    if(GetExitCodeThread( m_hThread, &result) != 0)
    {
        if(result == STILL_ACTIVE)
        {
            TerminateThread(m_hThread, result);
            CloseHandle( m_hThread );
            delete m_argPtr;
        }
    }
    else
    {
        // ERROR
    }
}

void Thread::Start(const IPtr<IFunction<void> > &Data) noexcept
{
    Join();
    m_argPtr = new ArgThread({Data.clone(), &m_EventSys, this});
    m_isRunning = true;
    m_Func = make_SmartPtr(Data.clone());
    m_hThread = reinterpret_cast<HANDLE>(_beginthreadex( nullptr, 0, &Worker, static_cast<void*>(m_argPtr), 0, &m_threadID));
}

void Thread::Join() noexcept
{
    WaitForSingleObject( m_hThread, INFINITE );
    CloseHandle( m_hThread );
    m_isRunning = false;
    delete m_argPtr;
    m_argPtr = nullptr;
}

void Thread::Detach() noexcept
{}
