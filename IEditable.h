#pragma once
#include <iostream>

namespace binaire
{
    class IEditable
    {
      protected :
        virtual std::ostream &_Edit (std::ostream &os) const noexcept = 0;

      public :
        virtual ~IEditable () noexcept = default;
    }; // CEditable
}
