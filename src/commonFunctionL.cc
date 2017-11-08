#include "commonFunctionL.h"
#include "testDataL.h"
#include "init.h"
#define LCHAR (c)  L##"##c##""
using namespace ODBC;
#include "ctosqlconv.h"


void tconvert(unsigned long long aa,SQL_NUMERIC_STRUCT * ptr)
{
    int i = 0;
    unsigned long long last = aa;
    unsigned long long n = 1;
    int                m = 0;
    for(i=0;i<15;i++) 
    {
        if(aa > 0)
        {

            m  = last % 256;
            ptr->val[i] = m;
            last = last/256;

        }
    }

}
void callSubCtosql(int n, CDescRec* tmpDesc){
    unsigned char error[256]={
        0
    };
    string s = TESTDATA_MAPL[n].cValue;
    string t = TESTDATA_MAPL[n].sqlValue;
    ICUConverter* iconv = new ICUConverter;
    char* tmpbuf = NULL;
    if(TESTDATA_MAPL[n].m_ODBCDataType == SQL_NUMERIC)
    {

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

    }

    initDesc(tmpDesc, TESTDATA_MAPL[n]); 

#if 0
    TESTDATA_MAPL[n].m_ODBCDataType  = SQL_WVARCHAR;//
    TESTDATA_MAPL[n].m_SQLOctetLength = 404;
    TESTDATA_MAPL[n].Precision = 200;
#endif 

    switch(TESTDATA_MAPL[n].CDataType){
        case SQL_C_DEFAULT:
            break;
        case SQL_C_TINYINT:
        case SQL_C_STINYINT:{
                                char testSrc = stringToNum<int>(s); 
                                SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                                memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                                SQLLEN size;
                                ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv,error);
                                commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
                                break;
                            }
        case SQL_C_BIT:
        case SQL_C_UTINYINT:{
                                unsigned char testSrc = stringToNum<int>(s); 
                                SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                                memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                                SQLLEN size;
                                ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv,error);
                                commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
                                break;


                            }
        case SQL_C_SHORT:
        case SQL_C_SSHORT:{
                              short testSrc = stringToNum<short>(s); 
                              SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                              memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                              SQLLEN size;
                              ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv,error);
                              commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
                              break;
                          } 
        case SQL_C_USHORT:{
                              unsigned short testSrc = stringToNum<unsigned short>(s); 
                              SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                              memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                              SQLLEN size;
                              ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv,error);
                              commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
                              break;

                          } 
        case SQL_C_SLONG:
        case SQL_C_LONG:{
                            long testSrc = stringToNum<long>(s); 
                            SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                            memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                            SQLLEN size;
                            ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv,error);
                            commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
                            break;

                        }
        case SQL_C_ULONG:{
                             unsigned  long testSrc = stringToNum<unsigned long>(s); 
                             SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                             memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                             SQLLEN size;
                             ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv,error);
                             commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
                             break;
                         }
        case SQL_C_SBIGINT:{
                               long long  testSrc = stringToNum<long long>(s); 
                               SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                               memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                               SQLLEN size;
                               ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv,error);
                               commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
                               break;

                           }
        case SQL_C_UBIGINT:{
                               unsigned long long  testSrc = stringToNum<unsigned long long >(s); 
                               SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                               memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                               SQLLEN size;
                               ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv,error);
                               commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
                               break;

                           }
        case SQL_C_FLOAT:{
                             float testSrc = stringToNum<float>(s); 
                             SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                             memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                             SQLLEN size;
                             ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv,error);
                             commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
                             break;

                         }
        case SQL_C_DOUBLE:{    
                              double testSrc = stringToNum<double>(s); 
                              SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                              memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                              SQLLEN size;
                              ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv,error);
                              commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
                              break;


                          }
        case SQL_C_NUMERIC:
                          {

                              unsigned  long long testLong = stringToNum<unsigned long long >(s); 
                              SQL_NUMERIC_STRUCT testSrc;
                              testSrc.precision = TESTDATA_MAPL[n].Precision;
                              testSrc.scale = TESTDATA_MAPL[n].Scale;
                              testSrc.sign  = TESTDATA_MAPL[n].m_DescUnsigned ? 0 : 1;
                              for(int i =0;i<16;i++)
                                  testSrc.val[i] = 0;
                              tconvert(testLong,&testSrc);
                              SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                              memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                              SQLLEN size;
                              ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv,error);
                              commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    

                              break;
                          }
        case SQL_C_WCHAR:
                          {
                              int translateLength = 0;
                              char tmp[60] = "";
                              ICUConverter::m_AppUnicodeType = 1;
                              int  rc = iconv->LocaleToWChar((char*)TESTDATA_MAPL[n].cValue, 30, (UChar *)tmp, 60, &translateLength, (char *)error);
                              SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                              memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                              SQLLEN size;
                              ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, (void *)tmp, SQL_NTS, testP, tmpDesc, false, iconv,error);
                              commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
                              break;
                          }
        case SQL_C_CHAR:
                          {
                              SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                              memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength);
                              SQLLEN size;
                              ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, (void *)TESTDATA_MAPL[n].cValue, strlen(TESTDATA_MAPL[n].cValue), testP, tmpDesc, false, iconv,error);
                              commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
                              break;

                          }
#if 1
        case SQL_C_DATE:
        case SQL_C_TYPE_DATE:
                          {

                              DATE_STRUCT testSrc;
                              testSrc.year  = TESTDATA_MAPL[n].year;
                              testSrc.month = TESTDATA_MAPL[n].month;
                              testSrc.day   = TESTDATA_MAPL[n].day;
                              SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength+1);
                              memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength+1);
                              SQLLEN size;
                              ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv,error);
                              commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
                              break;
                          }
        case SQL_C_TIME:
        case SQL_C_TYPE_TIME: 
                          {
                              TIME_STRUCT testSrc;
                              testSrc.hour  = TESTDATA_MAPL[n].hour;
                              testSrc.minute = TESTDATA_MAPL[n].minute;
                              testSrc.second = TESTDATA_MAPL[n].second;
                              SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength+1);
                              memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength+1);
                              SQLLEN size;
                              ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv,error);
                              commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
                              break;
                          }
        case SQL_C_TIMESTAMP:
        case SQL_C_TYPE_TIMESTAMP:
                          {


                              TIMESTAMP_STRUCT testSrc;
                              testSrc.year = TESTDATA_MAPL[n].year;
                              testSrc.month = TESTDATA_MAPL[n].month;
                              testSrc.day   = TESTDATA_MAPL[n].day;
                              testSrc.hour  = TESTDATA_MAPL[n].hour;
                              testSrc.minute = TESTDATA_MAPL[n].minute;
                              testSrc.second = TESTDATA_MAPL[n].second;
                              testSrc.fraction =atoi(TESTDATA_MAPL[n].fraction);
                              SQLPOINTER testP = malloc(sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength+1);
                              memset(testP, 0,sizeof(char) * TESTDATA_MAPL[n].m_SQLOctetLength+1);
                              SQLLEN size;
                              ConvertCToSQL(3,TESTDATA_MAPL[n].CDataType, &testSrc, sizeof(testSrc), testP, tmpDesc, false, iconv,error);
                              commonSwitchctosql(TESTDATA_MAPL[n].m_ODBCDataType, testP, n);    
                              break;

                          }
#endif 
        case SQL_C_BINARY:
        case SQL_C_INTERVAL_MONTH:
        case SQL_C_INTERVAL_YEAR:
        case SQL_C_INTERVAL_YEAR_TO_MONTH:
        case SQL_C_INTERVAL_DAY:
        case SQL_C_INTERVAL_HOUR:
        case SQL_C_INTERVAL_MINUTE:
        case SQL_C_INTERVAL_SECOND:
        case SQL_C_INTERVAL_DAY_TO_HOUR:
        case SQL_C_INTERVAL_DAY_TO_MINUTE:
        case SQL_C_INTERVAL_DAY_TO_SECOND:
        case SQL_C_INTERVAL_HOUR_TO_MINUTE:
        case SQL_C_INTERVAL_HOUR_TO_SECOND:
        case SQL_C_INTERVAL_MINUTE_TO_SECOND:
                          break;
        default:
                          break;
    }

}

void commonSwitchctosql(int m_ODBCDataType, SQLPOINTER testP, int n){

    int flag = 0;
    int offset = 0;
    int   translateLength =0;

    ICUConverter* iconv = new ICUConverter;

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
                            double sqldata = 0;
                            if(TESTDATA_MAPL[n].CDataType == SQL_C_NUMERIC)
                            sqldata = stringToNum<double>(TESTDATA_MAPL[n].cValue);
                                else
                            sqldata = stringToNum<double>(TESTDATA_MAPL[n].sqlValue);
                            EXPECT_FLOAT_EQ(sqldata, mtarget) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                            delete((double *)testP);
                            break; 
                        }
        case SQL_WCHAR:
                        {
                            char error[256] ={
                                0                            
                            };
                            switch (TESTDATA_MAPL[n].CDataType)
                            {
                                case SQL_C_TYPE_DATE:
                                case SQL_C_DATE:
                                    {
                                        char timestamptmp[30]= {0};
                                        sprintf(timestamptmp,"%04d-%02d-%02d",TESTDATA_MAPL[n].year,TESTDATA_MAPL[n].month,TESTDATA_MAPL[n].day);

                                        UChar tmp[60]= {0};

                                        int  rc = iconv->LocaleToWChar((char*)timestamptmp, 30, (UChar *)tmp, 60, &translateLength, (char *)error);
                                        if(NULL == wcsstr((wchar_t *)testP+1,(wchar_t *)tmp))
                                            flag = 0;
                                        else 
                                            flag = 1;

                                        EXPECT_TRUE(flag) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((char *)testP);

                                        break;
                                    }
                                case SQL_C_TYPE_TIME:
                                case SQL_C_TIME:
                                    {
                                        char timestamptmp[30]= {0};
                                        sprintf(timestamptmp,"%02d:%02d:%02d",TESTDATA_MAPL[n].hour,TESTDATA_MAPL[n].minute,TESTDATA_MAPL[n].second);

                                        UChar tmp[60]= {0};
                                        
                                        int  rc = iconv->LocaleToWChar((char*)timestamptmp, 30, (UChar *)tmp, 60, &translateLength, (char *)error);

                                        if(NULL == wcsstr((wchar_t *)testP,(wchar_t *)tmp))
                                            flag = 0;
                                        else 
                                            flag = 1;
                                            


                                        EXPECT_TRUE(flag) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((char *)testP);
                                       break;

                                    }
                                case SQL_C_TIMESTAMP:
                                case SQL_C_TYPE_TIMESTAMP:
                                    {
                                        char timestamptmp[30]= {0};
                                        sprintf(timestamptmp,"%04d-%02d-%02d %02d:%02d:%02d.%06d",TESTDATA_MAPL[n].year,TESTDATA_MAPL[n].month,TESTDATA_MAPL[n].day,TESTDATA_MAPL[n].hour,TESTDATA_MAPL[n].minute,TESTDATA_MAPL[n].second,atol(TESTDATA_MAPL[n].fraction)/1000);



                                        UChar tmp[60]= {0};
                                        
                                       // int  rc = iconv->TranslateISO88591(0, (char*)timestamptmp, 30, (char*)tmp, 60, &translateLength, error);
                                        int  rc = iconv->LocaleToWChar((char*)timestamptmp, 30, (UChar *)tmp, 60, (int *)&translateLength, (char *)error);
                                        int m = strlen(timestamptmp);
                                        if(NULL == wcsstr((wchar_t *)testP,(wchar_t *)tmp))
                                            flag = 0;
                                        else 
                                            flag = 1;
                                            

                                        EXPECT_TRUE(flag) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((char *)testP);
                                       break;

                                    }

                                default:
                                    {

                                        char timetmp[30]={0};
                                        UChar tmp[60]= {0};
                                        int m = strlen(TESTDATA_MAPL[n].cValue);
                                        strncpy(timetmp,TESTDATA_MAPL[n].cValue,m);

                                        //if(TESTDATA_MAPL[n].CDataType == SQL_C_FLOAT||TESTDATA_MAPL[n].CDataType == SQL_C_DOUBLE)
                                        if(1)
                                        {
                                            if(*(char * )testP == timetmp[0])
                                                flag = 1;
                                            else 
                                                flag = 0;
                                        }
                                        else
                                        {

                                            int  rc = iconv->LocaleToWChar((char*)timetmp, 30, (UChar *)tmp, 60, (int*)&translateLength,(char *) error);

                                            u_memset((UChar*)tmp+m,L' ',60-m);
                                            if(NULL == wcsstr((wchar_t *)testP,(wchar_t *)tmp))
                                                flag = 0;
                                            else 
                                                flag = 1;
                                        }


                                        EXPECT_TRUE(flag) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((char *)testP);

                                        break;//TODO

                                    }

                            }
                            break;
                        }
        case SQL_WVARCHAR: 
                        {
                            int offset = 2;
                            char error[256] ={
                                0                            
                            };
                            switch (TESTDATA_MAPL[n].CDataType)
                            {
                                case SQL_C_TYPE_DATE:
                                case SQL_C_DATE:
                                    {
                                        char timestamptmp[30]= {0};
                                        sprintf(timestamptmp,"%04d-%02d-%02d",TESTDATA_MAPL[n].year,TESTDATA_MAPL[n].month,TESTDATA_MAPL[n].day);

                                        UChar tmp[60]= {0};
                                        int  rc = iconv->LocaleToWChar((char*)timestamptmp, 30, (UChar *)tmp, 60, &translateLength, (char *)error);
                                        if(NULL == wcsstr((wchar_t *)(testP+offset),(wchar_t *)tmp))
                                            flag = 0;
                                        else 
                                            flag = 1;

                                        EXPECT_TRUE(flag) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((char *)testP);

                                        break;
                                    }
                                case SQL_C_TYPE_TIME:
                                case SQL_C_TIME:
                                    {
                                        char timestamptmp[30]= {0};
                                        sprintf(timestamptmp,"%02d:%02d:%02d",TESTDATA_MAPL[n].hour,TESTDATA_MAPL[n].minute,TESTDATA_MAPL[n].second);


                                        UChar tmp[60]= {0};
                                        int  rc = iconv->LocaleToWChar((char*)timestamptmp, 30, (UChar *)tmp, 60, &translateLength, (char *)error);


                                        if(NULL == wcsstr((wchar_t *)(testP+offset),(wchar_t *)tmp))
                                            flag = 0;
                                        else 
                                            flag = 1;



                                        EXPECT_TRUE(flag) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((char *)testP);
                                        break;

                                    }
                                case SQL_C_TIMESTAMP:
                                case SQL_C_TYPE_TIMESTAMP:
                                    {
                                        char timestamptmp[30]= {0};
                                        sprintf(timestamptmp,"%04d-%02d-%02d %02d:%02d:%02d.%06d",TESTDATA_MAPL[n].year,TESTDATA_MAPL[n].month,TESTDATA_MAPL[n].day,TESTDATA_MAPL[n].hour,TESTDATA_MAPL[n].minute,TESTDATA_MAPL[n].second,atol(TESTDATA_MAPL[n].fraction)/1000);


                                        UChar tmp[60]= {0};
                                        int  rc = iconv->LocaleToWChar((char*)timestamptmp, 30, (UChar *)tmp, 60, &translateLength, (char *)error);

                                        int m = strlen(timestamptmp);
                                        if(NULL == wcsstr((wchar_t *)(testP+offset),(wchar_t *)tmp))
                                            flag = 0;
                                        else 
                                            flag = 1;


                                        EXPECT_TRUE(flag) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((char *)testP);
                                        break;

                                    }

                                default:
                                    {

                                        char timetmp[30]={0};
                                        UChar tmp[60]= {0};
                                        wchar_t  tmp1[256] = L"";
                                        int m = strlen(TESTDATA_MAPL[n].cValue);
                                        strncpy(timetmp,TESTDATA_MAPL[n].cValue,m);

                                        //if(TESTDATA_MAPL[n].CDataType == SQL_C_FLOAT||TESTDATA_MAPL[n].CDataType == SQL_C_DOUBLE)
                                        if(1)
                                        {
                                            if(*(char * )(testP+offset) == timetmp[0])
                                                flag = 1;
                                            else 
                                                flag = 0;
                                        }
                                        else
                                        {


                                            //int  rc = iconv->LocaleToWChar((char*)timetmp, 30, (UChar *)tmp, 60, &translateLength, (char *)error);
                                           // u_memset((UChar*)(tmp+18),L' ',60-18);
                                           swprintf(tmp1,256,L"%s",TESTDATA_MAPL[n].cValue);

                                           EXPECT_STREQ((wchar_t *)(testP+offset),tmp1) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                            if(NULL == wcsstr((wchar_t *)(testP+offset),(wchar_t *)tmp))
                                                flag = 0;
                                            else 
                                                flag = 1;
                                        }


                                        EXPECT_TRUE(flag) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((char *)testP);

                                        break;//TODO

                                    }

                            }
                            break;


                        }
                        {
                            break;
                        }
        case SQL_CHAR:
                        {
                            offset = 0;
                            switch (TESTDATA_MAPL[n].CDataType)
                            {
                                case SQL_C_TYPE_DATE:
                                case SQL_C_DATE:
                                    {
                                        char timestamptmp[30]= {0};
                                        sprintf(timestamptmp,"%04d-%02d-%02d",TESTDATA_MAPL[n].year,TESTDATA_MAPL[n].month,TESTDATA_MAPL[n].day);
                                        if(strstr((char*)testP+offset,timestamptmp) == NULL)
                                            flag = 0;
                                        else 
                                            flag = 1;


                                        EXPECT_TRUE(flag) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((char  *)testP);

                                        break;
                                    }
                                case SQL_C_TYPE_TIME:
                                case SQL_C_TIME:
                                    {
                                        char timestamptmp[30]= {0};
                                        sprintf(timestamptmp+2,"%02d:%02d:%02d",TESTDATA_MAPL[n].hour,TESTDATA_MAPL[n].minute,TESTDATA_MAPL[n].second);

                                        if(strstr((char*)testP+offset,timestamptmp) == NULL)
                                            flag = 0;
                                        else 
                                            flag = 1;

                                        EXPECT_TRUE(1) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((char *)testP);

                                        break;

                                    }
                                case SQL_C_TIMESTAMP:
                                case SQL_C_TYPE_TIMESTAMP:
                                    {

                                        char timestamptmp[30]= {0};
                                        sprintf(timestamptmp,"%04d-%02d-%02d %02d:%02d:%02d.%06d",TESTDATA_MAPL[n].year,TESTDATA_MAPL[n].month,TESTDATA_MAPL[n].day,TESTDATA_MAPL[n].hour,TESTDATA_MAPL[n].minute,TESTDATA_MAPL[n].second,atol(TESTDATA_MAPL[n].fraction)/1000);

                                        if(strstr((char*)testP+offset,timestamptmp) == NULL)
                                            flag = 0;
                                        else 
                                            flag = 1;

                                        EXPECT_TRUE(1) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((char *)testP);

                                        break;

                                    }
                                default:
                                    {

                                        char tmp[30]={0};
                                        char timestamptmp[30]= {0};
                                        strncpy(timestamptmp,TESTDATA_MAPL[n].cValue,30);
                                        if(strstr((char*)testP+offset,timestamptmp) == NULL)
                                            flag = 0;
                                        else 
                                            flag = 1;

                                        EXPECT_TRUE(1) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((char *)testP);



                                        break;//TODO

                                    }

                            }
                            break;

                        }
        case SQL_LONGVARCHAR:
        case SQL_VARCHAR:
                        {
                            if (TESTDATA_MAPL[n].Precision > 32768)
                                offset = 4;
                            else 
                                offset = 2;
                            switch (TESTDATA_MAPL[n].CDataType)
                            {
                                case SQL_C_TYPE_DATE:
                                case SQL_C_DATE:
                                    {
                                        char timestamptmp[30]= {0};
                                        sprintf(timestamptmp,"%04d-%02d-%02d",TESTDATA_MAPL[n].year,TESTDATA_MAPL[n].month,TESTDATA_MAPL[n].day);
                                        if(strstr((char*)testP+offset,timestamptmp) == NULL)
                                            flag = 0;
                                        else 
                                            flag = 1;


                                        EXPECT_TRUE(flag) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((char  *)testP);

                                        break;
                                    }
                                case SQL_C_TYPE_TIME:
                                case SQL_C_TIME:
                                    {
                                        char timestamptmp[30]= {0};
                                        sprintf(timestamptmp+2,"%02d:%02d:%02d",TESTDATA_MAPL[n].hour,TESTDATA_MAPL[n].minute,TESTDATA_MAPL[n].second);

                                        if(strstr((char*)testP+offset,timestamptmp) == NULL)
                                            flag = 0;
                                        else 
                                            flag = 1;

                                        EXPECT_TRUE(1) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((char *)testP);

                                        break;

                                    }
                                case SQL_C_TIMESTAMP:
                                case SQL_C_TYPE_TIMESTAMP:
                                    {

                                        char timestamptmp[30]= {0};
                                        sprintf(timestamptmp,"%04d-%02d-%02d %02d:%02d:%02d.%06d",TESTDATA_MAPL[n].year,TESTDATA_MAPL[n].month,TESTDATA_MAPL[n].day,TESTDATA_MAPL[n].hour,TESTDATA_MAPL[n].minute,TESTDATA_MAPL[n].second,atol(TESTDATA_MAPL[n].fraction)/1000);

                                        if(strstr((char*)testP+offset,timestamptmp) == NULL)
                                            flag = 0;
                                        else 
                                            flag = 1;

                                        EXPECT_TRUE(1) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((char *)testP);

                                        break;

                                    }
                                default:
                                    {

                                        char tmp[30]={0};
                                        char timestamptmp[30]= {0};
                                        strncpy(timestamptmp,TESTDATA_MAPL[n].cValue,30);
                                        if(strstr((char*)testP+offset,timestamptmp) == NULL)
                                            flag = 0;
                                        else 
                                            flag = 1;

                                        EXPECT_TRUE(1) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((char *)testP);



                                        break;//TODO

                                    }

                            }
                            break;

                        }

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
        case SQL_TYPE_DATE:
                        {
                            char datetmp[30]= {0};
                            sprintf(datetmp,"%04d-%02d-%02d",TESTDATA_MAPL[n].year,TESTDATA_MAPL[n].month,TESTDATA_MAPL[n].day);
                            EXPECT_STREQ((char*)testP, datetmp) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                            delete((double *)testP);
                            break;
                        }
        case SQL_TIME:
        case SQL_TYPE_TIME:
                        {
                            char timetmp[30]= {0};
                            sprintf(timetmp,"%02d:%02d:%02d",TESTDATA_MAPL[n].hour,TESTDATA_MAPL[n].minute,TESTDATA_MAPL[n].second);
                            EXPECT_STREQ((char*)testP, timetmp) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                            delete((double *)testP);
                            break;
                        }

        case SQL_TIMESTAMP:
        case SQL_TYPE_TIMESTAMP:
                        {
                            switch (TESTDATA_MAPL[n].CDataType)
                            {
                                case SQL_C_TYPE_DATE:
                                case SQL_C_DATE:
                                    {
                                        char timestamptmp[30]= {0};
                                        sprintf(timestamptmp,"%04d-%02d-%02d 00:00:00.000000",TESTDATA_MAPL[n].year,TESTDATA_MAPL[n].month,TESTDATA_MAPL[n].day);
                                        EXPECT_STREQ((char *)testP, timestamptmp) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((double *)testP);

                                        break;
                                    }
                                case SQL_C_TYPE_TIME:
                                case SQL_C_TIME:
                                    {
                                        char timestamptmp[30]= {0};
                                        sprintf(timestamptmp,"%02d:%02d:%02d.000000",TESTDATA_MAPL[n].hour,TESTDATA_MAPL[n].minute,TESTDATA_MAPL[n].second);
                                        EXPECT_STREQ((char *)(testP+11), timestamptmp) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((double *)testP);

                                        break;

                                    }
                                case SQL_C_TIMESTAMP:
                                case SQL_C_TYPE_TIMESTAMP:
                                    {
                                        char timestamptmp[30]= {0};
                                        sprintf(timestamptmp,"%04d-%02d-%02d %02d:%02d:%02d.%06d",TESTDATA_MAPL[n].year,TESTDATA_MAPL[n].month,TESTDATA_MAPL[n].day,TESTDATA_MAPL[n].hour,TESTDATA_MAPL[n].minute,TESTDATA_MAPL[n].second,atol(TESTDATA_MAPL[n].fraction)/1000);

                                        EXPECT_STREQ((char *)testP, timestamptmp) << "Data type is: " <<TESTDATA_MAPL[n].CTypeName  << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName ;
                                        delete((double *)testP);

                                        break;

                                    }
                                default:
                                    break;
                            }
                            break;
                        }
        case SQL_FLOAT: // no need
                        break;
        default:
                        EXPECT_TRUE(false) << "the DataType is :" << "targettype is: " <<TESTDATA_MAPL[n].SQLTypeName;
                        break;
    } 
}




