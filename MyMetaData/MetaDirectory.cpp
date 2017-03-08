#include "MetaDirectory.h"
#include <algorithm>

using namespace binaire;
using namespace std;

binaire::MetaDirectory::MetaDirectory(const std::string &Name) noexcept : m_Name(Name)
{}

void MetaDirectory::addMetaData(const CPtr<MetaData> &data) noexcept
{
    m_Content.push_back(data);
}

void MetaDirectory::getMetaData(const string &key, std::vector<CPtr<MetaData> > &resul) const noexcept
{
    resul.resize(0);
    resul.reserve(std::count_if(m_Content.begin(), m_Content.end(), [&](const CPtr<MetaData> &data){
        return key == data->getKeyName();
    }));
    for(const CPtr<MetaData> &data : m_Content)
        if(data->getKeyName() == key)
            resul.push_back(data);
}

void MetaDirectory::getMetaData(std::vector<CPtr<MetaData> > &resul) const noexcept
{
    resul.resize(0);
    resul.reserve(m_Content.size());
    resul.insert(resul.begin(), m_Content.begin(), m_Content.end());
}

void MetaDirectory::getMetaDirectory(std::vector<CPtr<MetaDirectory> > &resul) const noexcept
{
    resul.resize(0);
    resul.reserve(std::count_if(m_Content.begin(), m_Content.end(), [&](const CPtr<MetaData> &data){
        return typeid(MetaDirectory) == data->getMetaType();
    }));

    for(const CPtr<MetaData> &data : m_Content)
        if(typeid(MetaDirectory) == data->getMetaType())
            resul.push_back(data.reinterpretCast<MetaDirectory>());
}

string binaire::MetaDirectory::getKeyName() const noexcept
{
    return m_Name;
}

const std::type_info &binaire::MetaDirectory::getMetaType() const noexcept
{
    return typeid(MetaDirectory);
}
