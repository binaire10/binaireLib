#include "Registry.h"
#include <stdexcept>
#include <iostream>

using namespace binaire;

void Registry::mkpath(const std::string &path)
{
    m_pathParse.setInput({path.begin(), path.end()});
    CPtr<MetaDirectory> current = m_Root;
    std::string dirName;
    while (m_pathParse.next())
    {
        std::vector<CPtr<MetaData> > value;
        current->getMetaData(dirName = m_pathParse.getResult(), value);
        std::vector<CPtr<MetaData> >::iterator ivalue = value.begin();

        while(ivalue != value.end() && (*ivalue)->getMetaType() != typeid(MetaDirectory))
        {
            ++ivalue;
        }
        if(ivalue == value.end())
        {
            CPtr<MetaDirectory> newDir;
            do
            {
                newDir = CPtr<MetaDirectory>::instantiate(MetaDirectory(m_pathParse.getResult()));
                current->addMetaData(newDir);
                current = newDir;
            } while(m_pathParse.next());
        }
        else
            current = ivalue->reinterpretCast<MetaDirectory>();
    }
}

CPtr<MetaDirectory> Registry::getDirectory(const std::string &path)
{
    m_pathParse.setInput({path.begin(), path.end()});
    CPtr<MetaDirectory> current = m_Root;
    while (m_pathParse.next())
    {
        std::vector<CPtr<MetaData> > value;
        current->getMetaData(m_pathParse.getResult(), value);
        if(value.size() == 0)
            throw std::runtime_error("invalide path");
        std::vector<CPtr<MetaData> >::iterator ivalue = value.begin();

        while(ivalue != value.end() && (*ivalue)->getMetaType() != typeid(MetaDirectory))
        {
            ++ivalue;
        }
        if(ivalue == value.end())
            throw std::runtime_error("invalide path");
        current = ivalue->reinterpretCast<MetaDirectory>();
    }
    return current;
}
/*
void Registry::getMetaData(const std::string &path, std::vector<CPtr<MetaData> > &result)
{
    result.clear();
    std::list<std::string> key;
    m_pathParse.setInput({path.begin(), path.end()});
    DynamicParser::
    while(m_pathParse.next())
        key.push_back(m_pathParse.getResult());

    if(key.size() == 0)
        return;
    for(std::list<std::string>::const_iterator i(key.begin()), end(key.end() -1);i != end; ++i)
    {

    }
}
*/
