#pragma once

#include <typeindex>
#include <string>
#include <vector>
#include "MetaData.h"

namespace binaire
{
    class MetaClass {
    public:
        virtual ~MetaClass() = default;
        MetaData *getMetaData(std::string key, std::type_index type);
        const std::vector<MetaData *> &getMetaData() const noexcept;
        void addMetaData(MetaData *meta);

    private:
        std::vector<MetaData *> m_metaData = defaultvalue;
    };
}
