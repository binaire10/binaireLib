#pragma once
#include "CException.h"

template<unsigned CCode, typename CastError>
binaire::CCustomClassException<CCode, CastError>::CCustomClassException(CastError Code) noexcept : m_Code(Code)
{}

template<unsigned CCode, typename CastError>
unsigned binaire::CCustomClassException<CCode, CastError>::getClassCode() const noexcept
{ return CCode; }

template<unsigned CCode, typename CastError>
unsigned binaire::CCustomClassException<CCode, CastError>::getCode() const noexcept
{ return m_Code; }

