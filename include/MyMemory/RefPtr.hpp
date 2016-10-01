#pragma once
#include "IPtr.hpp"

namespace binaire
{
    template<class Type>
    class RefPtr : public IPtr<Type>
    {
    public:
        template<typename T>
        operator RefPtr<T>() noexcept
        { return RefPtr<T>(*this); }

        template<typename T>
        operator const RefPtr<T>() const noexcept
        { return RefPtr<T>(*this); }

        RefPtr(const IPtr<Type> &V) noexcept : m_XPtr(V.GetPtr())
        {}
        RefPtr(const RefPtr &) = default;
        RefPtr &operator =(const RefPtr &) = default;
        RefPtr(Type &V) noexcept : m_XPtr(&V)
        {}
        RefPtr(Type *V) noexcept : m_XPtr(V)
        {}
        Type &operator *() noexcept override
        {
            return *m_XPtr;
        }
        Type *operator ->() noexcept override
        {
            return m_XPtr;
        }
        Type *GetPtr() noexcept override
        {
            return m_XPtr;
        }
        const Type &operator *() const noexcept override
        {
            return *m_XPtr;
        }
        const Type *operator ->() const noexcept override
        {
            return m_XPtr;
        }
        const Type *GetPtr() const noexcept override
        {
            return m_XPtr;
        }
        IPtr<Type> *clone() const noexcept override
        {
            return new RefPtr(*this);
        }
    private:
        Type *m_XPtr;
    };
}
