#pragma once

#include <typeindex>
#include <string>
#include "MetaData.h"
#include "../MyFunction/MetaTemplate/MetaType.hpp"


namespace binaire
{
    template<typename Type_t>
    class MetaValue: public MetaData {
    public:
        MetaValue(const std::string &key, const Type_t &value) noexcept : m_key(key), m_value(value)
        {}
        std::string getKeyName() const noexcept override
        {
            return m_key;
        }

        const std::type_info &getMetaType() const noexcept override
        {
            return typeid(MetaValue<Type_t>);
        }

        Type_t getValue()
        {
            return m_value;
        }

        void setValue(const Type_t &value)
        {
            this->m_value = m_value;
        }

    private:
        std::string m_key;
        Type_t m_value;
    };
}
