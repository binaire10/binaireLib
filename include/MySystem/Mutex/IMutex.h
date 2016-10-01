#pragma once
#include "../CException.h"

namespace binaire
{
    namespace System
    {
        class IMutex
        {
        public:
            enum MutexError{
                MutexAllReadyUsed,
                MutexNonInitilized,
                MutexUnknownError,
                MutexActionNotAllow,
                MutexRecursiveExceded
            };
            typedef CCustomClassException<KMutexError, IMutex::MutexError> CMutexExcept;
            IMutex() noexcept = default;
            virtual ~IMutex() noexcept = default;
            virtual void lock() throw(CMutexExcept) = 0;
            virtual bool tryLock() throw(CMutexExcept) = 0;
            virtual void release() throw(CMutexExcept) = 0;
        };

    }
}
