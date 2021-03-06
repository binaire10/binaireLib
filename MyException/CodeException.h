#pragma once

#include <exception>
#include <string>
#include <cxxabi.h>

namespace binaire
{
    template <typename I> std::string n2hexstr(I w, size_t hex_len = sizeof(I)<<1)
    {
        static const char* digits = "0123456789ABCDEF";
        std::string rc(hex_len,'0');
        for (size_t i=0, j=(hex_len-1)*4 ; i<hex_len; ++i,j-=4)
            rc[i] = digits[(w>>j) & 0x0f];
        return std::string() + "0x" + rc;
    }

    class CodeException : public std::exception
    {
    public:
        CodeException(const char *file, int line, const std::string &excpClass, const std::string &msg) noexcept;
        template<typename T>
        CodeException(const char *file, int line, const std::string &excpClass, const std::string &msg, const T &obj) noexcept : m_Msg(std::string() + '[' + abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, nullptr) + '@' + n2hexstr<unsigned long long>(reinterpret_cast<unsigned long long>(&obj)) + "][" + excpClass + "][" + file + "][" + std::to_string(line) + "] : " + msg)
        {}
        CodeException(const CodeException &) = default;
        CodeException &operator=(const CodeException &) = default;
        const char *what() const noexcept override;
    private:
        const std::string m_Msg;
    };
}
