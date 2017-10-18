#include "sqltocconv.h"

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
                            DWORD           translateOption,
#endif
                            SQLINTEGER*     totalReturnedLength,
                            UCHAR*          errorMsg,
                            SWORD           errorMsgMax,
                            SQLINTEGER      EnvironmentType,
                            BOOL            ColumnwiseData,
                            CHAR*           replacementChar
                            )
{
    unsigned long   retCode     = SQL_SUCCESS;

    if (errorMsg != NULL)
        *errorMsg = '\0';
    
    if (srcDataPtr == NULL)
        return IDS_HY_000;

    DataLangId = LANG_NEUTRAL;

//    if (totalReturnedLength != NULL)

//    if (CDataType == SQL_C_DEFAULT)
//        getCDefault(srcDescPtr->m_ODBCDataType, ODBCAppVersion,srcCharSet,CDataType);

    switch (CDataType)
    {
    case SQL_C_CHAR:
        switch (srcDescPtr->m_ODBCDataType)
        {
        case SQL_CHAR:
            if (SQLDataType == SQLTYPECODE_BOOLEAN)
            {
                ConvFromSQLBool(srcDataPtr, targetDataPtr, targetLength, targetStrLenPtr, CDataType);
                break;
            }
        }
    case SQL_C_WCHAR:
//        convSQLCharToChar()
        break;

    case SQL_C_BINARY:
        break;

    case SQL_C_TINYINT:
    case SQL_C_STINYINT:
    case SQL_C_BIT:
    case SQL_C_UTINYINT:
    case SQL_C_SHORT:
    case SQL_C_SSHORT:
    case SQL_C_USHORT:
    case SQL_C_LONG:
    case SQL_C_SLONG:
    case SQL_C_ULONG:
    case SQL_C_SBIGINT:
    case SQL_C_UBIGINT:
    case SQL_C_FLOAT:
    case SQL_C_DOUBLE:
        switch (srcDescPtr->m_ODBCDataType)
        {
        case SQL_CHAR:
            if (SQLDataType == SQLTYPECODE_BOOLEAN)
            {
                ConvFromSQLBool(srcDataPtr, targetDataPtr, targetLength, targetStrLenPtr, CDataType);
                break;
            }
        case SQL_WCHAR:
        case SQL_VARCHAR:
        case SQL_WVARCHAR:
        case SQL_LONGVARCHAR:
//            convSQLCharToNumeber();
            break;

        case SQL_TINYINT:
        case SQL_SMALLINT:
        case SQL_INTEGER:
        case SQL_BIGINT:
        case SQL_REAL:
        case SQL_DOUBLE:
            retCode = convSQLNumberToNumber(srcDataPtr, srcDescPtr, SQLDataType, targetDataPtr, targetStrLenPtr, CDataType);
            break;
        case SQL_NUMERIC:
        default:
            return IDS_07_006;
        }
        break;

    case SQL_C_DATE:
    case SQL_C_TYPE_DATE:
        break;
        
    case SQL_C_TIME:
    case SQL_C_TYPE_TIME:
        break;

    case SQL_C_TIMESTAMP:
    case SQL_C_TYPE_TIMESTAMP:
        break;

    case SQL_C_NUMERIC:
        break;

    case SQL_C_INTERVAL_MONTH:
    case SQL_C_INTERVAL_YEAR:
    case SQL_C_INTERVAL_YEAR_TO_MONTH:
    case SQL_C_INTERVAL_DAY:
    case SQL_C_INTERVAL_HOUR:
    case SQL_C_INTERVAL_MINUTE:
    case SQL_C_INTERVAL_SECOND:
    case SQL_C_INTERVAL_DAY_TO_HOUR:
    case SQL_C_INTERVAL_DAY_TO_MINUTE:
    case SQL_C_INTERVAL_DAY_TO_SECOND:
    case SQL_C_INTERVAL_HOUR_TO_MINUTE:
    case SQL_C_INTERVAL_HOUR_TO_SECOND:
    case SQL_C_INTERVAL_MINUTE_TO_SECOND:
        break;

    default:
        return IDS_07_006;
    }

    return retCode;
}


unsigned long convSQLNumberToNumber(SQLPOINTER srcDataPtr, CDescRec* srcDescPtr, SQLSMALLINT SQLDataType, SQLPOINTER targetDataPtr, SQLLEN* targetStrLenPtr, SQLSMALLINT CDataType)
{
    unsigned long       retCode = SQL_SUCCESS;

    double              dTmp = 0;
    __int64             tempVal64 = 0;
    __uint64            utempVal64 = 0;

    bool                useDouble = TRUE;

    switch (srcDescPtr->m_ODBCDataType)
    {
        case SQL_TINYINT:
            if (srcDescPtr->m_DescUnsigned)
            {
                dTmp = *((UCHAR *) srcDataPtr);
            }
            else
            {
                dTmp = *((SCHAR *) srcDataPtr);
            }
            break;

        case SQL_SMALLINT:
            if (srcDescPtr->m_DescUnsigned)
            {
                dTmp = *((USHORT *) srcDataPtr);
            }
            else
            {
                dTmp = *((SSHORT *) srcDataPtr);
            }
            break;

        case SQL_INTEGER:
            if (srcDescPtr->m_DescUnsigned)
            {
                dTmp = *((ULONG_P *) srcDataPtr);
            }
            else
            {
                dTmp = *((SLONG_P *) srcDataPtr);
            }
            break;
            
        case SQL_BIGINT:
            if (srcDescPtr->m_DescUnsigned)
            {
                utempVal64 = *((__uint64 *) srcDataPtr);
            }
            else
            {
                tempVal64 = *((__int64 *) srcDataPtr);
            }
            useDouble = FALSE;
            break;

        case SQL_REAL:
            dTmp = *(SFLOAT *)srcDataPtr;
/*            if ((SQLDataType == SQLTYPECODE_DECIMAL_LARGE_UNSIGNED) ||
                (SQLDataType == SQLTYPECODE_DECIMAL_LARGE))
            {
                if (ConvertSoftDecimalToDouble(SQLDataType, srcDataPtr, srcLength, srcScale,dTmp)  != SQL_SUCCESS)
                    return IDS_07_006;
            }
            else*/
            break;
        case SQL_DOUBLE:
                dTmp =  *(DOUBLE *)srcDataPtr;
            break;

        default:
			return IDS_07_006;
    }
    if (useDouble)
        ConvDoubleToCNumber(dTmp, targetDataPtr, targetStrLenPtr, CDataType);
    else
    {
        ConvInt64ToCNumber(tempVal64, utempVal64, srcDescPtr->m_DescUnsigned, targetDataPtr, targetStrLenPtr, CDataType);
    }

    return retCode;
}


unsigned long ConvFromSQLBool(SQLPOINTER srcDataPtr, SQLPOINTER targetDataPtr, SQLINTEGER targetLength, SQLLEN* targetStrLenPtr, SQLSMALLINT CDataType)
{
    SQLRETURN   retCode  = SQL_SUCCESS;
    double      dTmp     = 0;
    SQLINTEGER  DataLen  = 0;
//    rTrim((char *)srcDataPtr);
    DataLen = strlen((char *)srcDataPtr);
    switch (CDataType)
    {
        case SQL_C_CHAR:
            if (DataLen + 1 > targetLength)
                return IDS_22_003;
            *targetStrLenPtr = snprintf((char *)targetDataPtr, targetLength, "%s", srcDataPtr);
            break;
            
        case SQL_C_WCHAR:
            if (DataLen * 2 + 1 > targetLength)
                return IDS_22_003;
            *targetStrLenPtr = swprintf((wchar_t *)targetDataPtr, targetLength, L"%s", srcDataPtr);
            break;

        case SQL_C_BIT:
        case SQL_C_TINYINT:
        case SQL_C_STINYINT:
        case SQL_C_UTINYINT:
        case SQL_C_SHORT:
        case SQL_C_SSHORT:
        case SQL_C_USHORT:
        case SQL_C_LONG:
        case SQL_C_SLONG:
        case SQL_C_ULONG:
        case SQL_C_SBIGINT:
        case SQL_C_UBIGINT:
        case SQL_C_FLOAT:
        case SQL_C_DOUBLE:
            dTmp = strtod((char*)srcDataPtr, NULL);
            retCode = ConvDoubleToCNumber(dTmp, targetDataPtr, targetStrLenPtr, CDataType);
            break;
        default:
            return IDS_07_006;
    }
    
    return retCode;
}


unsigned long ConvDoubleToCNumber(double dTmp, SQLPOINTER targetDataPtr, SQLLEN* targetStrLenPtr, SQLSMALLINT CDataType)
{
    unsigned long       retCode = SQL_SUCCESS;

    switch (CDataType)
    {
        case SQL_C_TINYINT:
        case SQL_C_STINYINT:
            if (dTmp < SCHAR_MIN || dTmp > SCHAR_MAX)
                return IDS_22_003;
            *((SCHAR *)targetDataPtr) = (SCHAR)dTmp;    
            if (*((SCHAR *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(SCHAR); 
            break;

        case SQL_C_BIT:
            if(dTmp < 0 || dTmp > 2)
                return IDS_22_003; 
        case SQL_C_UTINYINT:
            if (dTmp < 0 || dTmp > UCHAR_MAX)
                return IDS_22_003;
            *((UCHAR *)targetDataPtr) = (UCHAR)dTmp;
            if (*((UCHAR *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(UCHAR); 
            break;

        case SQL_C_SHORT:
        case SQL_C_SSHORT:
            if (dTmp < SHRT_MIN || dTmp > SHRT_MAX)
                return IDS_22_003;
            *((SHORT *)targetDataPtr) = (SHORT)dTmp;
            if (*((SHORT *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(SHORT); 
            break;

        case SQL_C_USHORT:
            if (dTmp < 0 || dTmp > USHRT_MAX)
                return IDS_22_003;
            *((USHORT *)targetDataPtr) = (USHORT)dTmp;
            if (*((USHORT *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(USHORT); 
            break;

        case SQL_C_LONG:
        case SQL_C_SLONG:
            if (dTmp < LONG_MIN || dTmp > LONG_MAX)
                return IDS_22_003;
            *((SLONG_P *)targetDataPtr) = (SLONG_P)dTmp;
            if (*((SLONG_P *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(SLONG_P); 
            break;

        case SQL_C_ULONG:
            if (dTmp < 0 ||dTmp > ULONG_MAX)
                return IDS_22_003;
            *((ULONG_P *)targetDataPtr) = (ULONG_P)dTmp;
            if (*((ULONG_P *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(ULONG_P); 
            break;

        case SQL_C_SBIGINT:
            if (dTmp < LLONG_MIN || dTmp > LLONG_MAX)
                return IDS_22_003;
            *((__int64 *)targetDataPtr) = (__int64)dTmp;
            if (*((__int64 *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(__int64); 
            break;

        case SQL_C_UBIGINT:
            if (dTmp < 0 || dTmp > ULLONG_MAX)
                return IDS_22_003;
            *((__uint64 *)targetDataPtr) = (__uint64)dTmp;
            if (*((__uint64 *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(__uint64); 
            break;

        case SQL_C_FLOAT:
            if (dTmp < -FLT_MAX || dTmp > FLT_MAX)
                return IDS_22_003;
            *((SQLFLOAT *)targetDataPtr) = (SQLFLOAT)dTmp;
            if (*((SQLFLOAT *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(SQLFLOAT); 
            break;

        case SQL_C_DOUBLE:
            *((SQLDOUBLE *)targetDataPtr) = dTmp;
            if (*((SQLDOUBLE *)targetDataPtr) != dTmp)
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(SQLDOUBLE); 
            break;

        default:
			return IDS_07_006;
    }

    return retCode;
}


unsigned long ConvInt64ToCNumber(__int64 tempVal64, __uint64 utempVal64, bool unsignedValue, SQLPOINTER targetDataPtr, SQLLEN* targetStrLenPtr, SQLSMALLINT CDataType)
{
    unsigned long       retCode = SQL_SUCCESS;

    switch (CDataType)
    {
        case SQL_C_TINYINT:
        case SQL_C_STINYINT:
            if (tempVal64 < SCHAR_MIN || tempVal64 > SCHAR_MAX)
                return IDS_22_003;
            *((SCHAR *)targetDataPtr) = (unsignedValue ?
                                        (SCHAR)utempVal64: (SCHAR)tempVal64);
            if (*((SCHAR *)targetDataPtr) != (unsignedValue ?
                                        (SCHAR)utempVal64: (SCHAR)tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(SCHAR); 
            break;

        case SQL_C_BIT:
            if (unsignedValue && (utempVal64 < 0 || utempVal64 > 1))
                return IDS_22_003;
            if (!unsignedValue && (tempVal64 < 0 || tempVal64 > 1))
                return IDS_22_003;
        case SQL_C_UTINYINT:
            if (tempVal64 > UCHAR_MAX)
                return IDS_22_003;
            *((UCHAR *)targetDataPtr) = (unsignedValue ?
                                        (UCHAR)utempVal64: (UCHAR)tempVal64);
            if (*((UCHAR *)targetDataPtr) != (unsignedValue ?
                                        (UCHAR)utempVal64: (UCHAR)tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(UCHAR); 
            break;

        case SQL_C_SHORT:
        case SQL_C_SSHORT:
            if (tempVal64 < SHRT_MIN || tempVal64 > SHRT_MAX)
                return IDS_22_003;
            *((SHORT *)targetDataPtr) = (unsignedValue ?
                                        (SHORT)utempVal64: (SHORT)tempVal64);
            if (*((SHORT *)targetDataPtr) != (unsignedValue ?
                                        (SHORT)utempVal64: (SHORT)tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(SHORT); 
            break;

        case SQL_C_USHORT:
            if (tempVal64 > USHRT_MAX)
                return IDS_22_003;
            *((USHORT *)targetDataPtr) = (unsignedValue ?
                                        (USHORT)utempVal64: (USHORT)tempVal64);
            if (*((USHORT *)targetDataPtr) != (unsignedValue ?
                                        (USHORT)utempVal64: (USHORT)tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(USHORT); 
            break;

        case SQL_C_LONG:
        case SQL_C_SLONG:
            if (tempVal64 < LONG_MIN || tempVal64 > LONG_MAX)
                return IDS_22_003;
            *((SLONG_P *)targetDataPtr) = (unsignedValue ?
                                        (SLONG_P)utempVal64: (SLONG_P)tempVal64);
            if (*((SLONG_P *)targetDataPtr) != (unsignedValue ?
                                        (SLONG_P)utempVal64: (SLONG_P)tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(SLONG_P); 
            break;

        case SQL_C_ULONG:
            if (tempVal64 > ULONG_MAX)
                return IDS_22_003;
            *((ULONG_P *)targetDataPtr) = (unsignedValue ?
                                        (ULONG_P)utempVal64: (ULONG_P)tempVal64);
            if (*((ULONG_P *)targetDataPtr) != (unsignedValue ?
                                        (ULONG_P)utempVal64: (ULONG_P)tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(ULONG_P); 
            break;

        case SQL_C_SBIGINT:
            if (tempVal64 < LLONG_MIN || tempVal64 > LLONG_MAX)
                return IDS_22_003;
            *((__int64 *)targetDataPtr) = (unsignedValue ?
                                        (__int64)utempVal64: tempVal64);
            if (*((__int64 *)targetDataPtr) != (unsignedValue ?
                                        (__int64)utempVal64: tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(__int64); 
            break;

        case SQL_C_UBIGINT:
            if (tempVal64 > ULLONG_MAX)
                return IDS_22_003;
            *((__uint64 *)targetDataPtr) = (unsignedValue ?
                                        utempVal64: (__uint64)tempVal64);
            if (*((__uint64 *)targetDataPtr) != (unsignedValue ?
                                        utempVal64: (__uint64)tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(__uint64); 
            break;

        case SQL_C_FLOAT:
            if (tempVal64 < -FLT_MAX || tempVal64 > FLT_MAX)
                return IDS_22_003;
            *((SQLFLOAT *)targetDataPtr) = (unsignedValue ?
                                            (SQLFLOAT)utempVal64: (SQLFLOAT)tempVal64);
            if (*((SQLFLOAT *)targetDataPtr) = (unsignedValue ?
                                            (SQLFLOAT)utempVal64: (SQLFLOAT)tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(SQLFLOAT); 
            break;

        case SQL_C_DOUBLE:
            *((SQLDOUBLE*)targetDataPtr) = (unsignedValue ?
                                                (SQLDOUBLE)utempVal64: (SQLDOUBLE)tempVal64);
            if (*((SQLFLOAT*)targetDataPtr) = (unsignedValue ?
                                            (SQLDOUBLE)utempVal64: (SQLDOUBLE)tempVal64))
                retCode = IDS_01_S07;
            *targetStrLenPtr = sizeof(SQLDOUBLE); 
            break;

        default:
			return IDS_07_006;
    }

    return retCode;
}
