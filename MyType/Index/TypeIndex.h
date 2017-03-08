#pragma once

#include <cstdint>
#include <typeindex>
#include <CPtr.h>

namespace binaire
{
    class TypeIndex {
    public:
        virtual ~TypeIndex() noexcept = default;
        virtual size_t getHash() const = undefined;
        virtual std::type_index getTypeIndex() const = undefined;
        virtual bool equal(const TypeIndex &) const = undefined;
        virtual bool equal(const std::type_index &) const = undefined;
    };
}
