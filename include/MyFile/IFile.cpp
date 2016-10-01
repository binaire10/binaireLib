#include "IFile.h"
#include "IDir.h"


using namespace std;
using namespace binaire::System;

string IFileGeneric::getPath()
{
    return (m_Path!=nullptr ? m_Path->getPath() : "") + '/' + m_Name;
}
