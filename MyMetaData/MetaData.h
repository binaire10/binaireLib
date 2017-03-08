#pragma once
#include <typeindex>
#include <string>

namespace binaire
{
    class MetaData
    {
    public:
        virtual ~MetaData() = default;
        virtual std::string getKeyName() const = undefined;
        virtual const std::type_info &getMetaType() const = undefined;
    };
}
