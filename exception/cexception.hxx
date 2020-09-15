/**
 *
 * @file    cexception.hxx
 *
 * @authors M. Laporte, D. Mathieu, Alexandre Sollier
 *
 * @date    23/03/2010
 *
 * @version V1.1
 *
 * @brief   classe CException
 *
 **/

#ifndef CEXCEPTION_HXX
#define CEXCEPTION_HXX

#include <string>

#include "cexception.h"

inline nsException::CException::CException(const std::string& Libelle /* = std::string () */, const unsigned CodErr  /* = KNoExc */)
    : m_Libelle (Libelle)
    , m_CodErr (CodErr)
{} // CException()

inline const std::string& nsException::CException::GetLibelle() const
{
    return m_Libelle;
} // GetLibelle()

inline unsigned nsException::CException::GetCodErr() const
{
    return m_CodErr;
} // GetCoderr()

inline const char* nsException::CException::what() const noexcept
{
    return m_Libelle.c_str();
} // what()

#endif // CEXCEPTION_HXX

