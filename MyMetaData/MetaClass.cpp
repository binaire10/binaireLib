#include "MetaClass.h"
#include <algorithm>

using namespace binaire;

MetaData *MetaClass::getMetaData(std::string key, std::type_index type)
{
    for(MetaData *da : m_metaData)
        if(da->getKeyName() == key && type == da->getMetaType())
            return da;

    return nullptr;
}

const std::vector<MetaData *> &MetaClass::getMetaData() const noexcept
{
    return m_metaData;
}

void MetaClass::addMetaData(MetaData *meta)
{
    for(std::vector<MetaData *>::iterator i(m_metaData.begin()) ; i<m_metaData.end() ;++i)
        if((*i)->getKeyName() == meta->getKeyName() && (*i)->getMetaType() == meta->getMetaType())
        {
            m_metaData.erase(i);
        }
    m_metaData.push_back(meta);
}
