import sys
from preDefine import defType
import DoJob
def getMax(a, b):
    if a > b :
        return a
    else:
        return b
def getMin(a, b):
    if a < b:
        return a
    else:
        return b
def return0(a, b):
    return 0
functionList = {
    0 : getMax,
    1 : return0,
    2 : getMin
}
functionListForUnsign = {
    1 : getMin,
    0 : getMax,
    2 : return0
}

#count = 0
def doJob():
    count = 0
    result = [0, '']
    result[0] = count
    result[1] = ''
    result = DoJob.doSignedJob(result[0], result[1])
    #result = DoJob.doUnsignedJob(result[0], result[1])
                                       #result[0] =DoJob. doNumericJobTest(count)
    result = DoJob.doNumericJob(result[0], result[1])
    result = DoJob.doNumericJobMinus(result[0], result[1])
    result = DoJob.doNumericJobUnsigned(result[0], result[1])
    result = DoJob.doNumericJobScale(result[0], result[1])

    result = DoJob.doCNumericScale(result[0], result[1])
    result = DoJob.doCNumericJob(result[0], result[1])
    result = DoJob.doTimeStamp(result[0], result[1])
    result = DoJob.doChar(result[0], result[1])
    result = DoJob.doCChar(result[0], result[1])
    result = DoJob.doCCharUnsigned(result[0], result[1])
    result = DoJob.doWChar(result[0], result[1])
    result = DoJob.doWCChar(result[0], result[1])
    result = DoJob.doWCCharUnsigned(result[0], result[1])
    result = DoJob.doNumericChar(result[0], result[1])
    return result[1]



def main():
    writeFileHead('testData.h')
    data = doJob()
    writeFileEnd('testData.h', data)


def writeFileHead(file):
    FileHeader = '''\
#ifndef __TESTDATA__
#define __TESTDATA__
#include<sqltypes.h>
#include"table.h"
TESTDATA_TABLE TESTDATA_MAP[] = {
    '''
    with open(file, 'w') as f:
        f.write(
            FileHeader
        )

def writeFileEnd(file, data):
    FileEnd = '''
};
#endif
//%s
        '''%(data)
    with open(file, 'a') as f:
        f.write(
            FileEnd
        )





if __name__=='__main__':
    main()



# def printToFile(c_k, sql_k, outputData, count, isunsigned):
#     with open('testDataL.h', 'a') as f:
#         f.write(
#             '''{
#         %s//const char *sqlValue;                       ,
#         %s//const char *cValue;                         ,
#         %d//int CDataType;                             ,
#         %d//int CDataLen;                              ,
#         %d//int m_ODBCDataType;                        ,
#         %s//int m_SQLDataType;                         ,
#         %d//int m_SQLMaxLength;                        ,
#         %d//int m_DescUnsigned;                        ,
#         %d//int Precision;                             ,
#         %d//int Scale;                                 ,
#         %d//int m_SQLCharset;                          ,
#         %d//int m_SQLDatetimeCode;                     ,
#         %d//int m_SQLOctetLength;                      ,
#         %d//char numeric_sign;  /* 1=+ 0=- */          ,
#         %d//char numeric_value[SQL_MAX_NUMERIC_LEN];   ,
#     },
#     '''%(
#           str(outputData)          ,
#           str(outputData)          ,
#           defType.sql_c_type[c_k]  ,
#           defType.sql_c_Len[c_k]   ,
#           defType.sql_type[sql_k]  ,
#           defType.sql_type_Datatype[sql_k],
#           defType.sql_type_len[sql_k]     ,
#           isunsigned               ,
#           0                        ,
#           0                        ,
#           0                        ,
#           0                        ,
#           0                        ,
#           0                        ,
#           0)
#       )'''