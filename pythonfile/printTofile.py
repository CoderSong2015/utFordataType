from preDefine import defType
def printToFile(c_k, sql_k, outputData, count, isunsigned):
    with open('testData.h', 'a') as f:
        f.write(
            '''{
                             //count=%d
          "%s"               //const char *sqlValue;                                             
        , "%s"               //const char *cValue;                                  
        , %s                 //int CDataType;                                  
        , %d                 //int CDataLen;                                  
        , %s                 //int m_ODBCDataType;                                  
        , %s                 //int m_SQLDataType;                                  
        , %d                 //int m_SQLMaxLength;                                  
        , %d                 //int m_DescUnsigned;                                  
        , %d                 //int Precision;                                  
        , %d                 //int Scale;                                  
        , %d                 //int m_SQLCharset;                                  
        , %d                 //int m_SQLDatetimeCode;                       
        , %d                 //int m_SQLOctetLength;                       
        , '%d'               //char numeric_sign;  /* 1=+ 0=- */        
        , "%s"                 //char numeric_value[SQL_MAX_NUMERIC_LEN];
        , "%s"                 // C typename
        , "%s"                 // SRC type name
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,""
    },
    '''%(
          count-1                  ,
          str(outputData)          ,
          str(outputData)          ,
          defType.sql_c_type[c_k]  ,
          defType.sql_c_Len[c_k]   ,
          defType.sql_type[sql_k]  ,
          defType.sql_type_Datatype[sql_k],
          defType.sql_type_len[sql_k]     ,
          isunsigned               ,
          0                        ,
          0                        ,
          0                        ,
          0                        ,
          defType.sql_type_len[sql_k],
          0                        ,
          ""                       ,
          defType.sql_c_type[c_k]  ,
          defType.sql_type[sql_k]  ,
            )
        )

def printNumericTest(precision, scale, isUnsigned, outputData, count):
    with open('testData.h', 'a') as f:
        f.write(
            '''{
                             //count=%d
          "%s"               //const char *sqlValue;                                             
        , "%s"               //const char *cValue;                                  
        , %s                 //int CDataType;                                  
        , %d                 //int CDataLen;                                  
        , SQL_NUMERIC        //int m_ODBCDataType;                                  
        , 0                  //int m_SQLDataType;                                  
        , %d                 //int m_SQLMaxLength;                                  
        , %d                 //int m_DescUnsigned;                                  
        , %d                 //int Precision;                                  
        , %d                 //int Scale;                                  
        , %d                 //int m_SQLCharset;                                  
        , %d                 //int m_SQLDatetimeCode;                       
        , %d                 //int m_SQLOctetLength;                       
        , '%d'               //char numeric_sign;  /* 1=+ 0=- */        
        , "%s"                 //char numeric_value[SQL_MAX_NUMERIC_LEN];
        , ""                 // C typename
        , "SQL_NUMERIC"                 // SRC type name
        ,0
                ,0
                ,0
                ,0
                ,0
                ,0
                ,""
    },
    '''%(
          count-1                  ,
          str(outputData)          ,
          str(outputData)          ,
          0,
          0 ,
          0 ,
          isUnsigned              ,
          precision               ,
          scale                   ,
          0,
          0                        ,
          0,
          isUnsigned               ,
          str(outputData)          ,

          )
        )


def printNumeric(precision, scale, isUnsigned, outputData, count, c_k, outputDataNumeric):
    with open('testData.h', 'a') as f:
        f.write(
            '''{
                             //count=%d
          "%s"               //const char *sqlValue;                                             
        , "%s"               //const char *cValue;                                  
        , %s                 //int CDataType;                                  
        , %d                 //int CDataLen;                                  
        , SQL_NUMERIC        //int m_ODBCDataType;                                  
        , 0                  //int m_SQLDataType;                                  
        , %d                 //int m_SQLMaxLength;                                  
        , %d                 //int m_DescUnsigned;                                  
        , %d                 //int Precision;                                  
        , %d                 //int Scale;                                  
        , %d                 //int m_SQLCharset;                                  
        , %d                 //int m_SQLDatetimeCode;                       
        , %d                 //int m_SQLOctetLength;                       
        , '%d'               //char numeric_sign;  /* 1=+ 0=- */        
        , "%s"                 //char numeric_value[SQL_MAX_NUMERIC_LEN];
        , "%s"                 // C typename
        , "SQL_NUMERIC"                 // SRC type name
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,""
    },
    '''%(
          count-1                  ,
          str(outputDataNumeric)          ,
          str(outputData)          ,
          defType.sql_c_type[c_k],
          defType.sql_c_Len[c_k],
          0 ,
          isUnsigned              ,
          precision               ,
          scale                   ,
          0,
          0                        ,
          0,
          isUnsigned               ,
          str(outputDataNumeric)          ,
          defType.sql_c_type[c_k]  ,

          )
        )

def printTimeStamp(Ctype,
                   SQLtype,
                   year,
                   mon,
                   monthDay,
                   hour,
                   min,
                   second,
                   fac,
                   cTypeLen,
                   sqlTypeLen,
                   count = 0):
    with open('testData.h', 'a') as f:
        f.write(
            '''{
                             //count=%d
          "%s"               //const char *sqlValue;                                             
        , "%s"               //const char *cValue;                                  
        , %s                 //int CDataType;                                  
        , %d                 //int CDataLen;                                  
        , %s                 //int m_ODBCDataType;                                  
        , 0                  //int m_SQLDataType;                                  
        , %d                 //int m_SQLMaxLength;                                  
        , %d                 //int m_DescUnsigned;                                  
        , %d                 //int Precision;                                  
        , %d                 //int Scale;                                  
        , %d                 //int m_SQLCharset;                                  
        , %d                 //int m_SQLDatetimeCode;                       
        , %d                 //int m_SQLOctetLength;                       
        , '%d'               //char numeric_sign;  /* 1=+ 0=- */        
        , "%s"                 //char numeric_value[SQL_MAX_NUMERIC_LEN];
        , "%s"                 // C typename
        , "%s"                 // SRC type name
        ,%d
        ,%d
        ,%d
        ,%s
        ,%s
        ,%s
        ,"%s"
    },
    '''%(
          count-1    ,
          ""         ,
          ""         ,
          Ctype,
          cTypeLen,
          SQLtype,
          sqlTypeLen,
          0,
          0               ,
          0                   ,
          0,
          0                        ,
          0,
          0 ,
          0,
          Ctype,
          SQLtype,
          year,
          mon,
          monthDay,
          hour,
          min,
          second,
          fac
          )
        )

    pass