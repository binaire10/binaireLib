#pragma once
#include "../binairelib_global.h"
#include "../MyFunction/IFunction.hpp"
#include "../MyFunction/lambda/TFonctor.hpp"
#include "IPtr.hpp"

namespace binaire
{
    template<typename Type>
    class SmartPtr;

    class BINAIRELIBSHARED_EXPORT BaseSmartPtr // Made a protected package for SmartPtr class
    {
    protected:
        class BINAIRELIBSHARED_EXPORT NativeSmartPtr // class in protected package
        {
        public:
            NativeSmartPtr() = delete;
            NativeSmartPtr(const NativeSmartPtr &) = delete;
            NativeSmartPtr &operator =(const NativeSmartPtr &) = delete;
            virtual ~NativeSmartPtr() = 0;
            virtual void *get() noexcept = 0;
            const unsigned &count() const noexcept;
            void newRef() const noexcept;
            bool deleteRef() const noexcept;
        };

        template<typename Type>
        class CPtr : NativeSmartPtr
        {
        public:
            void *get() override
            {
                return &m_Ptr;
            }

        private:
            Type m_Ptr;
            IFunction<void, Type> m_Deleter;
        };

        template<typename Type>
        class CPtr<Type *> : NativeSmartPtr
        {
        public:
            CPtr(Type *&Ptr) noexcept : m_Ptr(Ptr)
            {}

            ~CPtr() noexcept override
            {
                delete m_Ptr;
            }

            void *get() override
            {
                return m_Ptr;
            }

        private:
            Type *m_Ptr;
            IFunction<void, Type*> m_Deleter;
        };

        template<typename Type>
        class CPtr<Type[]> : NativeSmartPtr
        {
        public:
            ~CPtr() noexcept override
            {
                delete[] Value;
            }

            void *get() override
            {
                return m_Ptr;
            }

        private:
            Type *m_Ptr;
            IFunction<void, Type*> m_Deleter;
        };


        NativeSmartPtr *m_Reference;
        BaseSmartPtr() noexcept;
        BaseSmartPtr(NativeSmartPtr *Val) noexcept;
        BaseSmartPtr(const BaseSmartPtr &Val) noexcept;
        BaseSmartPtr(void *Val, const IFunction<void, void *> *Deleter, const bool &autoDelete) noexcept;
        virtual ~BaseSmartPtr() noexcept;

    public:
            class BINAIRELIBSHARED_EXPORT DeleterNothing_t : public IFunction<void, void*>
            {
            public:
                ~DeleterNothing_t() noexcept override;
                void operator() (void *ptr) const noexcept final;
            };

        BaseSmartPtr &operator=(const BaseSmartPtr &Val) noexcept;
        template<typename T>
        friend SmartPtr<T> strong_cast(const BaseSmartPtr &V) noexcept;
    };

    template<typename Type>
    class SmartPtr : public BaseSmartPtr, public IPtr<Type>
    {
    public:
        typedef Type Type_t;
        class Deleter_t : public IFunction<void, void*>
        {
        public:
            ~Deleter_t() noexcept
            {}
            void operator() (void *ptr) const noexcept final
            {delete static_cast<Type *>(ptr);}
        };

    private:
        //static const Deleter_t *m_basicDelete;
    public:
        explicit SmartPtr(Type *, NativeSmartPtr *Val) noexcept : BaseSmartPtr(Val)
        {}

        explicit SmartPtr(Type *ptr, const IFunction<void, void *> *Del = new Deleter_t, const bool &autoDelete = true) noexcept : BaseSmartPtr(static_cast<void *>(ptr), Del, autoDelete)
        {}

        SmartPtr() noexcept
        {
            m_Reference = nullptr;
        }

        static SmartPtr<Type> builSmartPtr(Type *ptr)
        {
            return ptr;
        }

        template<typename T>
        operator SmartPtr<T>() noexcept
        { return SmartPtr<T>(static_cast<Type *>(m_Reference->get()), m_Reference); }

        template<typename T>
        operator const SmartPtr<T>() const noexcept
        { return SmartPtr<T>(static_cast<Type *>(m_Reference->get()), m_Reference); }

        Type &operator*() noexcept override
        { return *static_cast<Type *>(m_Reference->get()); }

        Type *operator->() noexcept override
        { return static_cast<Type *>(m_Reference->get()); }

        Type *GetPtr() noexcept override
        { return m_Reference ? static_cast<Type *>(m_Reference->get()) : nullptr; }

        const Type *GetPtr() const noexcept override
        { return m_Reference ? static_cast<Type *>(m_Reference->get()) : nullptr; }

        const Type &operator*() const noexcept override
        { return *static_cast<Type *>(m_Reference->get()); }

        const Type *operator->() const noexcept override
        { return static_cast<Type *>(m_Reference->get()); }

        // IPtr interface
    public:
        IPtr<Type> *clone() const noexcept override
        {
            return new SmartPtr(*this);
        }
        template<typename T, typename K>
        friend SmartPtr<T> strong_cast(const BaseSmartPtr &V) noexcept;
    };

    template<>
    class SmartPtr<void> : public BaseSmartPtr
    {
    public:
        typedef void Type_t;
        class Deleter_t : public IFunction<void, void*>
        {
        public:
            inline ~Deleter_t() noexcept
            {}
            void operator() (void *) const noexcept final
            {}
        };

    private:
        //static const Deleter_t *m_basicDelete;
    public:
        explicit SmartPtr(void *, NativeSmartPtr *Val) noexcept : BaseSmartPtr(Val)
        {}

        explicit SmartPtr(void *ptr, const IFunction<void, void *> *Del, const bool &autoDelete) noexcept : BaseSmartPtr(ptr, Del, autoDelete)
        {}

        SmartPtr(const SmartPtr &) = default;

        SmartPtr() noexcept
        {
            m_Reference = nullptr;
        }

        template<typename T>
        operator SmartPtr<T>() noexcept
        { return SmartPtr<T>(static_cast<T *>(m_Reference->get()), m_Reference); }

        template<typename T>
        operator const SmartPtr<T>() const noexcept
        { return SmartPtr<T>(static_cast<T *>(m_Reference->get()), m_Reference); }

        void *GetPtr() noexcept
        { return m_Reference ? m_Reference->get() : nullptr; }

        void *GetPtr() const noexcept
        { return m_Reference ? m_Reference->get() : nullptr; }

    };

    template<typename T>
    SmartPtr<T> strong_cast(const BaseSmartPtr &V) noexcept
    { return SmartPtr<T>(static_cast<T *>(V.m_Reference->get()), V.m_Reference); }

    template<typename T>
    inline SmartPtr<T> make_SmartPtr(T *V) noexcept
    { return SmartPtr<T>(V); }
}
