/**
 *
 * @file    cexception.cxx
 *
 * @authors M. Laporte, D. Mathieu, Alexandre Sollier
 *
 * @date    23/03/2010
 *
 * @version V1.1
 *
 * @brief  classe CException
 *
 **/

#include <iostream>

#include "cexception.h"

std::ostream& nsException::CException::_Edit(std::ostream& os) const
{ 
    return os << "Exception : " << m_Libelle << '\n'
              << "Code      : " << m_CodErr;
} // _Edit()

