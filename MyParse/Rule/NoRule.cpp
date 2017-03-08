#include "NoRule.h"

using namespace binaire;

std::string::const_iterator NoRule::next(std::string::const_iterator, const std::string::const_iterator &end)
{
    return end;
}

std::string::const_iterator NoRule::nextEnd(std::string::const_iterator, const std::string::const_iterator &end)
{
    return end;
}

size_t NoRule::beginSize() const noexcept
{
    return 0;
}
