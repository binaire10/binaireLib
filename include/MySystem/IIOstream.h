#pragma once
#include "Input/IInput.h"
#include "Output/IOutput.h"

namespace binaire
{
    namespace System
    {
        class IIOStream : public virtual IOutput, public virtual IInput
        {
        public:
            virtual ~IIOStream() override = default;
        };
    }
}
