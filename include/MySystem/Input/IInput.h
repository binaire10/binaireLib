#pragma once
#include <string>
#include "../IStream.h"

namespace binaire
{
    namespace System
    {
        class IInput : public virtual IStream
        {
        public:
            virtual ~IInput() = default;
            virtual void read(std::string &data) = 0;
            virtual size_t read(char *&data, const unsigned &size) = 0;
        };
    }
}
