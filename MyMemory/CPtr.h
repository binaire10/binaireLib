#pragma once
#include "IPtr.h"
#include "BasicPtr.h"
#include "StaticPtr.h"
#include "../MyFunction/MetaTemplate/MetaType.hpp"

namespace binaire
{
    template<typename Type_t>
    class CPtr;

    template<typename Type_t>
    CPtr<Type_t> make_Ptr(Type_t *ptr);

    template<>
    class CPtr<void> {
    public:
        CPtr() noexcept : m_ref(nullptr)
        {}

        CPtr(const CPtr &copy) noexcept
        { setRef(copy.getRef()); }


        template<typename... Arg_t>
        static CPtr instantiate(Arg_t&&... arg);
        void *operator->();
        const void *operator->() const;

        virtual ~CPtr() noexcept
        {
            if(m_ref != nullptr && m_ref->deleteReference())
                delete m_ref;
        }

        void* getPtr() noexcept
        {  return static_cast<void *>(m_ref->getPtr()); }

        const void* getPtr() const noexcept
        { return static_cast<void *>(m_ref->getPtr()); }

        template<typename T>
        CPtr<T> reinterpretCast() const
        { return CPtr<T>(getRef()); }

        CPtr &operator=(const CPtr &value) noexcept
        {
            setRef(value.getRef());
            return *this;
        }

        void release()
        { setRef(nullptr); }

        const std::type_info &getTypeIndex() const
        {
            return m_ref->getTypeIndex();
        }

        friend CPtr<void> make_Ptr<void>(void *ptr);

    protected:
        explicit CPtr(IPtr *ref) noexcept : m_ref(nullptr)
        { setRef(ref); }

        void setRef(IPtr *value) noexcept
        {
            if(value != nullptr)
                value->newReference();
            if(m_ref != nullptr && m_ref->deleteReference())
                delete m_ref;
            m_ref = value;
        }

        IPtr *getRef() const noexcept
        { return m_ref; }

        IPtr *m_ref = nullptr;
    };

    template<typename Type_t>
    class CPtr : public CPtr<void>
    {
    public:
        CPtr() noexcept : CPtr<void>(nullptr)
        {}

        operator Type_t*() const
        {
            return getPtr();
        }

        operator const Type_t*() const
        {
            return getPtr();
        }

        template<typename T>
        operator CPtr<T>()
        {
            binaire::EqualFail<Type_t *, T *>::test();
            const CPtr<T> val(getRef());

            return val;
        }

        template<typename T>
        operator const CPtr<T>() const
        {
            binaire::EqualFail<Type_t *, T *>::test();
            const CPtr<T> val(getRef());

            return val;
        }

        template<typename... Arg_t>
        static CPtr instantiate(Arg_t... arg)
        { return CPtr(new StaticPtr<Type_t>(arg...)); }

        Type_t* getPtr() noexcept
        {  return m_ref==nullptr ? nullptr :  static_cast<Type_t *>(m_ref->getPtr()); }

        const Type_t* getPtr() const noexcept
        { return m_ref==nullptr ? nullptr : static_cast<Type_t *>(m_ref->getPtr()); }

        CPtr &operator=(const CPtr &value) noexcept
        {
            setRef(value.getRef());
            return *this;
        }

        Type_t &operator*()
        { return *getPtr(); }

        Type_t *operator->()
        { return getPtr(); }

        const Type_t &operator*() const
        { return *getPtr(); }

        const Type_t *operator->() const
        { return getPtr(); }

        friend CPtr<Type_t> make_Ptr<Type_t>(Type_t *ptr);

        template<typename T>
        friend class CPtr<T>::CPtr;

    private:
        explicit CPtr(IPtr *ref) noexcept : CPtr<void>(ref)
        {}
    };

    template<typename Type_t>
    CPtr<Type_t> make_Ptr(Type_t *ptr)
    {
        CPtr<Type_t> gest;
        gest.setRef(new BasicPtr<Type_t>(ptr));
        return gest;
    }
}
