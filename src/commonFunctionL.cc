#include "commonFunctionL.h"
#include "testDataL.h"
#include "init.h"
using namespace ODBC;
#include "ctosqlconv.h"


void callSubCtosql(int n, CDescRec* tmpDesc){
   
    string s = TESTDATA_MAPL[n].cValue;
    initDesc(tmpDesc, TESTDATA_MAPL[n]); 
    ICUConverter* iconv;
    char* tmpbuf = NULL;

 
    switch(TESTDATA_MAPL[n].CDataType){
        case SQL_C_TINYINT:
        case SQL_C_STINYINT:{
            char testSrc = stringToNum<int>(s); 
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            SQLLEN size;
            ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv);
            commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
            break;
        }
        case SQL_C_BIT:
        case SQL_C_UTINYINT:{
            unsigned char testSrc = stringToNum<int>(s); 
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            SQLLEN size;
            ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv);
            commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
            break;

                            
        }
        case SQL_C_SHORT:
        case SQL_C_SSHORT:{
            short testSrc = stringToNum<short>(s); 
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            SQLLEN size;
            ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv);
            commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
            break;
        } 
        case SQL_C_USHORT:{
            unsigned short testSrc = stringToNum<unsigned short>(s); 
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            SQLLEN size;
            ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv);
            commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
            break;
 
        } 
        case SQL_C_SLONG:
        case SQL_C_LONG:{
            long testSrc = stringToNum<long>(s); 
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            SQLLEN size;
            ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv);
            commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
            break;
 
        }
        case SQL_C_ULONG:{
            unsigned  long testSrc = stringToNum<unsigned long>(s); 
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            SQLLEN size;
            ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv);
            commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
            break;
        }
        case SQL_C_SBIGINT:{
            long long  testSrc = stringToNum<long long>(s); 
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            SQLLEN size;
            ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv);
            commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
            break;
 
        }
        case SQL_C_UBIGINT:{
            unsigned long long  testSrc = stringToNum<unsigned long long >(s); 
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            SQLLEN size;
            ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv);
            commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
            break;
 
        }
        case SQL_C_FLOAT:{
            float testSrc = stringToNum<float>(s); 
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            SQLLEN size;
            ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv);
            commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
            break;
 
        }
        case SQL_C_DOUBLE:{    
            double testSrc = stringToNum<double>(s); 
            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLMaxLength);
            SQLLEN size;
            ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv);
            commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
            break;
 
                              
        }
        default:
        break;
    }
 
}

void commonSwitchctosql(int m_ODBCDataType, SQLPOINTER testP, int n){
    

    switch(m_ODBCDataType){
        
        case SQL_BIT:{
            char mtarget = *(char *)testP;
            char sqldata = stringToNum<int>(TESTDATA_MAPL[n].sqlValue);
            EXPECT_FLOAT_EQ(sqldata, mtarget) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
            delete((char *)testP);
            break; 
        }
        case SQL_TINYINT:{

                             if(TESTDATA_MAPL[n].m_DescUnsigned)
                             {
                                 unsigned char mtarget = *(unsigned char *)testP;
                                 unsigned char sqldata = stringToNum<int>(TESTDATA_MAPL[n].sqlValue);
                                 EXPECT_FLOAT_EQ(sqldata, mtarget) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                 delete((unsigned char *)testP);

                             }
                             else
                             {

                                 char mtarget = *(char *)testP;
                                 char sqldata = stringToNum<int>(TESTDATA_MAPL[n].sqlValue);
                                 EXPECT_FLOAT_EQ(sqldata, mtarget) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                 delete((char *)testP);

                             }
                             break; 

                         }
        case SQL_SMALLINT:{

                              if(TESTDATA_MAPL[n].m_DescUnsigned)
                              {

                                  unsigned short   mtarget = *(unsigned short *)testP;
                                  unsigned short   sqldata = stringToNum<unsigned short>(TESTDATA_MAPL[n].sqlValue);
                                  EXPECT_FLOAT_EQ((unsigned short)sqldata, (unsigned short)mtarget) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;

                                  delete((unsigned short *)testP);
                              }
                              else
                              {

                                  short   mtarget = *(short *)testP;
                                  short   sqldata = stringToNum<short>(TESTDATA_MAPL[n].sqlValue);
                                  EXPECT_FLOAT_EQ((short)sqldata, mtarget) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;

                                  delete((short *)testP);
                              }
                              break; 

                          }
        case SQL_INTEGER:{

                             if(TESTDATA_MAPL[n].m_DescUnsigned)
                             {

                                 unsigned int mtarget = *(unsigned int *)testP;
                                 unsigned int sqldata = stringToNum<unsigned int>(TESTDATA_MAPL[n].sqlValue);
                                 EXPECT_FLOAT_EQ(sqldata, mtarget) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                 delete((unsigned int *)testP);

                             }
                             else{

                                 int mtarget = *(int *)testP;
                                 int sqldata = stringToNum<int>(TESTDATA_MAPL[n].sqlValue);
                                 EXPECT_FLOAT_EQ(sqldata, mtarget) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                 delete((int *)testP);
                             }
                             break;
        }
        case SQL_BIGINT:{

                            if(TESTDATA_MAPL[n].m_DescUnsigned)
                            {
                                unsigned long long  mtarget = *(unsigned long long  *)testP;
                                unsigned long long  sqldata = stringToNum<unsigned long long>(TESTDATA_MAPL[n].sqlValue);
                                EXPECT_FLOAT_EQ(sqldata, mtarget) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                delete((unsigned long long *)testP);

                            }
                            else
                            {

                                long long  mtarget = *(long long  *)testP;
                                long long  sqldata = stringToNum<long long>(TESTDATA_MAPL[n].sqlValue);
                                EXPECT_FLOAT_EQ(sqldata, mtarget) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                delete((long long *)testP);
                            }
            break; 
        }
        case SQL_REAL:
            break;//TODO
        case SQL_DOUBLE:{
        
            double mtarget = *(double *)testP;
            double sqldata = stringToNum<double>(TESTDATA_MAPL[n].sqlValue);
            EXPECT_FLOAT_EQ(sqldata, mtarget) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
            delete((double *)testP);
            break; 
        }
        case SQL_CHAR:
        case SQL_WCHAR:
        case SQL_VARCHAR:
        case SQL_WVARCHAR: 
        case SQL_LONGVARCHAR:
             break;//TODO
        case SQL_NUMERIC:
             SQL_NUMERIC_STRUCT mtarget = *(SQL_NUMERIC_STRUCT*)testP;

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
            EXPECT_TRUE(false) << "the DataType is :" << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName;
            break;
    } 
}




