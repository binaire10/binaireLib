#pragma once
#include <string>

namespace binaire
{
    namespace System
    {
        enum ExceptDevice
        {
            NotExist,
            unc
        };

        class IDevice
        {
        public:
            enum OpenMode{
                Read =      0b1,
                Write =    0b10,
                Trucate = 0b100,
                Append = 0b1000,
                Text =  0b10000
            };

        protected:
            std::string m_ID;

        public:
            virtual ~IDevice() noexcept = default;
            virtual void open(const OpenMode &Flag) throw() = 0;
            virtual void close() noexcept = 0;
            virtual bool isready() noexcept = 0;
        };
    }
}
