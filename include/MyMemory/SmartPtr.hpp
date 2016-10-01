#pragma once
#include "SmartPtr.h"

#if defined __cplusplus
namespace binaire
{
    template<typename Type>
    SmartPtr<Type>::Deleter_t::~Deleter_t() noexcept
    {}

    template<typename Type>
    void SmartPtr<Type>::Deleter_t::operator() (void *ptr) const noexcept
    {delete static_cast<Type *>(ptr);}

    template<typename Type>
    SmartPtr<Type>::SmartPtr(Type *, NativeSmartPtr *Val) noexcept : BaseSmartPtr(Val)
    {}

    template<typename Type>
    SmartPtr<Type>::SmartPtr(Type *ptr, const IFunction<void, void *> *Del, const bool &autoDelete) noexcept : BaseSmartPtr(static_cast<void *>(ptr), Del, autoDelete)
    {}

    template<typename Type>
    SmartPtr<Type>::SmartPtr() noexcept
    {
        m_Reference = nullptr;
    }

    template<typename Type>
    template<typename T>
    SmartPtr<Type>::operator SmartPtr<T>() noexcept
    { return SmartPtr<T>(static_cast<Type *>(m_Reference->get()), m_Reference); }

    template<typename Type>
    template<typename T>
    SmartPtr<Type>::operator const SmartPtr<T>() const noexcept
    { return SmartPtr<T>(static_cast<Type *>(m_Reference->get()), m_Reference); }

    template<typename Type>
    Type &SmartPtr<Type>::operator*() noexcept
    { return *static_cast<Type *>(m_Reference->get()); }

    template<typename Type>
    Type *SmartPtr<Type>::operator->() noexcept
    { return static_cast<Type *>(m_Reference->get()); }

    template<typename Type>
    Type *SmartPtr<Type>::GetPtr() noexcept
    { return m_Reference ? static_cast<Type *>(m_Reference->get()) : nullptr; }

    template<typename Type>
    const Type *SmartPtr<Type>::GetPtr() const noexcept
    { return m_Reference ? static_cast<Type *>(m_Reference->get()) : nullptr; }

    template<typename Type>
    const Type &SmartPtr<Type>::operator*() const noexcept
    { return *static_cast<Type *>(m_Reference->get()); }

    template<typename Type>
    const Type *SmartPtr<Type>::operator->() const noexcept
    { return static_cast<Type *>(m_Reference->get()); }

    template<typename Type>
    IPtr<Type> *SmartPtr<Type>::clone() const noexcept
    {
        return new SmartPtr(*this);
    }

    template<typename T>
    inline SmartPtr<T> strong_cast(const BaseSmartPtr &V) noexcept
    { return SmartPtr<T>(static_cast<T *>(V.m_Reference->get()), V.m_Reference); }

    template<typename T>
    inline SmartPtr<T> make_SmartPtr(T *V) noexcept
    { return SmartPtr<T>(V); }
}
#endif
