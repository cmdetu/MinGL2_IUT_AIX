#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include "CException.h"
#include "CstCodErr.h"

class MyException : public nsUtil::CException
{
public:
    MyException(const unsigned & code);
};

#endif // MYEXCEPTION_H
