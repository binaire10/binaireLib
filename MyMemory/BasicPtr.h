#pragma once

#include "IPtr.h"

namespace binaire
{
    template<typename Type_t > class CPtr;

    template<typename Type_t>
    class BasicPtr: public IPtr {
    public:
        BasicPtr(Type_t *ptr) : m_ptr(ptr)
        {}

        ~BasicPtr() noexcept
        { delete m_ptr;}

        void *getPtr() noexcept override
        { return static_cast<void *>(m_ptr); }

        unsigned countRef() const noexcept override
        {
            return m_referenceCount;
        }

        const std::type_info &getTypeIndex() override
        { return typeid(Type_t); }

    protected:
        void newReference() const noexcept override
        { ++m_referenceCount; }

        bool deleteReference() const noexcept override
        { return --m_referenceCount == 0; }

    private:
        Type_t *m_ptr = nullptr;
        mutable unsigned m_referenceCount = 0;

        friend class CPtr<Type_t>;
    };
}
