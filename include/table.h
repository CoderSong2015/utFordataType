
typedef struct TESTDATATABLE{
    
    const char *src;
    int srcType; 
    const char * target;
    int targetType;
    int targetLen;
    
    int m_ODBCDataType;
    int m_DescUnsigned;
    int m_DescType;     
    int m_DescConciseType;
    int m_DescDatetimeIntervalCode;
    int m_DescOctetLength;
    int m_DescLength;
    int m_DescPrecision;
    int m_DescScale;
    int m_DescDatetimeIntervalPrecision;
    int m_DescFixedPrecScale;
    int m_DescNullable;
    int m_SQLCharset;
    int m_ODBCCharset;
    int m_SQLDataType;
    int m_SQLPrecision;
    int m_ODBCPrecision;
    int m_ODBCScale;
    int m_SQLDatetimeCode;
    int m_SQLOctetLength;
    int m_SQLMaxLength;
    int m_DescReturnedLength;
}TESTDATA_TABLE;
