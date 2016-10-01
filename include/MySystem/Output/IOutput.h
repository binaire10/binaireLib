#pragma once
#include <string>
#include "../IStream.h"

namespace binaire
{
    namespace System
    {
        class IOutput : public virtual IStream
        {
        public:
            virtual ~IOutput() = default;
            virtual void write(const std::string &data) = 0;
            virtual void write(const char * const &data, const unsigned &size) = 0;
        };
    }
}
