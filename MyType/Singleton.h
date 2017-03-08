#pragma once

#include <CPtr.h>

namespace binaire
{
    template<typename Type_t>
    class Singleton
    {
    public:
        static CPtr<Type_t> getInstance()
        {
            return m_Singleton;
        }

    private:
        Singleton() = default;
        static CPtr<Type_t> m_Singleton;
    };

    template<typename Type_t>
    CPtr<Type_t> Singleton<Type_t>::m_Singleton = CPtr<Type_t>::instantiate();
}
