#pragma once
#include <vector>
#include "IFile.h"

namespace binaire
{
    namespace System
    {
        class IDir : public IFileGeneric
        {
        protected:
            IDir *m_Parent = nullptr;
        public:
            virtual void addFile(IFileGeneric &)  throw(const CCastFileError &) = 0;
        };
    }
}
