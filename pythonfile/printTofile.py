from preDefine import defType



def printToFile(cKey = 0 ,
                sqlKey = 0,
                count = 0,
                sqlValue = 0,
                cValue = 0,
                CDataType = "SQL_C_NONE",
                CDataLen =  0,
                ODBCDataType ="SQL_NONE",
                SQLDataType  ="SQL_NONE",
                SQLMaxLength = 0,
                DescUnsigned = 0,
                Precision = 0,
                Scale = 0,
                SQLCharset = 0,
                SQLDatetimeCode = 0,
                SQLOctetLength = 0,
                numeric_sign   = 0,
                numeric_value  = "NONE",
                year = 2017,
                mon  = 12,
                day  = 31,
                hour = 22,
                min  = 45,
                second = 10,
                frac = "123456000"
        ):
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
        , "%s"               //char numeric_value[SQL_MAX_NUMERIC_LEN];
        , "%s"               // C typename
        , "%s"               // SRC type name
        , %d                 // year,
        , %d                 // mon,
        , %d                 // day,
        , %d                 // hour,
        , %d                 // min,
        , %d                 // second
        , "%s"               // frac
    },
    '''%(
            count - 1,
            sqlValue,
            cValue,
            CDataType,
            CDataLen,
            ODBCDataType,
            SQLDataType,
            SQLMaxLength,
            DescUnsigned,
            Precision,
            Scale,
            SQLCharset,
            SQLDatetimeCode,
            SQLOctetLength,
            numeric_sign,
            numeric_value,
            CDataType,
            ODBCDataType,
            year,
            mon,
            day,
            hour,
            min,
            second,
            frac,
            )
        )
