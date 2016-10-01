#pragma once

namespace binaire
{
    template<class X>
    class IPtr
    {
    public:
        typedef X* ptr_t;
        virtual ~IPtr() = default;
        virtual X &operator*() noexcept  = 0;
        virtual X *operator->() noexcept = 0;
        virtual X *GetPtr() noexcept = 0;

        virtual const X &operator*() const noexcept  = 0;
        virtual const X *operator->() const noexcept = 0;
        virtual const X *GetPtr() const noexcept = 0;
        bool operator==(const IPtr &A) const noexcept
        {
            return A.GetPtr() == GetPtr();
        }
        operator bool() const noexcept
        {
            return GetPtr() != nullptr;
        }
        virtual IPtr *clone() const noexcept = 0;
    };
}
