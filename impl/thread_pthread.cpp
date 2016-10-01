#include "../include/SystemFunction.h"
#include "../CstCodErr.h"
#include "../include/MySignal/SignalStack.h"
#include "../include/MyFunction/utility.hpp"

#include <pthread.h>

using namespace binaire;
using namespace System;

class Thread;
struct ArgThread
{
    IPtr< IFunction<void> > *Fonc;
    SignalStack *ThreadEvent;
    Thread *MyThread;
};

void *Worker(void *ptr);

class Thread : public IThread
{
public:
    Thread(SignalStack &z);
    Thread(const Thread &) = delete;
    Thread operator=(const Thread &) = delete;
    ~Thread() override;
    void Start(const IPtr<IFunction<void> > &Data) noexcept override;
    void Join() noexcept override;
    void Detach() noexcept override;
private:
    pthread_t m_ID = 0;
    SignalStack &m_EventSys;
    SmartPtr< IFunction<void> > WaitEndThread;
    SmartPtr< IPtr< IFunction<void> > > m_Func = SmartPtr< IPtr< IFunction<void> > >();
    bool m_isRunning = false;
    ArgThread *m_argPtr;
};

SmartPtr<IThread> CreatThread(SignalStack &Event)
{
    return make_SmartPtr(new Thread(Event));
}

void *Worker(void *ptr)
{
    ArgThread &Arg = *static_cast<ArgThread *>(ptr);
    IFunction<void> &Value = *(Arg.Fonc->GetPtr());
    Arg.MyThread->isStarted.emitSig();
    Value();
    Arg.MyThread->isClosed.emitSig();
    delete Arg.Fonc;
    return 0;
}

Thread::Thread(SignalStack &z) : IThread(z), m_EventSys(z), WaitEndThread(SmartCall::make_SFunction(*this, &Thread::Join)), m_argPtr(nullptr)
{
    isClosed.addSlot(WaitEndThread);
}

Thread::~Thread()
{
    if(m_isRunning)
        pthread_cancel(m_ID);
}

void Thread::Start(const IPtr<IFunction<void> > &Data) noexcept
{
    pthread_create(&m_ID, nullptr, Worker, static_cast<void *>(new ArgThread({Data.clone(), &m_EventSys, this})));
    m_isRunning = true;
}

void Thread::Join() noexcept
{
    pthread_join(m_ID, nullptr);
    m_isRunning = false;
    delete m_argPtr;
}

void Thread::Detach() noexcept
{
    pthread_detach(m_ID);
}
