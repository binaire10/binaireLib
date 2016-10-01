#pragma once
#include "../binairelib_global.h"

namespace binaire
{
    namespace System
    {
        class BINAIRELIBSHARED_EXPORT IStream
        {
        public:
            typedef unsigned long long size_t;
            IStream() noexcept;
            virtual ~IStream() noexcept = default;
            virtual void move(unsigned long long offset, bool increase = true) = 0;
            virtual void moveTo(unsigned long long offset) = 0;
            bool replaceMode() const;
            void setReplaceMode(bool replaceMode);

        protected:
            bool m_replaceMode;
        };
    }
}
