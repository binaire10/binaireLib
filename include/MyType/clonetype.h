#pragma once

namespace binaire
{
    namespace expiremental
    {
        template<typename Type>
        class CloneType
        {
        public:
            Type cxx_Construct()
            { return Type(); }

            template<typename... Arg_t>
            Type cxx_Construct(Arg_t ...arg)
            { return Type(arg...); }
        };
    }
}
