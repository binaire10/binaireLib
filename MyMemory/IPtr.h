#pragma once
#include <typeindex>


namespace binaire
{
    template<typename Type_t> class CPtr;
    class IPtr {
    public:
        virtual ~IPtr() = default;

        virtual void* getPtr() noexcept = undefined;
        virtual unsigned countRef() const noexcept = undefined;
        virtual const std::type_info &getTypeIndex() = undefined;

    protected:
        virtual void newReference() const noexcept = undefined;
        virtual bool deleteReference() const noexcept = undefined;
        template<typename Type_t> friend class CPtr;
    };
}
