#pragma once
#include <string>
#include <CPtr.h>
#include <Rule/WordRule.h>
#include "MetaDirectory.h"
#include "futility.h"

namespace binaire
{
    class Registry
    {
    public:
        Registry() = default;
        void mkpath(const std::string &path);
        CPtr<MetaDirectory> getDirectory(const std::string &path);
        //void getMetaData(const std::string &path, std::vector< CPtr<MetaData> > &);

    private:
        CPtr<MetaDirectory> m_Root = CPtr<MetaDirectory>::instantiate(MetaDirectory("/"));
        DynamicParser m_pathParse = ([](){
                typedef bool (*func_t)(char value);
                DynamicParser parse;
                parse.addParseur(CPtr<WordRule>::instantiate(binaire::make_FunctionPtr(static_cast<func_t>([](char value){
                    return static_cast<bool>(value != '/');
                }))));
                return parse;
            })();
    };
}
