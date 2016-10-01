#include "../include/MySystem/CException.h"
#include "../include/MyFile/IFile.h"
#include "../include/MyFile/IDir.h"
#include "../include/SystemFunction.h"

#include <pthread.h>

using namespace binaire;
using namespace System;

class SysMutex : public IMutex
{
    // Mutex interface
public:
    ~SysMutex();
    void lock() throw(CMutexExcept) override;
    bool tryLock() throw(CMutexExcept) override;
    void release() throw(CMutexExcept) override;

private:
    pthread_mutex_t m_Mutex = PTHREAD_MUTEX_INITIALIZER;
};

extern "C"
{
    SmartPtr<IMutex> CreatMutex()
    {
        return make_SmartPtr(new SysMutex());
    }
}

SysMutex::~SysMutex()
{
    switch (pthread_mutex_destroy(&m_Mutex))
    {
    case EBUSY: // The implementation has detected an attempt to destroy the object referenced by mutex while it is locked or referenced
        break;
    case EINVAL: // non initialised thread
        break;
    case 0:
    default:
        break;
    }
}

void SysMutex::lock() throw(CMutexExcept)
{
    switch (pthread_mutex_lock(&m_Mutex))
    {
    case EBUSY: // The implementation has detected an attempt to destroy the object referenced by mutex while it is locked or referenced
        throw CMutexExcept(MutexAllReadyUsed);
        break;

    case EINVAL: // non initialised thread
        throw CMutexExcept(MutexNonInitilized);
        break;

    case EAGAIN: // The  mutex  could  not be acquired because the maximum number of recursive locks for mutex has been exceeded
        throw CMutexExcept(MutexRecursiveExceded);
        break;

    case EDEADLK: // The current thread already owns the mutex
        throw CMutexExcept(MutexAllReadyUsed);
        break;
    case 0:
    default:
        break;
    }
}

bool SysMutex::tryLock() throw(CMutexExcept)
{
    switch(pthread_mutex_trylock(&m_Mutex))
    {
    case EDEADLK: // The current thread already owns the mutex
        throw CMutexExcept(MutexAllReadyUsed);
        break;
    case EINVAL: // non initialised thread
        throw CMutexExcept(MutexNonInitilized);
        break;

    case 0:
        return true;
    case EBUSY: // The implementation has detected an attempt to destroy the object referenced by mutex while it is locked or referenced
    case EAGAIN: // The  mutex  could  not be acquired because the maximum number of recursive locks for mutex has been exceeded
    default:
        return false;
        break;
    }

    return false;
}

void SysMutex::release() throw(CMutexExcept)
{
    switch(pthread_mutex_unlock(&m_Mutex))
    {
    case EPERM: // The current thread does not own the mutex.
        throw CMutexExcept(MutexActionNotAllow);
        break;
    case 0:
        break;
    default:
        throw CMutexExcept(MutexUnknownError);
        break;
    }
}
