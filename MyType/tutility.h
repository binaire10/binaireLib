#pragma once
#include <cxxabi.h>
#include <typeinfo>
#include <string>

namespace binaire
{
    inline bool instanceOf(const std::type_info &from, const void *objptr, const std::type_info &to)
    {
        return from.__do_upcast(reinterpret_cast<const abi::__class_type_info *>(&to), &const_cast<void *&>(objptr));
    }

    inline std::string nameOf(const std::type_info &to)
    {
        return abi::__cxa_demangle(to.name(), nullptr, nullptr, nullptr);
    }
}
