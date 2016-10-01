#pragma once
#include "IIOstream.h"
#include <string>
#include "../binairelib_global.h"

namespace binaire
{
    class BINAIRELIBSHARED_EXPORT CStringStream : public System::IIOStream
    {
    public:
        CStringStream() noexcept;
        CStringStream(const std::string &buffer) noexcept;
    private:
        std::string m_Buf;
        unsigned long long m_Offset;

        // IStream interface
    public:
        void move(size_t offset, bool increase) override;
        void moveTo(size_t offset) override;

        // IInput interface
    public:
        void read(std::string &data) override;
        //size_t read(char *&data, const unsigned &size) override;

        // IOutput interface
    public:
        void write(const std::string &data) override;
        void write(const char *const &data, const unsigned &size) override;
        std::string Buf() const;
    };

}
