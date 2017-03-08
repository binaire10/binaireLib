#pragma once

#include "TypeIndex.h"


namespace binaire
{
    template<typename Type_t >
    class NativeIndex: public TypeIndex
    {
    public:
        size_t getHash() const override
        {
            return typeid(Type_t).hash_code();
        }
        bool equal(const TypeIndex &a) const override
        {
            return a.getTypeIndex() == typeid(Type_t);
        }
        bool equal(const std::type_index &a) const override
        {
            return a == typeid(Type_t);
        }
        std::type_index getTypeIndex() const override
        {
            return typeid(Type_t);
        }
    };
}
