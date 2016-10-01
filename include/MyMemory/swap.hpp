#pragma once

namespace binaire
{
    template<typename XType, typename YType>
    void swap(XType &Val1, YType &Val2)
    {
        XType save(Val1);
        Val1 = Val2;
        Val2 = save;
    }
}
