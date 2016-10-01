#include "../include/MySystem/IStream.h"

using namespace binaire;
using namespace System;

IStream::IStream() noexcept : m_replaceMode(false)
{}

bool IStream::replaceMode() const
{
    return m_replaceMode;
}

void IStream::setReplaceMode(bool replaceMode)
{
    m_replaceMode = replaceMode;
}
