#ifndef CTOSQLCONV_H
#define CTOSQLCONV_H

#include "cdesc.h"
#include <sql.h>
#include <sqlext.h>

unsigned long convToSQLBool(SQLPOINTER srcDataPtr, SQLSMALLINT CDataType, SQLPOINTER targetDataPtr, CDescRec* targetDescPtr, ICUConverter* iconv);



#endif
