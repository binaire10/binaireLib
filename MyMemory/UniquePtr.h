#pragma once

#include <IPtr.h>

namespace binaire
{
    class UniquePtr : public IPtr
    {
    public:
        UniquePtr() = default;
        virtual ~UniquePtr() = default;

        void *getPtr() override
        {
        }
        unsigned countRef() const override
        {
        }
        const std::type_info &getTypeIndex() override
        {
        }

    protected:
        void newReference() const override
        {
        }
        bool deleteReference() const override
        {
        }

    private:

    };
}
