/**
 *
 * @file    ieditable.h
 *
 * @authors D. Mathieu, M. Laporte, Alexandre Sollier
 *
 * @date    16/03/2009
 *
 * @version V2.1
 *
 * @brief   declaration de la classe CEditable dans nsUtil
 *
 **/

#ifndef IEDITABLE_H
#define IEDITABLE_H

#include <iostream>

namespace nsUtil
{

class IEditable
{

public:
    virtual ~IEditable() = default;

    friend std::ostream& operator<<(std::ostream& os, const IEditable& Obj);

protected:
    virtual std::ostream& _Edit(std::ostream& os) const = 0;

}; // class IEditable

std::ostream& operator<<(std::ostream & os, const IEditable & Obj);

} // namespace nsUtil

#include "ieditable.hxx"

#endif // IEDITABLE_H

