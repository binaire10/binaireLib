#pragma once
#include <iostream>

namespace binaire
{
    class IDumpable
    {
    public:
        IDumpable() noexcept = default;
        virtual std::ostream & operator<< (std::ostream & os) const = 0;

    };
}
