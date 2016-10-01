#pragma once
#include "../binairelib_global.h"
#include "IIOstream.h"
#include "../MyMemory/SmartPtr.hpp"
#include "Mutex/IMutex.h"

namespace binaire
{
    namespace System
    {
        class BINAIRELIBSHARED_EXPORT Console : public IIOStream
        {
        public:
            Console() noexcept;
            ~Console() override = default;

            // IOutput interface
            void write(const std::string &data) override;
            void write(const char *const &data, const unsigned &size) override;

            // IInput interface

            void read(std::string &data) override;
            //size_t read(char *&data, const unsigned &size) override;
        private:
            SmartPtr<IMutex> m_Mutex;

            // IStream interface
        public:
            void move(unsigned long long offset, bool increase) override;
            void moveTo(unsigned long long offset) override;
        };
    }
}
