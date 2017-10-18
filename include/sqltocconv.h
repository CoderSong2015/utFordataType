#ifndef SQLTOCCONV_H
#define SQLTOCCONV_H

#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include "cdesc.h"
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>


unsigned long ConvertSQLToC(SQLINTEGER      ODBCAppVersion,
                            DWORD           DataLangId,
                            CDescRec*       srcDescPtr,
                            SQLSMALLINT     SQLDataType,
                            SQLPOINTER      srcDataPtr,
                            SQLINTEGER      srcLength,
                            SQLSMALLINT     CDataType,
                            SQLPOINTER      targetDataPtr,
                            SQLINTEGER      targetLength,
                            SQLLEN*         targetStrLenPtr,
                            BOOL            bigEndian,
#ifdef unixcli
                            ICUConverter*   iconv,
#else
                            DWORD           translateOption = 0,
#endif
                            SQLINTEGER*     totalReturnedLength = NULL,//offset in Input
                            UCHAR*          errorMsg = NULL,
                            SWORD           errorMsgMax = 0,
                            SQLINTEGER      EnvironmentType = NSK_BUILD_1,
                            BOOL            ColumnwiseData = FALSE,//catalog api set TRUE
                            CHAR*           replacementChar = NULL
                            );


unsigned long convSQLNumberToNumber(SQLPOINTER srcDataPtr, CDescRec* srcDescPtr, SQLSMALLINT SQLDataType, SQLPOINTER targetDataPtr, SQLLEN* targetStrLenPtr, SQLSMALLINT CDataType);
unsigned long ConvFromSQLBool(SQLPOINTER srcDataPtr, SQLPOINTER targetDataPtr, SQLINTEGER targetLength, SQLLEN* targetStrLenPtr, SQLSMALLINT CDataType);
unsigned long ConvDoubleToCNumber(double dTmp, SQLPOINTER targetDataPtr, SQLLEN* targetStrLenPtr, SQLSMALLINT CDataType);
unsigned long ConvInt64ToCNumber(__int64 tempVal64, __uint64 utempVal64, bool unsignedValue, SQLPOINTER targetDataPtr, SQLLEN* targetStrLenPtr, SQLSMALLINT CDataType);





#endif
