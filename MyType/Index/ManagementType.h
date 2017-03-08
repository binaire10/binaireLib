#pragma once

#include <vector>
#include "TypeGestionary.h"
#include "NativeIndex.h"

namespace binaire
{
    class ManagementType: public TypeGestionary
    {
    public:
        template<typename T>
        TypeIndex *getType() noexcept
        {
            for(TypeIndex *e : m_Types)
                if(e->equal(typeid(T)))
                    return e;
            m_Types.push_back(new NativeIndex<T>);
            return m_Types.back();
        }
    private:
        std::vector<TypeIndex *> m_Types;
    };
}
