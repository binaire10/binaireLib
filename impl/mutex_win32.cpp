#include "../include/MySystem/CException.h"
#include "../include/MyFile/IFile.h"
#include "../include/MyFile/IDir.h"
#include "../include/SystemFunction.h"

#include <windows.h>

using namespace binaire;
using namespace System;

class SysMutex : public IMutex
{
    // Mutex interface
public:
    SysMutex() noexcept : critical()
    {
        InitializeCriticalSection(&critical);
    }
    ~SysMutex() noexcept
    {
        DeleteCriticalSection(&critical);
    }

    void lock() throw(CMutexExcept) override
    {
        EnterCriticalSection(&critical);
    }

    bool tryLock() throw(CMutexExcept) override
    {
        return TryEnterCriticalSection(&critical);
    }

    void release() throw(CMutexExcept) override
    {
        LeaveCriticalSection(&critical);
    }
private:
    CRITICAL_SECTION critical;
    //HANDLE ghMutex;
};

extern "C"
{
    SmartPtr<IMutex> CreatMutex()
    {
        return make_SmartPtr(new SysMutex());
    }
}
