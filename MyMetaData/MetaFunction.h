#pragma once

#include <typeindex>
#include <string>
#include "MetaData.h"


namespace binaire
{
    template<typename Func_t>
    class MetaFunction: public MetaData {
    public:
        std::string getKeyName() const noexcept override
        {
            return m_key;
        }

        const std::type_info &getMetaType() const noexcept override
        {
            return typeid(MetaFunction<Func_t>);
        }

        Func_t getFunction()
        {
            return m_function;
        }

        void setValue(Func_t value)
        {
            this->m_function = m_function;
        }

    private:
        std::string m_key = {};
        Func_t m_function = {};
    };
}
