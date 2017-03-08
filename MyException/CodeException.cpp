#include "CodeException.h"
#include <string.h>

using namespace std;
using namespace binaire;

CodeException::CodeException(const char *file, int line, const std::string &excpClass, const string &msg) noexcept : m_Msg(string() + "[" + excpClass + "][" + file + "][" + to_string(line) + "] : " + msg)
{}

const char *CodeException::what() const noexcept
{
    return m_Msg.data();
}
