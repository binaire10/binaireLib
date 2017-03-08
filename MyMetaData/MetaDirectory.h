#pragma once

#include <list>
#include <vector>
#include "MetaData.h"
#include <CPtr.h>
#include <DynamicParser.h>

namespace binaire
{
    class MetaDirectory : public MetaData
    {
    public:
        void addMetaData(const CPtr<MetaData> &) noexcept;
        void getMetaData(const std::string &, std::vector<CPtr<MetaData> > &) const noexcept;
        void getMetaData(std::vector<CPtr<MetaData> > &) const noexcept;
        void getMetaDirectory(std::vector<CPtr<MetaDirectory> > &) const noexcept;
        std::string getKeyName() const noexcept override;
        const std::type_info &getMetaType() const noexcept override;

    private:
        friend class Registry;
        MetaDirectory(const std::string &) noexcept;
        std::list< CPtr<MetaData> > m_Content = defaultvalue;
        std::string m_Name;
    };
}
