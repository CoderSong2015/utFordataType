#include "commonFunction.h"
#include "testData.h"
//#include "functionList.h"
void testE(){
    EXPECT_EQ(1, 2);
}

void initDesc(CDescRec *cdr, TESTDATA_TABLE  map){

    cdr->m_ODBCDataType                 = map.m_ODBCDataType;
    cdr->m_DescUnsigned                  = map.m_SQLUnsigned;
    cdr->m_DescType                     = map.m_DescType;     
    cdr->m_DescConciseType              = map.m_DescConciseType;
    cdr->m_DescDatetimeIntervalCode     = map.m_DescDatetimeIntervalCode;
    cdr->m_DescOctetLength              = map.m_DescOctetLength;
    cdr->m_DescLength                   = map.m_DescLength;
    cdr->m_DescPrecision                = map.m_DescPrecision;
    cdr->m_DescScale                    = map.m_DescScale;
    cdr->m_DescDatetimeIntervalPrecision= map.m_DescDatetimeIntervalPrecision;
    cdr->m_DescFixedPrecScale           = map.m_DescFixedPrecScale;
    cdr->m_DescNullable                 = map.m_DescNullable;
    cdr->m_SQLCharset                   = map.m_SQLCharset;
    cdr->m_ODBCCharset                  = map.m_ODBCCharset;
    cdr->m_SQLDataType                  = map.m_SQLDataType;
    cdr->m_SQLPrecision                 = map.m_SQLPrecision;
    cdr->m_ODBCPrecision                = map.m_ODBCPrecision;
    cdr->m_ODBCScale                    = map.m_ODBCScale;
    cdr->m_SQLDatetimeCode              = map.m_SQLDatetimeCode;
    cdr->m_SQLOctetLength               = map.m_SQLOctetLength;
    cdr->m_SQLMaxLength                 = map.m_SQLMaxLength;
    cdr->m_DescReturnedLength           = map.m_DescReturnedLength;

}
void commonSwitch(int targetType, SQLPOINTER testP, int n){
    
    switch(targetType){
        case SQL_C_TINYINT:
        case SQL_C_STINYINT:{
            char mtarget = *(char *)testP;
            char dataTarget = stringToNum<int>(TESTDATA_MAP[n].target);
            EXPECT_EQ(dataTarget, mtarget);
            delete((char *)testP);
            break;                        
        }
        case SQL_C_BIT:
        case SQL_C_UTINYINT:{
            unsigned char mtarget = *(unsigned char *)testP;
            unsigned char dataTarget = stringToNum<unsigned int>(TESTDATA_MAP[n].target);
            EXPECT_EQ(dataTarget, mtarget);
            delete((unsigned char *)testP);
            break;
        }
        case SQL_C_SHORT:
        case SQL_C_SSHORT:{
            short mtarget = *(short *)testP;
            EXPECT_EQ(stringToNum<short>(TESTDATA_MAP[n].target), mtarget);
            delete((short *)testP);
            break;
        } 
        case SQL_C_USHORT:{
            unsigned short mtarget = *(unsigned short *)testP;
            EXPECT_EQ(stringToNum<unsigned short>(TESTDATA_MAP[n].target), mtarget);
            delete((unsigned short *)testP);
            break;
        } 
        case SQL_C_SLONG:
        case SQL_C_LONG:{
            int mtarget = *(int *)testP;
            EXPECT_EQ(stringToNum<int>(TESTDATA_MAP[n].target), mtarget);
            delete((int *)testP);
            break;
        }
        case SQL_C_ULONG:{
            unsigned int mtarget = *(unsigned int *)testP;
            EXPECT_EQ(stringToNum<unsigned int>(TESTDATA_MAP[n].target), mtarget);
            delete((unsigned int *)testP);
            break;
        }
        case SQL_C_SBIGINT:{
            long long mtarget = *(long long *)testP;
            EXPECT_EQ(stringToNum<long long>(TESTDATA_MAP[n].target), mtarget);
            delete((long long *)testP);
            break;
        }
        case SQL_C_UBIGINT:{
            unsigned long long mtarget = *(unsigned long long *)testP;
            EXPECT_EQ(stringToNum<unsigned long long>(TESTDATA_MAP[n].target), mtarget);
            delete((unsigned long long *)testP);
            break;
        }
        case SQL_C_FLOAT:{
            float mtarget = *(float *)testP;
            EXPECT_FLOAT_EQ(stringToNum<float>(TESTDATA_MAP[n].target), mtarget);
            delete((float *)testP);
            break; 
        }
        case SQL_C_DOUBLE:{    
            double mtarget = *(double *)testP;
            EXPECT_DOUBLE_EQ(stringToNum<double>(TESTDATA_MAP[n].target), mtarget);
            delete((double *)testP);
            break;
        }
        default:
        break;
    }
 
}

void callSub(int n, CDescRec* tmpDesc){
    
    string s = TESTDATA_MAP[n].src;
    initDesc(tmpDesc, TESTDATA_MAP[n]); 

    switch(TESTDATA_MAP[n].srcType){
        
        case SQL_TINYINT:{
            char testSrc = stringToNum<int>(s);
            
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].targetLen);
            SQLLEN size;
            ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].srcType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].targetType, testP, TESTDATA_MAP[n].targetLen, &size, false, NULL);
            commonSwitch(TESTDATA_MAP[n].targetType, testP, n);    
            break;
        }
        case SQL_SMALLINT:{
            short testSrc = stringToNum<short>(s);
            
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].targetLen);
            SQLLEN size;
            ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].srcType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].targetType, testP, TESTDATA_MAP[n].targetLen, &size, false, NULL);
            commonSwitch(TESTDATA_MAP[n].targetType, testP, n);    
            break;
        }
        case SQL_INTEGER:{
            int testSrc = stringToNum<int>(s);
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].targetLen); 
            SQLLEN size;
            ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].srcType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].targetType, testP, TESTDATA_MAP[n].targetLen, &size, false, NULL);
            commonSwitch(TESTDATA_MAP[n].targetType, testP, n);    
            break; 
        }
        case SQL_DOUBLE:{
            double testSrc = stringToNum<double>(s);
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].targetLen);
            SQLLEN size;
            ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].srcType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].targetType, testP, TESTDATA_MAP[n].targetLen, &size, false, NULL);
            commonSwitch(TESTDATA_MAP[n].targetType, testP, n);    
            break;
        }
        case SQL_FLOAT:{
            break;
        }
        case SQL_WCHAR:
        case SQL_VARCHAR:
        case SQL_WVARCHAR: 
        case SQL_LONGVARCHAR:
             break;//TODO
        case SQL_BIGINT:{
            long long testSrc = stringToNum<long long>(s);
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].targetLen);
            SQLLEN size;
            ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].srcType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].targetType, testP, TESTDATA_MAP[n].targetLen, &size, false, NULL);
            commonSwitch(TESTDATA_MAP[n].targetType, testP, n);    
            break;
        }
        case SQL_REAL:
            break;//TODO
        case SQL_BIT:
            break;
        case SQL_NUMERIC:
        default:
        EXPECT_TRUE(false) << "the DataType is :" << TESTDATA_MAP[n].srcType;
        break;
    } 
}
