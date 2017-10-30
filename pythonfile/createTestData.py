import sys
from preDefine import defType
from printTofile import printToFile
from printTofile import printNumeric
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

    for sql_k, sql_v in defType.sql_type_max_min.items():
        for c_k, c_v in defType.sql_c_max_min.items():
            for i in range(3):
                print(count, end=',')
                count += 1
                outputData = functionList.get(i, return0)(sql_v[i], c_v[i])
                printToFile(c_k, sql_k, outputData, count, 0)

    for sql_k, sql_v in defType.sql_type_max_min_unsigned.items():
        for c_k, c_v in defType.sql_c_max_min.items():
            for i in range(2):
                print(count, end=',')
                count += 1
                outputData = functionListForUnsign.get(i, return0)(sql_v[i], c_v[i + 1])
                printToFile(c_k, sql_k, outputData, count, 1)

    num = 0
    for i in range(18):
        num = num * 10 + 9
        precision = i + 1
        count += 1
        print(count, end=',')
        printNumeric(precision, 0, 0, num, count)


def main():
    writeFileHead('testData.h')
    doJob()
    writeFileEnd('testData.h')


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

def writeFileEnd(file):
    FileEnd = '''
};
#endif
        '''
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