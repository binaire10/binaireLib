#pragma once
#include <string>
#include "../MySystem/CException.h"
namespace binaire
{
    namespace System
    {
        enum ExceptFile
        {
            FileNotExist,
            FileNotOpen,
            FileNotAvailable
        };

        typedef CCustomClassException<KNoError, ExceptFile> CCastFileError;

        class IDir;

        class IFileGeneric
        {
        protected:
            IDir *m_Path;
            std::string m_Name;
        public:
            virtual ~IFileGeneric() noexcept = default;
            virtual void remove() throw(const CCastFileError &) = 0;
            virtual void move(const IDir &Dest) throw(const CCastFileError &) = 0;
            virtual void copy(const IFileGeneric &Dest) throw(const CCastFileError &) = 0;
            std::string getPath();
        };
    }
}
