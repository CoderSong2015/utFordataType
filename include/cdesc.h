#ifndef CDESC_H
#define CDESC_H

#include <sql.h>
#include <sqlext.h>
#include "sqlcli.h"
typedef long long __int64;
typedef unsigned long long __uint64;
typedef signed int SLONG_P;
typedef unsigned int ULONG_P;
typedef double    DOUBLE;
typedef float     FLOAT;
typedef short     SHORT;
#define TRUE      true
#define FALSE     false
#define IDS_22_003                       ((DWORD)0xC0030018L)
#define IDS_01_S07                       ((DWORD)0x80030152L)
#define IDS_07_006                       ((DWORD)0xC0030007L)
#define IDS_HY_000                       ((DWORD)0xC0030007L)
#define NSK_BUILD_1 0
#define LANG_NEUTRAL 0

class CDescRec {
public:
	CDescRec(SQLSMALLINT ODBCDataType, SQLSMALLINT m_DescUnsigned);
	~CDescRec();

	SQLSMALLINT	m_DescType;
	SQLSMALLINT	m_DescConciseType;
	SQLSMALLINT	m_DescDatetimeIntervalCode;
	SQLINTEGER	m_DescOctetLength;
	SQLUINTEGER	m_DescLength;
	SQLINTEGER	m_DescPrecision;
	SQLSMALLINT	m_DescScale;
	SQLINTEGER	m_DescDatetimeIntervalPrecision;
	SQLSMALLINT	m_DescFixedPrecScale;
	SQLSMALLINT	m_DescNullable;
//	SQLPOINTER	m_DescDataPtr;
//	SQLLEN	    *m_DescIndicatorPtr;
//	SQLINTEGER 	m_DescDisplaySize;
//	SQLLEN	    *m_DescOctetLengthPtr;   
//	SQLSMALLINT	m_DescParameterType;
//	SQLCHAR		m_DescBaseColumnName[MAX_IDENTIFIER_LEN+1];
//	SQLCHAR		m_DescName[MAX_IDENTIFIER_LEN+1];

	SQLINTEGER	m_SQLCharset;
	SQLINTEGER	m_ODBCCharset;
	SQLSMALLINT m_SQLDataType;
	SQLSMALLINT m_ODBCDataType;
	SQLINTEGER	m_SQLPrecision;
	SQLINTEGER	m_ODBCPrecision;
	SQLSMALLINT	m_ODBCScale;
	SQLSMALLINT m_SQLDatetimeCode;
	SQLINTEGER	m_SQLOctetLength;
	SQLSMALLINT	m_SQLUnsigned;
	SQLINTEGER	m_SQLMaxLength;

//	SQLINTEGER	m_DescAutoUniqueValue;
//	SQLINTEGER	m_DescCaseSensitive;
//	SQLINTEGER	m_DescNumPrecRadix;
//	SQLSMALLINT	m_DescSearchable;
//	SQLSMALLINT	m_DescUnnamed;
	SQLSMALLINT	m_DescUnsigned;
//	SQLSMALLINT	m_DescUpdatable;

//	SQLCHAR		m_DescTypeName[MAX_IDENTIFIER_LEN+1];
//	SQLCHAR		m_DescBaseTableName[MAX_IDENTIFIER_LEN+1];
//	SQLCHAR		m_DescCatalogName[MAX_IDENTIFIER_LEN+1];
//	SQLCHAR		m_DescLabel[MAX_IDENTIFIER_LEN+1];
//	SQLCHAR		m_DescTableName[MAX_IDENTIFIER_LEN+1];
	
//	SQLCHAR		m_DescLiteralPrefix[20];
//	SQLCHAR		m_DescLiteralSuffix[20];
//	SQLCHAR		m_DescLocalTypeName[MAX_IDENTIFIER_LEN+1];
//	SQLCHAR		m_DescSchemaName[MAX_IDENTIFIER_LEN];

	SQLINTEGER	m_DescReturnedLength;	// Used by SQLGetData - Length of data returned already
									// SQL_NO_DATA means the data is alreay sent
 //	CHAR		*m_TranslatedDataPtr; // Used by SQLGetData - 10-090119-8521

};

class ICUConverter {
public:
    ICUConverter();
};

#endif
