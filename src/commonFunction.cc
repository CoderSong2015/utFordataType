#include "commonFunction.h"
#include "testData.h"

using namespace ODBC;
//#include "functionList.h"
void testE(){
    EXPECT_EQ(1, 2);
}

void initDesc(CDescRec *cdr, TESTDATA_TABLE  map){

    cdr->m_ODBCDataType                 = map.m_ODBCDataType; //1
    cdr->m_SQLDatetimeCode              = map.m_SQLDatetimeCode; //2
    cdr->m_DescPrecision                = map.m_DescPrecision; //3
    cdr->m_DescScale                    = map.m_DescScale; //4
    cdr->m_DescUnsigned                 = map.m_DescUnsigned; //5
    cdr->m_SQLCharset                   = map.m_SQLCharset; //6
    cdr->m_SQLMaxLength                 = map.m_SQLMaxLength; //7

//    cdr->m_SQLDataType                  = map.m_SQLDataType; 
//    cdr->m_SQLOctetLength               = map.m_SQLOctetLength; 
//    cdr->m_ODBCPrecision                = map.m_ODBCPrecision; 
//    cdr->m_ODBCScale                    = map.m_ODBCScale; 
//    cdr->m_SQLUnsigned                  = map.m_SQLUnsigned;

}

void commonSwitch(int targetType, SQLPOINTER testP, int n){
    
    switch(targetType){
        case SQL_C_TINYINT:
        case SQL_C_STINYINT:{
            char mtarget = *(char *)testP;
            char dataTarget = stringToNum<int>(TESTDATA_MAP[n].target);
            EXPECT_EQ(dataTarget, mtarget) <<TESTDATA_MAP[n].targetType  << TESTDATA_MAP[n].srcType;
            delete((char *)testP);
            break;                        
        }
        case SQL_C_BIT:
        case SQL_C_UTINYINT:{
            unsigned char mtarget = *(unsigned char *)testP;
            unsigned char dataTarget = stringToNum<unsigned int>(TESTDATA_MAP[n].target);
            EXPECT_EQ(dataTarget, mtarget) <<TESTDATA_MAP[n].targetType  << TESTDATA_MAP[n].srcType ;
            delete((unsigned char *)testP);
            break;
        }
        case SQL_C_SHORT:
        case SQL_C_SSHORT:{
            short mtarget = *(short *)testP;
            EXPECT_EQ(stringToNum<short>(TESTDATA_MAP[n].target), mtarget) <<TESTDATA_MAP[n].targetType  << TESTDATA_MAP[n].srcType ;
            delete((short *)testP);
            break;
        } 
        case SQL_C_USHORT:{
            unsigned short mtarget = *(unsigned short *)testP;
            EXPECT_EQ(stringToNum<unsigned short>(TESTDATA_MAP[n].target), mtarget) <<TESTDATA_MAP[n].targetType  << TESTDATA_MAP[n].srcType ;
            delete((unsigned short *)testP);
            break;
        } 
        case SQL_C_SLONG:
        case SQL_C_LONG:{
            int mtarget = *(int *)testP;
            EXPECT_EQ(stringToNum<int>(TESTDATA_MAP[n].target), mtarget) <<TESTDATA_MAP[n].targetType  << TESTDATA_MAP[n].srcType ;
            delete((int *)testP);
            break;
        }
        case SQL_C_ULONG:{
            unsigned int mtarget = *(unsigned int *)testP;
            EXPECT_EQ(stringToNum<unsigned int>(TESTDATA_MAP[n].target), mtarget) <<TESTDATA_MAP[n].targetType  << TESTDATA_MAP[n].srcType ;
            delete((unsigned int *)testP);
            break;
        }
        case SQL_C_SBIGINT:{
            long long mtarget = *(long long *)testP;
            EXPECT_EQ(stringToNum<long long>(TESTDATA_MAP[n].target), mtarget) <<TESTDATA_MAP[n].targetType  << TESTDATA_MAP[n].srcType ;
            delete((long long *)testP);
            break;
        }
        case SQL_C_UBIGINT:{
            unsigned long long mtarget = *(unsigned long long *)testP;
            EXPECT_EQ(stringToNum<unsigned long long>(TESTDATA_MAP[n].target), mtarget) <<TESTDATA_MAP[n].targetType  << TESTDATA_MAP[n].srcType ;
            delete((unsigned long long *)testP);
            break;
        }
        case SQL_C_FLOAT:{
            float mtarget = *(float *)testP;
            EXPECT_FLOAT_EQ(stringToNum<float>(TESTDATA_MAP[n].target), mtarget) <<TESTDATA_MAP[n].targetType  << TESTDATA_MAP[n].srcType ;
            delete((float *)testP);
            break; 
        }
        case SQL_C_DOUBLE:{    
            double mtarget = *(double *)testP;
            EXPECT_DOUBLE_EQ(stringToNum<double>(TESTDATA_MAP[n].target), mtarget) <<TESTDATA_MAP[n].targetType  << TESTDATA_MAP[n].srcType ;
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
    ICUConverter* iconv;
    char* tmpbuf = NULL;

    switch(TESTDATA_MAP[n].srcType){
        
        case SQL_BIT:
            break;
        case SQL_TINYINT:{
            char testSrc = stringToNum<int>(s);
            
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].targetLen);
            memset(testP, 0,sizeof(char) * TESTDATA_MAP[n].targetLen);
            SQLLEN size;
            ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].srcType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].targetType, testP, TESTDATA_MAP[n].targetLen, &size, false, tmpbuf, iconv);
            commonSwitch(TESTDATA_MAP[n].targetType, testP, n);    
            break;
        }
        case SQL_SMALLINT:{
            short testSrc = stringToNum<short>(s);
            
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].targetLen);
            memset(testP, 0,sizeof(char) * TESTDATA_MAP[n].targetLen);
            SQLLEN size;
            ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].srcType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].targetType, testP, TESTDATA_MAP[n].targetLen, &size, false, tmpbuf, iconv);
            commonSwitch(TESTDATA_MAP[n].targetType, testP, n);    
            break;
        }
        case SQL_INTEGER:{
            int testSrc = stringToNum<int>(s);
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].targetLen); 
            memset(testP, 0,sizeof(char) * TESTDATA_MAP[n].targetLen);
            SQLLEN size;
            ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].srcType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].targetType, testP, TESTDATA_MAP[n].targetLen, &size, false, tmpbuf, iconv);
            commonSwitch(TESTDATA_MAP[n].targetType, testP, n);    
            break; 
        }
        case SQL_BIGINT:{
            long long testSrc = stringToNum<long long>(s);
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].targetLen);
            memset(testP, 0,sizeof(char) * TESTDATA_MAP[n].targetLen);
            SQLLEN size;
            ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].srcType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].targetType, testP, TESTDATA_MAP[n].targetLen, &size, false, tmpbuf, iconv);
            commonSwitch(TESTDATA_MAP[n].targetType, testP, n);    
            break;
        }
        case SQL_REAL:
            break;//TODO
        case SQL_DOUBLE:{
            double testSrc = stringToNum<double>(s);
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].targetLen);
            memset(testP, 0,sizeof(char) * TESTDATA_MAP[n].targetLen);
            SQLLEN size;
            ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].srcType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].targetType, testP, TESTDATA_MAP[n].targetLen, &size, false, tmpbuf, iconv);
            commonSwitch(TESTDATA_MAP[n].targetType, testP, n);    
            break;
        }
        case SQL_CHAR:
        case SQL_WCHAR:
        case SQL_VARCHAR:
        case SQL_WVARCHAR: 
        case SQL_LONGVARCHAR:
             break;//TODO
        case SQL_NUMERIC:
             SQL_NUMERIC_STRUCT testSrc;
             break;
        case SQL_DATE:
             break;
        case SQL_TIME:
             break;
        case SQL_TIMESTAMP:
             break;
        case SQL_FLOAT: // no need
             break;
        default:
            EXPECT_TRUE(false) << "the DataType is :" << TESTDATA_MAP[n].srcType;
            break;
    } 
}
