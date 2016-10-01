#include "../include/MySystem/CStreamString.h"

using namespace std;
using namespace binaire;

CStringStream::CStringStream() noexcept :  m_Buf(), m_Offset(0)
{}

CStringStream::CStringStream(const string &buffer) noexcept : m_Buf(buffer), m_Offset(0)
{}

std::string CStringStream::Buf() const
{
    return m_Buf;
}

void CStringStream::move(size_t offset, bool increase)
{
    if(increase)
        m_Offset += offset;
    else
        m_Offset -= offset;
}

void CStringStream::moveTo(size_t offset)
{
    if(m_Buf.size()>offset)
        m_Offset = offset;
    else
    {
        throw "nop";
    }
}

void CStringStream::read(string &data)
{
    data = m_Buf.substr(m_Offset);
}
/*
size_t CStringStream::read(char *&data, const unsigned &size)
{
    if(m_Buf.size() <= m_Offset)
        return 0;
    unsigned Available(m_Buf.size() - m_Offset);
    Available = Available<size ? Available : size;
    memcpy(data, m_Buf.data() + m_Offset, Available);
    m_Offset += Available;
    return Available;
}*/

void CStringStream::write(const string &data)
{
    if(m_Offset == m_Buf.size())
        m_Buf.insert(m_Offset, data);
    else
    {
        if(m_replaceMode)
        {
            size_t Rest(m_Buf.size() - m_Offset);
            if(Rest<=data.size())
            {
                m_Buf.resize(m_Buf.size() + (data.size() - Rest));
            }
            m_Buf.replace(m_Offset, string::npos, data);
        }
        else
            m_Buf.insert(m_Offset, data);
    }
    m_Offset += data.size();
}

void CStringStream::write(const char *const &data, const unsigned &size)
{
    if(m_Offset == m_Buf.size())
        m_Buf.insert(m_Offset, data, size);
    else
    {
        if(m_replaceMode)
        {
            size_t Rest(m_Buf.size() - m_Offset);
            if(Rest<=size)
            {
                m_Buf.resize(m_Buf.size() + (size - Rest));
            }
            m_Buf.replace(m_Offset, string::npos, data, size);
        }
        else
            m_Buf.insert(m_Offset, data, size);
    }
    m_Offset += size;
}
