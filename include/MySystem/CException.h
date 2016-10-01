#pragma once

namespace binaire
{
    class CException
    {
    protected:
        CException() noexcept = default;
        virtual ~CException() noexcept = default;
    public:
        virtual unsigned getCode() const noexcept      = 0;
        virtual unsigned getClassCode() const noexcept = 0;
    };

    template<unsigned CCode, typename CastError>
    class CCustomClassException : public CException
    {
    private:
        CastError m_Code;
    public:
        CCustomClassException(CastError Code) noexcept : m_Code(Code)
        {}

        unsigned getClassCode() const noexcept final
        { return CCode; }

        unsigned getCode() const noexcept final
        { return m_Code; }

        CastError getErrCode() const noexcept
        { return m_Code; }
    };


    enum ErrorCast
    {
        KNoError     = 0,
        KStreamError = 1,
        KDeviceerror = 2,
        KMutexError  = 3
    };
}
