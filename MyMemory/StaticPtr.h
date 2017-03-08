#pragma once

#include "IPtr.h"

namespace binaire
{
    template<typename Type_t > class CPtr;

    template<typename Type_t >
    class StaticPtr: public IPtr {
    public:
        template<typename... Arg_t>
        StaticPtr(Arg_t... arg) : m_referenceCount(0), m_value(arg...)
        {}

        ~StaticPtr() noexcept
        {}

        void *getPtr() noexcept override
        { return static_cast<void *>(&m_value); }

        unsigned countRef() const noexcept override
        { return m_referenceCount; }

        const std::type_info &getTypeIndex() override
        { return typeid(Type_t); }

    protected:
        void newReference() const noexcept override
        {++m_referenceCount;}

        bool deleteReference() const noexcept override
        { return --m_referenceCount == 0; }

    private:
        mutable unsigned m_referenceCount = 0;
        Type_t m_value = defaultvalue;
    };
}
