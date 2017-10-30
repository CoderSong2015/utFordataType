#ifndef __TABLE__
#define __TABLE__
typedef struct TESTDATATABLE{
    const char *sqlValue;                                             
    const char *cValue;                                  
    int CDataType;                                  
    int CDataLen;                                  
    int m_ODBCDataType;                                  
    int m_SQLDataType;                                  
    int m_SQLMaxLength;                                  
    int m_DescUnsigned;                                  
    int Precision;                                  
    int Scale;                                  
    int m_SQLCharset;                                  
    int m_SQLDatetimeCode;                       
    int m_SQLOctetLength;                       
    char numeric_sign;  /* 1=+ 0=- */        
    const char *numeric_value;
    const char *CTypeName;
    const char *SQLTypeName;
}TESTDATA_TABLE;

#endif
