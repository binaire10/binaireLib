#include "CPtr.h"

using namespace binaire;

int main()
{
    CPtr<char> k = CPtr<char>::instantiate('"');
    return 0;
}
