#include "InvalideArgument.h"
#include <cxxabi.h>

using namespace std;
using namespace binaire;

InvalideArgument::InvalideArgument(const char *file, int line, const string &msg) noexcept : CodeException(file, line, "InvalideArgument", msg)
{}
