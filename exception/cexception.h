/**
 *
 * @file    cexception.h
 *
 * @authors M. Laporte, D. Mathieu, Alexandre Sollier
 *
 * @date    23/03/2010
 *
 * @version V1.1
 *
 * @brief   Declaration de la classe CException
 *
 **/

#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#include <string>
#include <iostream>
#include <exception>

#include "../tools/ieditable.h"
#include "errcode.h"

/**
 * @namespace nsException
 * @brief Espace de nom pour la gestion d'exceptions
 */
namespace nsException
{

class CException : public std::exception, public nsUtil::IEditable
{

public :
    CException(const std::string& Libelle = std::string(), const unsigned CodErr = KNoExc);
    virtual ~CException() = default;

    const std::string& GetLibelle() const;
    unsigned GetCodErr() const;

    virtual const char* what() const noexcept override;

protected :
    virtual std::ostream& _Edit(std::ostream& os = std::cerr) const override;

    std::string m_Libelle;
    unsigned m_CodErr;

}; // class CException
    
} // namespace nsException

#include "cexception.hxx"

#endif // CEXCEPTION_H

