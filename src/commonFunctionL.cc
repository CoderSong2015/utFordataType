#include "commonFunctionL.h"
#include "testDataL.h"
#include "init.h"
using namespace ODBC;
#include "ctosqlconv.h"


void callSubCtosql(int n, CDescRec* tmpDesc){
   
    string s = TESTDATA_MAPL[n].cValue;
    ICUConverter* iconv;
    char* tmpbuf = NULL;
    switch (TESTDATA_MAPL[n].Precision)
    {
        case 1:
        case 2:
        case 3:
        case 4:
            if(TESTDATA_MAPL[n].m_DescUnsigned)
                TESTDATA_MAPL[n].m_SQLDataType = SQLTYPECODE_SMALLINT_UNSIGNED;
            else
                TESTDATA_MAPL[n].m_SQLDataType = SQLTYPECODE_SMALLINT;
            break;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            if(TESTDATA_MAPL[n].m_DescUnsigned)
                TESTDATA_MAPL[n].m_SQLDataType = SQLTYPECODE_INTEGER_UNSIGNED;
            else 

                TESTDATA_MAPL[n].m_SQLDataType = SQLTYPECODE_INTEGER;
            break;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
            if(TESTDATA_MAPL[n].m_DescUnsigned)
                TESTDATA_MAPL[n].m_SQLDataType  =SQLTYPECODE_LARGEINT_UNSIGNED;
            else 
                TESTDATA_MAPL[n].m_SQLDataType  =SQLTYPECODE_LARGEINT;
            break;
         default:
            if(TESTDATA_MAPL[n].m_DescUnsigned)
               TESTDATA_MAPL[n].m_SQLDataType  = SQLTYPECODE_NUMERIC_UNSIGNED;
            else
               TESTDATA_MAPL[n].m_SQLDataType  = SQLTYPECODE_NUMERIC;
            break;

    }

    initDesc(tmpDesc, TESTDATA_MAPL[n]); 
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
             {
                 switch(TESTDATA_MAPL[n].m_SQLDataType)
                 {
                     case SQLTYPECODE_TINYINT_UNSIGNED:
                         {
                             unsigned char mtarget = *(unsigned char *)testP;
                             unsigned char sqldata = stringToNum<int>(TESTDATA_MAPL[n].sqlValue);
                             EXPECT_FLOAT_EQ(sqldata, mtarget) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                             delete((unsigned char *)testP);



                             break;

                         }
                     case SQLTYPECODE_TINYINT:
                         {
                             char mtarget = *(char *)testP;
                             char sqldata = stringToNum<int>(TESTDATA_MAPL[n].sqlValue);
                             EXPECT_FLOAT_EQ(sqldata, mtarget) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                             delete((char *)testP);

                             break;

                         }
                     case SQLTYPECODE_SMALLINT_UNSIGNED:
                         {
                             unsigned short   mtarget = *(unsigned short *)testP;
                             unsigned short   sqldata = stringToNum<unsigned short>(TESTDATA_MAPL[n].sqlValue);
                             EXPECT_FLOAT_EQ((unsigned short)sqldata, (unsigned short)mtarget) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;

                             delete((unsigned short *)testP);

                             break;
                         }
                     case SQLTYPECODE_SMALLINT:
                         {

                             short   mtarget = *(short *)testP;
                             short   sqldata = stringToNum<short>(TESTDATA_MAPL[n].sqlValue);
                             EXPECT_FLOAT_EQ((short)sqldata, mtarget) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;

                             delete((short *)testP);


                             break;

                         }
                     case SQLTYPECODE_INTEGER_UNSIGNED:
                         {
                             unsigned int mtarget = *(unsigned int *)testP;
                             unsigned int sqldata = stringToNum<unsigned int>(TESTDATA_MAPL[n].sqlValue);
                             EXPECT_FLOAT_EQ(sqldata, mtarget) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                             delete((unsigned int *)testP);

                             break;

                         }
                     case SQLTYPECODE_INTEGER:
                         {

                             int mtarget = *(int *)testP;
                             int sqldata = stringToNum<int>(TESTDATA_MAPL[n].sqlValue);
                             EXPECT_FLOAT_EQ(sqldata, mtarget) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                             delete((int *)testP);

                             break;
                         }
                     case SQLTYPECODE_LARGEINT:
                         { 
                             long long  mtarget = *(long long  *)testP;
                             long long  sqldata = stringToNum<long long>(TESTDATA_MAPL[n].sqlValue);
                             EXPECT_FLOAT_EQ(sqldata, mtarget) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                             delete((long long *)testP);


                             break;

                         }
                     case SQLTYPECODE_NUMERIC:
                     case SQLTYPECODE_NUMERIC_UNSIGNED:
                         {

                             EXPECT_STREQ(TESTDATA_MAPL[n].sqlValue, (char *)testP) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                             break;
                         }
                     default:
                         break;

                 } 

                 break;
             }
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




