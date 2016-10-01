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
        private:
            void *m_ptr = nullptr;
            mutable unsigned m_count = 0;
            const IFunction<void,void *> *m_Deleter;
            bool m_AutoDelete;
        public:
            NativeSmartPtr() = delete;
            NativeSmartPtr(const NativeSmartPtr &) = delete;
            NativeSmartPtr &operator =(const NativeSmartPtr &) = delete;

            NativeSmartPtr(void *ptr, const IFunction<void, void *> *Deleter, const bool &autoDelete) noexcept;
            ~NativeSmartPtr() noexcept;
            void *get() noexcept;
            const unsigned &count() const noexcept;
            void newRef() const noexcept;
            bool deleteRef() const noexcept;
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
            ~Deleter_t() noexcept;
            void operator() (void *ptr) const noexcept final;
        };
        SmartPtr() noexcept;
        explicit SmartPtr(Type *, NativeSmartPtr *Val) noexcept;
        explicit SmartPtr(Type *ptr, const IFunction<void, void *> *Del = new Deleter_t, const bool &autoDelete = true) noexcept;

        template<typename T>
        operator SmartPtr<T>() noexcept;
        template<typename T>
        operator const SmartPtr<T>() const noexcept;
        Type &operator*() noexcept override;
        Type *operator->() noexcept override;
        Type *GetPtr() noexcept override;
        const Type *GetPtr() const noexcept override;
        const Type &operator*() const noexcept override;
        const Type *operator->() const noexcept override;
        IPtr<Type> *clone() const noexcept override;

        template<typename T, typename K>
        friend SmartPtr<T> strong_cast(const BaseSmartPtr &V) noexcept;
    };

    template<>
    class BINAIRELIBSHARED_EXPORT SmartPtr<void> : public BaseSmartPtr
    {
    public:
        SmartPtr() noexcept;
        explicit SmartPtr(void *, NativeSmartPtr *Val) noexcept;
        explicit SmartPtr(void *ptr, const IFunction<void, void *> *Del, const bool &autoDelete) noexcept;
        SmartPtr(const SmartPtr &) = default;

        template<typename T>
        operator SmartPtr<T>() noexcept;
        template<typename T>
        operator const SmartPtr<T>() const noexcept;
        void *GetPtr() noexcept;
        void *GetPtr() const noexcept;
        typedef void Type_t;
        class Deleter_t : public IFunction<void, void*>
        {
        public:
            inline ~Deleter_t() noexcept;
            void operator() (void *) const noexcept final;
        };
    };

    template<typename T>
    inline SmartPtr<T> strong_cast(const BaseSmartPtr &V) noexcept;

    template<typename T>
    inline SmartPtr<T> make_SmartPtr(T *V) noexcept;
}
