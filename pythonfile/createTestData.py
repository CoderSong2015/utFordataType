import sys
from preDefine import defType

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
def printToFile(sql_k, c_k, outputData, count, isunsigned):
    with open('testData1.h', 'a') as f:
        f.write(
            '''{
        "%s",
        %s,
        "%s",
        %s,
        %d,
        %s,
        %d,//is unsigened 
        %d,//int m_DescType;                        
        %d,//int m_DescConciseType;
        %d,//int m_DescDatetimeIntervalCode;
        %d,//int m_DescOctetLength;
        %d,//int m_DescLength;                      
        %d,//int m_DescPrecision;                   
        %d,//int m_DescScale;                       
        %d,//int m_DescDatetimeIntervalPrecision;   
        %d,//int m_DescFixedPrecScale;                
        %d,//int m_DescNullable;                    
        %d,//int m_SQLCharset;                      
        %d,//int m_ODBCCharset;                     
        %d,//int m_SQLDataType;                     
        %d,//int m_SQLPrecision;                    
        %d,//int m_ODBCPrecision;                    
        %d,//int m_ODBCScale;
        %d,//int m_SQLDatetimeCode;
        %d,//int m_SQLOctetLength;
        %d,//int m_SQLMaxLength;
        %d//int m_DescReturnedLength;
    },
    '''%(

               str(outputData),
               defType.sql_type[sql_k],
               str(outputData),
               defType.sql_c_type[c_k],
               defType.sql_c_Len[c_k],
               defType.sql_type[sql_k],
               isunsigned,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0
            )
        )
    pass


def printToFileL(c_k, sql_k, outputData, count, isunsigned):
    with open('testDataL.h', 'a') as f:
        f.write(
            '''{
        "%s",
        %s,
        "%s",
        %s,
        %d,
        %s,
        %d,//is unsigened 
        %d,//int m_DescType;                        
        %d,//int m_DescConciseType;
        %d,//int m_DescDatetimeIntervalCode;
        %d,//int m_DescOctetLength;
        %d,//int m_DescLength;                      
        %d,//int m_DescPrecision;                   
        %d,//int m_DescScale;                       
        %d,//int m_DescDatetimeIntervalPrecision;   
        %d,//int m_DescFixedPrecScale;                
        %d,//int m_DescNullable;                    
        %d,//int m_SQLCharset;                      
        %d,//int m_ODBCCharset;                     
        %d,//int m_SQLDataType;                     
        %d,//int m_SQLPrecision;                    
        %d,//int m_ODBCPrecision;                    
        %d,//int m_ODBCScale;
        %d,//int m_SQLDatetimeCode;
        %d,//int m_SQLOctetLength;
        %d,//int m_SQLMaxLength;
        %d//int m_DescReturnedLength;
    },
    '''%(

               str(outputData),
               defType.sql_c_type[c_k],
               str(outputData),
               defType.sql_type[sql_k],
               defType.sql_type_len[sql_k],
               defType.sql_type[sql_k],
               isunsigned,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0,
               0
            )
        )
    pass
def doJob():
    count = 0

    for sql_k,sql_v in defType.sql_type_max_min.items():
        for c_k,c_v in defType.sql_c_max_min.items():
            for i in range(3):
                print(count, end = ',')
                count += 1
                outputData = functionList.get(i, return0)(sql_v[i], c_v[i])
                printToFile(sql_k, c_k, outputData, count, 0)

    for sql_k,sql_v in defType.sql_type_max_min_unsigned.items():
        for c_k,c_v in defType.sql_c_max_min.items():
            for i in range(2):
                print(count, end = ',')
                count += 1
                outputData = functionListForUnsign.get(i, return0)(sql_v[i], c_v[i + 1])
                printToFile(sql_k, c_k, outputData, count, 1)


def doJobL():
    count = 0

    for sql_k, sql_v in defType.sql_type_max_min.items():
        for c_k, c_v in defType.sql_c_max_min.items():
            for i in range(3):
                print(count, end=',')
                count += 1
                outputData = functionList.get(i, return0)(sql_v[i], c_v[i])
                printToFileL(c_k, sql_k, outputData, count, 0)

    for sql_k, sql_v in defType.sql_type_max_min_unsigned.items():
        for c_k, c_v in defType.sql_c_max_min.items():
            for i in range(2):
                print(count, end=',')
                count += 1
                outputData = functionListForUnsign.get(i, return0)(sql_v[i], c_v[i + 1])
                printToFileL(c_k, sql_k, outputData, count, 1)
def main():
    writeFileHead('testDataL.h')
    doJobL()
    writeFileEnd('testDataL.h')


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
}
#endif
        '''
    with open(file, 'a') as f:
        f.write(
            FileEnd
        )

if __name__=='__main__':
    main()
