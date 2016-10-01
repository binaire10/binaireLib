#include "../include/MyMemory/SmartPtr.hpp"

using namespace binaire;

BaseSmartPtr::NativeSmartPtr::NativeSmartPtr(void *ptr, const IFunction<void, void *> *Deleter, const bool &autoDelete) noexcept : m_ptr(ptr), m_Deleter(Deleter), m_AutoDelete(autoDelete)
{}

BaseSmartPtr::NativeSmartPtr::~NativeSmartPtr() noexcept
{
    (*m_Deleter)(m_ptr);
    if(m_AutoDelete)
        delete m_Deleter;
}

void *BaseSmartPtr::NativeSmartPtr::get() noexcept
{ return m_ptr; }

const unsigned &BaseSmartPtr::NativeSmartPtr::count() const noexcept
{ return m_count;}

void BaseSmartPtr::NativeSmartPtr::newRef() const noexcept
{ ++m_count; }

bool BaseSmartPtr::NativeSmartPtr::deleteRef() const noexcept
{ return --m_count == 0; }

BaseSmartPtr::BaseSmartPtr() noexcept : m_Reference(nullptr)
{}

BaseSmartPtr::BaseSmartPtr(BaseSmartPtr::NativeSmartPtr *Val) noexcept : m_Reference(Val)
{
    if(m_Reference != nullptr)
        m_Reference->newRef();
}

BaseSmartPtr::BaseSmartPtr(const BaseSmartPtr &Val) noexcept : m_Reference(Val.m_Reference)
{
    if(m_Reference != nullptr)
        m_Reference->newRef();
}

BaseSmartPtr::BaseSmartPtr(void *Val, const IFunction<void, void *> *Deleter, const bool &autoDelete) noexcept : m_Reference(new NativeSmartPtr(Val, Deleter, autoDelete))
{ m_Reference->newRef(); }

BaseSmartPtr::~BaseSmartPtr() noexcept
{
    if(m_Reference && m_Reference->deleteRef())
    {
        delete m_Reference;
    }
}

BaseSmartPtr &BaseSmartPtr::operator=(const BaseSmartPtr &Val) noexcept
{
    if(Val.m_Reference!=nullptr)
        Val.m_Reference->newRef();

    if(m_Reference && m_Reference->deleteRef())
        delete m_Reference;

    m_Reference = Val.m_Reference;
    return *this;
}

BaseSmartPtr::DeleterNothing_t::~DeleterNothing_t() noexcept
{}

void BaseSmartPtr::DeleterNothing_t::operator()(void *) const noexcept
{}

SmartPtr<void>::SmartPtr(void *, NativeSmartPtr *Val) noexcept : BaseSmartPtr(Val)
{}

SmartPtr<void>::SmartPtr(void *ptr, const IFunction<void, void *> *Del, const bool &autoDelete) noexcept : BaseSmartPtr(ptr, Del, autoDelete)
{}

SmartPtr<void>::SmartPtr() noexcept
{ m_Reference = nullptr; }

template<typename T>
SmartPtr<void>::operator SmartPtr<T>() noexcept
{ return SmartPtr<T>(static_cast<T *>(m_Reference->get()), m_Reference); }

template<typename T>
SmartPtr<void>::operator const SmartPtr<T>() const noexcept
{ return SmartPtr<T>(static_cast<T *>(m_Reference->get()), m_Reference); }

void *SmartPtr<void>::GetPtr() noexcept
{ return m_Reference ? m_Reference->get() : nullptr; }

void *SmartPtr<void>::GetPtr() const noexcept
{ return m_Reference ? m_Reference->get() : nullptr; }
