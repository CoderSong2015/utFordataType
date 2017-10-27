#include "commonFunction.h"
#include "testData.h"
#include "init.h"
using namespace ODBC;
//#include "functionList.h"
void testE(){
    EXPECT_EQ(1, 2);
}


void commonSwitch(int CDataType, SQLPOINTER testP, int n){
    
    switch(CDataType){
        case SQL_C_TINYINT:
        case SQL_C_STINYINT:{
            char mtarget = *(char *)testP;
            char dataTarget = stringToNum<int>(TESTDATA_MAP[n].cValue);
            EXPECT_EQ(dataTarget, mtarget) << TESTDATA_MAP[n].CDataType << " " << TESTDATA_MAP[n].m_ODBCDataType;
            delete((char *)testP);
            break;                        
        }
        case SQL_C_BIT:
        case SQL_C_UTINYINT:{
            unsigned char mtarget  = *(unsigned char *)testP;
            unsigned char dataTarget = stringToNum<unsigned int>(TESTDATA_MAP[n].cValue);
            EXPECT_EQ(dataTarget, mtarget) << TESTDATA_MAP[n].CDataType << " " << TESTDATA_MAP[n].m_ODBCDataType ;
            delete((unsigned char *)testP);
            break;
        }
        case SQL_C_SHORT:
        case SQL_C_SSHORT:{
            short mtarget = *(short *)testP;
            EXPECT_EQ(stringToNum<short>(TESTDATA_MAP[n].cValue), mtarget) << TESTDATA_MAP[n].CDataType <<" " << TESTDATA_MAP[n].m_ODBCDataType ;
            delete((short *)testP);
            break;
        } 
        case SQL_C_USHORT:{
            unsigned short mtarget = *(unsigned short *)testP;
            EXPECT_EQ(stringToNum<unsigned short>(TESTDATA_MAP[n].cValue), mtarget) << TESTDATA_MAP[n].CDataType << " " << TESTDATA_MAP[n].m_ODBCDataType ;
            delete((unsigned short *)testP);
            break;
        } 
        case SQL_C_SLONG:
        case SQL_C_LONG:{
            int mtarget = *(int *)testP;
            EXPECT_EQ(stringToNum<int>(TESTDATA_MAP[n].cValue), mtarget) << TESTDATA_MAP[n].CDataType << " " << TESTDATA_MAP[n].m_ODBCDataType ;
            delete((int *)testP);
            break;
        }
        case SQL_C_ULONG:{
            unsigned int mtarget = *(unsigned int *)testP;
            EXPECT_EQ(stringToNum<unsigned int>(TESTDATA_MAP[n].cValue), mtarget) << TESTDATA_MAP[n].CDataType << " " << TESTDATA_MAP[n].m_ODBCDataType ;
            delete((unsigned int *)testP);
            break;
        }
        case SQL_C_SBIGINT:{
            long long mtarget = *(long long *)testP;
            EXPECT_EQ(stringToNum<long long>(TESTDATA_MAP[n].cValue), mtarget) << TESTDATA_MAP[n].CDataType << " " << TESTDATA_MAP[n].m_ODBCDataType ;
            delete((long long *)testP);
            break;
        }
        case SQL_C_UBIGINT:{
            unsigned long long mtarget = *(unsigned long long *)testP;
            EXPECT_EQ(stringToNum<unsigned long long>(TESTDATA_MAP[n].cValue), mtarget) << TESTDATA_MAP[n].CDataType << " " << TESTDATA_MAP[n].m_ODBCDataType ;
            delete((unsigned long long *)testP);
            break;
        }
        case SQL_C_FLOAT:{
            float mtarget = *(float *)testP;
            EXPECT_FLOAT_EQ(stringToNum<float>(TESTDATA_MAP[n].cValue), mtarget) << TESTDATA_MAP[n].CDataType << " " << TESTDATA_MAP[n].m_ODBCDataType ;
            delete((float *)testP);
            break; 
        }
        case SQL_C_DOUBLE:{    
            double mtarget = *(double *)testP;
            EXPECT_DOUBLE_EQ(stringToNum<double>(TESTDATA_MAP[n].cValue), mtarget) << TESTDATA_MAP[n].CDataType << " " << TESTDATA_MAP[n].m_ODBCDataType ;
            delete((double *)testP);
            break;
        }
        default:
        break;
    }
 
}

void callSub(int n, CDescRec* tmpDesc){
    
    string s = TESTDATA_MAP[n].sqlValue;
    initDesc(tmpDesc, TESTDATA_MAP[n]); 
    ICUConverter* iconv;
    char* tmpbuf = NULL;

    switch(TESTDATA_MAP[n].m_ODBCDataType){
        
        case SQL_BIT:
            break;
        case SQL_TINYINT:{
            if (!TESTDATA_MAP[n].m_DescUnsigned)
            {
                char testSrc = stringToNum<int>(s);
                SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].m_SQLMaxLength);
                memset(testP, 0,sizeof(char) * TESTDATA_MAP[n].m_SQLMaxLength);
                SQLLEN size;
                ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].m_ODBCDataType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].CDataType, testP, TESTDATA_MAP[n].m_SQLMaxLength, &size, false, tmpbuf, iconv);
                commonSwitch(TESTDATA_MAP[n].CDataType, testP, n);    
            }
            else{
                unsigned char testSrc = stringToNum<int>(s);
                SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].m_SQLMaxLength);
                memset(testP, 0,sizeof(char) * TESTDATA_MAP[n].m_SQLMaxLength);
                SQLLEN size;
                ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].m_ODBCDataType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].CDataType, testP, TESTDATA_MAP[n].m_SQLMaxLength, &size, false, tmpbuf, iconv);
                commonSwitch(TESTDATA_MAP[n].CDataType, testP, n);    
            }
            break;
        }
        case SQL_SMALLINT:{
            if (!TESTDATA_MAP[n].m_DescUnsigned)
            {
                short testSrc = stringToNum<int>(s);
                SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].m_SQLMaxLength);
                memset(testP, 0,sizeof(char) * TESTDATA_MAP[n].m_SQLMaxLength);
                SQLLEN size;
                ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].m_ODBCDataType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].CDataType, testP, TESTDATA_MAP[n].m_SQLMaxLength, &size, false, tmpbuf, iconv);
                commonSwitch(TESTDATA_MAP[n].CDataType, testP, n);    
            }
            else
            {
                unsigned short testSrc = stringToNum<unsigned short>(s);
                SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].m_SQLMaxLength);
                memset(testP, 0,sizeof(char) * TESTDATA_MAP[n].m_SQLMaxLength);
                SQLLEN size;
                ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].m_ODBCDataType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].CDataType, testP, TESTDATA_MAP[n].m_SQLMaxLength, &size, false, tmpbuf, iconv);
                commonSwitch(TESTDATA_MAP[n].CDataType, testP, n);    
            }
            break;
        }
        case SQL_INTEGER:{
            if (!TESTDATA_MAP[n].m_DescUnsigned)
            {
                int testSrc = stringToNum<int>(s);
                SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].m_SQLMaxLength); 
                memset(testP, 0,sizeof(char) * TESTDATA_MAP[n].m_SQLMaxLength);
                SQLLEN size;
                ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].m_ODBCDataType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].CDataType, testP, TESTDATA_MAP[n].m_SQLMaxLength, &size, false, tmpbuf, iconv);
                commonSwitch(TESTDATA_MAP[n].CDataType, testP, n);    
            }
            else
            {
                unsigned int testSrc = stringToNum<unsigned int>(s);
                SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].m_SQLMaxLength); 
                memset(testP, 0,sizeof(char) * TESTDATA_MAP[n].m_SQLMaxLength);
                SQLLEN size;
                ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].m_ODBCDataType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].CDataType, testP, TESTDATA_MAP[n].m_SQLMaxLength, &size, false, tmpbuf, iconv);
                commonSwitch(TESTDATA_MAP[n].CDataType, testP, n);    
            }
            break; 
        }
        case SQL_BIGINT:{
            if (!TESTDATA_MAP[n].m_DescUnsigned)
            {
                long long testSrc = stringToNum<long long>(s);
                SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].m_SQLMaxLength);
                memset(testP, 0,sizeof(char) * TESTDATA_MAP[n].m_SQLMaxLength);
                SQLLEN size;
                ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].m_ODBCDataType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].CDataType, testP, TESTDATA_MAP[n].m_SQLMaxLength, &size, false, tmpbuf, iconv);
                commonSwitch(TESTDATA_MAP[n].CDataType, testP, n);    
            }
            else
            {
                unsigned long long testSrc = stringToNum<unsigned long long>(s);
                SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].m_SQLMaxLength);
                memset(testP, 0,sizeof(char) * TESTDATA_MAP[n].m_SQLMaxLength);
                SQLLEN size;
                ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].m_ODBCDataType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].CDataType, testP, TESTDATA_MAP[n].m_SQLMaxLength, &size, false, tmpbuf, iconv);
                commonSwitch(TESTDATA_MAP[n].CDataType, testP, n);    
            }
            break;
        }
        case SQL_REAL:
            break;//TODO
        case SQL_DOUBLE:{
            double testSrc = stringToNum<double>(s);
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAP[n].m_SQLMaxLength);
            memset(testP, 0,sizeof(char) * TESTDATA_MAP[n].m_SQLMaxLength);
            SQLLEN size;
            ConvertSQLToC(3, 0, tmpDesc, TESTDATA_MAP[n].m_ODBCDataType, &testSrc, sizeof(testSrc), TESTDATA_MAP[n].CDataType, testP, TESTDATA_MAP[n].m_SQLMaxLength, &size, false, tmpbuf, iconv);
            commonSwitch(TESTDATA_MAP[n].CDataType, testP, n);    
            break;
        }
        case SQL_CHAR:
        case SQL_WCHAR:
        case SQL_VARCHAR:
        case SQL_WVARCHAR: 
        case SQL_LONGVARCHAR:
             break;//TODO
        case SQL_NUMERIC:
//             SQL_NUMERIC_STRUCT testSrc;
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
            EXPECT_TRUE(false) << "the DataType is :" << TESTDATA_MAP[n].m_ODBCDataType;
            break;
    } 
}
