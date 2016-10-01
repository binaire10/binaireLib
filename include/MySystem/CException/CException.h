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
        CCustomClassException(CastError Code) noexcept;

        unsigned getClassCode() const noexcept final;

        unsigned getCode() const noexcept final;
    };

    enum ErrorCast
    {
        KNoError     = 0,
        KStreamError = 1,
        KDeviceerror = 2
    };
}
