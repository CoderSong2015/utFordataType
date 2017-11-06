from preDefine import defType
from createTestData import functionList,functionListForUnsign
from createTestData import return0
from printTofile import printToFile

def doSignedJob(count, countStr):
    for sql_k, sql_v in defType.sql_type_max_min.items():
        for c_k, c_v in defType.sql_c_max_min.items():
            for i in range(3):
                countStr = countStr + str(count) + ','
                count += 1
                outputData = functionList.get(i, return0)(sql_v[i], c_v[i])
                printToFile(CDataType= defType.sql_c_type[c_k],
                            CDataLen= defType.sql_c_Len[c_k] ,
                            ODBCDataType= defType.sql_type[sql_k],
                            SQLDataType= defType.sql_type_Datatype[sql_k],
                            SQLMaxLength= defType.sql_type_len[sql_k],
                            sqlValue = outputData,
                            cValue = outputData,
                            count = count,
                            SQLOctetLength =  defType.sql_type_len[sql_k],
                            DescUnsigned = 0)
    #countStr = countStr + '||'
    return count, countStr

def doUnsignedJob(count, countStr):
    for sql_k, sql_v in defType.sql_type_max_min_unsigned.items():
        for c_k, c_v in defType.sql_c_max_min.items():
            for i in range(2):
                countStr = countStr + str(count) + ','
                count += 1
                outputData = functionListForUnsign.get(i, return0)(sql_v[i], c_v[i + 1])
                printToFile(CDataType= defType.sql_c_type[c_k],
                            CDataLen= defType.sql_c_Len[c_k] ,
                            ODBCDataType= defType.sql_type[sql_k],
                            SQLDataType= defType.sql_type_Datatype[sql_k],
                            SQLMaxLength= defType.sql_type_len[sql_k],
                            sqlValue = outputData,
                            cValue = outputData,
                            count = count,
                            SQLOctetLength =  defType.sql_type_len[sql_k],
                            DescUnsigned = 1)
    return count, countStr

'''
def doNumericJobTest(count, countStr):
    num = 0
    for i in range(18):
        num = num * 10 + 9
        precision = i + 1

        countStr = countStr + str(count) + ','
        count += 1
        printNumericTest(precision, 0, 0, num, count)

    #countStr = countStr + '||'
    return count, countStr
'''
def doNumericJob(count, countStr):
    num = 0

    for i in range(18):
        num = num * 10 + 9
        precision = i + 1
        for c_k, c_v in defType.sql_c_max_min.items():
            if (defType.sql_c_type_isUnsigned[c_k] == 1) or (precision > defType.sql_c_max_numlen[c_k]):
                continue

            outNum = 0
            if  num > defType.sql_c_max_min[c_k][2]:
                outNum = defType.sql_c_max_min[c_k][2]
            else:
                outNum = num

            countStr = countStr + str(count) + ','
            count = count + 1

            printToFile(
                CDataType = defType.sql_c_type[c_k],
                CDataLen = defType.sql_c_Len[c_k],
                ODBCDataType = 'SQL_NUMERIC',
                SQLDataType = 'SQL_NUMERIC',
                SQLMaxLength = 0,
                sqlValue=outNum,
                cValue=outNum,
                numeric_value=outNum,
                count=count,
                SQLOctetLength = 0 ,
                DescUnsigned=0,
                Precision = precision,
                Scale = 0
            )
    #countStr = countStr + '||'
    return count, countStr

def doNumericJobMinus(count, countStr):
    num = 0

    for i in range(18):
        num = num * 10 + 9
        precision = i + 1
        for c_k, c_v in defType.sql_c_max_min.items():
            if (defType.sql_c_type_isUnsigned[c_k] == 1) or (precision > defType.sql_c_max_numlen[c_k]):
                continue

            outNum = 0
            if num > defType.sql_c_max_min[c_k][2]:
                outNum = -(defType.sql_c_max_min[c_k][2] + 1)
            else:
                outNum = -num
            countStr = countStr + str(count) + ','
            count = count + 1
            printToFile(
                CDataType=defType.sql_c_type[c_k],
                CDataLen=defType.sql_c_Len[c_k],
                ODBCDataType='SQL_NUMERIC',
                SQLDataType='SQL_NUMERIC',
                SQLMaxLength=0,
                sqlValue=outNum,
                cValue=outNum,
                numeric_value=outNum,
                count=count,
                SQLOctetLength=0,
                DescUnsigned=0,
                Precision=precision,
                Scale=0
            )
    #countStr = countStr + '||'
    return count, countStr

def doNumericJobUnsigned(count, countStr):
    num = 0

    for i in range(18):
        num = num * 10 + 9
        precision = i + 1
        for c_k, c_v in defType.sql_c_max_min.items():
            if (defType.sql_c_type_isUnsigned[c_k] == 0) or (precision > defType.sql_c_max_numlen[c_k]):
                continue
            outNum = 0
            if num > defType.sql_c_max_min[c_k][2]:
                outNum = defType.sql_c_max_min[c_k][2]
            else:
                outNum = num

            countStr = countStr + str(count) + ','
            count = count + 1

            printToFile(
                CDataType=defType.sql_c_type[c_k],
                CDataLen=defType.sql_c_Len[c_k],
                ODBCDataType='SQL_NUMERIC',
                SQLDataType='SQL_NUMERIC',
                SQLMaxLength=0,
                sqlValue=outNum,
                cValue=outNum,
                count=count,
                SQLOctetLength=0,
                DescUnsigned=1,
                Precision=precision,
                numeric_value=outNum,
                Scale=0
            )
    #countStr = countStr + '||'
    return count, countStr

def doNumericJobScale(count, countStr):
    num = 0

    for i in range(18):
        num = num * 10 + 9
        precision = i + 1

        for scale in range(precision):
            numZore = 10 **(scale + 1)
            data = divmod(num, numZore)
            data2 = data[0] + data[1] / numZore

            nowPre = precision
            if data2 < 1:
                nowPre = nowPre + 1

            if nowPre > 15:
                continue
            countStr = countStr + str(count) + ','
            count = count + 1
            printToFile(Precision = nowPre,
                        Scale= scale + 1,
                        DescUnsigned = 0,
                        cValue = data2 ,
                        count = count,
                        CDataType= 'SQL_C_DOUBLE',
                        CDataLen= 19,
                        ODBCDataType='SQL_NUMERIC',
                        SQLOctetLength = 0,
                        sqlValue= num,
                        numeric_value= num,
                        numeric_sign = 0)
    #countStr = countStr + '||'
    return count, countStr

def doCNumericScale(count, countStr):
    num = 0
    for i in range(18):
        num = num * 10 + 9
        precision = i + 1

        for scale in range(precision):
            numZore = 10 ** (scale + 1)
            data = divmod(num, numZore)
            data2 = data[0] + data[1] / numZore

            nowPre = precision
            if data2 < 1:
                nowPre = nowPre + 1

            if nowPre > 15:
                continue
            countStr = countStr + str(count) + ','
            count = count + 1
            printToFile(Precision=nowPre,
                        Scale=scale + 1,
                        DescUnsigned=0,
                        cValue= num ,
                        count=count,
                        CDataType='SQL_C_NUMERIC',
                        CDataLen=19,
                        ODBCDataType='SQL_DOUBLE',
                        SQLOctetLength=0,
                        numeric_value=num,
                        sqlValue=data2,
                        numeric_sign=0)
    # countStr = countStr + '||'
    return count, countStr

def doCNumericJob(count, countStr):
    num = 0

    for i in range(18):
        num = num * 10 + 9
        precision = i + 1
        for sql_k, sql_v in defType.sql_type_max_min.items():
            if  (precision > defType.sql_type_len[sql_k]):
                continue

            outNum = 0
            if  num > defType.sql_type_max_min[sql_k][2]:
                outNum = defType.sql_type_max_min[sql_k][2]
            else:
                outNum = num

            countStr = countStr + str(count) + ','
            count = count + 1

            printToFile(
                CDataType = 'SQL_C_NUMERIC',
                CDataLen =  19,
                ODBCDataType = defType.sql_type[sql_k],
                SQLMaxLength = defType.sql_type_len[sql_k],
                sqlValue=outNum,
                cValue=outNum,
                count=count,
                SQLOctetLength = 0 ,
                numeric_value=outNum,
                DescUnsigned=0,
                Precision = precision,

                Scale = 0
            )
    #countStr = countStr + '||'
    return count, countStr
def doTimeStamp(count, countStr):
    for k,v in defType.sql_timestamp_exchange.items():
        Ctype = v.split(':')[0]
        SQLtype = v.split(':')[1]
        OCTtype = v.split(':')[2]
        year = 2017
        for i in range(12):
            mon = i + 1
            for j in range(4):
                timeIndex = j
                countStr = countStr + str(count) + ','
                count = count + 1
                FRAC = defType.sql_time_fac[timeIndex]
                if (Ctype == 'SQL_C_DATE' or Ctype == 'SQL_C_TIME'):
                    FRAC = "0"
                printToFile(   CDataType= Ctype,
                               SQLDataType=SQLtype,
                               ODBCDataType=SQLtype,
                               year=year,
                               mon=mon,
                               day=defType.sql_monthDay[mon],
                               hour=defType.sql_time_hour[timeIndex],
                               min=defType.sql_time_min[timeIndex],
                               second=defType.sql_time_second[timeIndex],
                               frac= FRAC,
                               CDataLen=defType.sql_time_len[Ctype],
                               SQLMaxLength=defType.sql_time_len[SQLtype],
                               SQLOctetLength=defType.sql_time_len[OCTtype],
                               count=count,
                               Precision=6
                )
    return count,countStr




def doChar(count, countStr):
    for c_k, c_v in defType.sql_c_max_min.items():
        for i in range(3):
           countStr = countStr + str(count) + ','
           count += 1

           outputData = defType.sql_c_max_min[c_k][i]
           printToFile(CDataType=defType.sql_c_type[c_k],
               CDataLen=defType.sql_c_Len[c_k],
               ODBCDataType= 'SQL_CHAR',
               SQLDataType=  'SQL_CHAR',
               SQLMaxLength= 200,
               sqlValue=outputData,
               cValue=outputData,
               count=count,
               Precision=200,
               SQLOctetLength= 201,
               DescUnsigned=0)
        pass
    return count, countStr



def doCChar(count, countStr):
    for sql_k, sql_v in defType.sql_type_max_min.items():
        for i in range(3):
           countStr = countStr + str(count) + ','
           count += 1

           outputData = defType.sql_type_max_min[sql_k][0]
           printToFile(CDataType='SQL_C_CHAR',
               CDataLen=200,
               ODBCDataType= defType.sql_type[sql_k],
               SQLDataType=  defType.sql_type[sql_k],
               SQLMaxLength= defType.sql_type_len[sql_k],
               sqlValue=outputData,
               cValue=outputData,
               count=count,
               Precision=200,
               SQLOctetLength= 201,
               DescUnsigned=0)
        pass
    return count, countStr


def doCCharUnsigned(count, countStr):
    for sql_k, sql_v in defType.sql_type_max_min_unsigned.items():
        for i in range(3):
           countStr = countStr + str(count) + ','
           count += 1

           outputData = defType.sql_type_max_min_unsigned[sql_k][0]
           printToFile(CDataType='SQL_C_CHAR',
               CDataLen=200,
               ODBCDataType= defType.sql_type[sql_k],
               SQLDataType=  defType.sql_type[sql_k],
               SQLMaxLength= defType.sql_type_len[sql_k],
               sqlValue=outputData,
               cValue=outputData,
               count=count,
               Precision=200,
               SQLOctetLength= 201,
               DescUnsigned=1)
        pass
    return count, countStr




def doWChar(count, countStr):
    for c_k, c_v in defType.sql_c_max_min.items():
        for i in range(3):
           countStr = countStr + str(count) + ','
           count += 1

           outputData = defType.sql_c_max_min[c_k][i]
           printToFile(CDataType=defType.sql_c_type[c_k],
               CDataLen=defType.sql_c_Len[c_k],
               ODBCDataType= 'SQL_WCHAR',
               SQLDataType=  'SQL_WCHAR',
               SQLCharset=11,
               SQLMaxLength= 200,
               sqlValue=outputData,
               cValue=outputData,
               count=count,
               Precision=200,
               SQLOctetLength= 201,
               DescUnsigned=0)
        pass
    return count, countStr



def doWCChar(count, countStr):
    for sql_k, sql_v in defType.sql_type_max_min.items():
        for i in range(3):
           countStr = countStr + str(count) + ','
           count += 1

           outputData = defType.sql_type_max_min[sql_k][0]
           printToFile(CDataType='SQL_C_WCHAR',
               CDataLen=200,
               ODBCDataType= defType.sql_type[sql_k],
               SQLDataType=  defType.sql_type[sql_k],
               SQLMaxLength= defType.sql_type_len[sql_k],
               sqlValue=outputData,
               cValue=outputData,
               count=count,
               Precision=200,
               SQLOctetLength= 201,
               DescUnsigned=0)
        pass
    return count, countStr


def doWCCharUnsigned(count, countStr):
    for sql_k, sql_v in defType.sql_type_max_min_unsigned.items():
        for i in range(3):
           countStr = countStr + str(count) + ','
           count += 1

           outputData = defType.sql_type_max_min_unsigned[sql_k][0]
           printToFile(CDataType='SQL_C_WCHAR',
               CDataLen=200,
               ODBCDataType= defType.sql_type[sql_k],
               SQLDataType=  defType.sql_type[sql_k],
               SQLMaxLength= defType.sql_type_len[sql_k],
               sqlValue=outputData,
               cValue=outputData,
               count=count,
               Precision=200,
               SQLOctetLength= 201,
               DescUnsigned=1)
        pass
    return count, countStr


def doNumericChar(count, countStr):
    num = 0

    for i in range(18):
        num = num * 10 + 9
        precision = i + 1
        for c_k, c_v in defType.sql_c_max_min.items():
            if (defType.sql_c_type_isUnsigned[c_k] == 1) or (precision > defType.sql_c_max_numlen[c_k]):
                continue

            outNum = 0
            if  num > defType.sql_c_max_min[c_k][2]:
                outNum = defType.sql_c_max_min[c_k][2]
            else:
                outNum = num

            countStr = countStr + str(count) + ','
            count = count + 1

            printToFile(
                CDataType = 'SQL_C_CHAR',
                CDataLen =  200,
                ODBCDataType = 'SQL_NUMERIC',
                SQLDataType = 'SQL_NUMERIC',
                SQLMaxLength = 0,
                sqlValue=outNum,
                cValue=outNum,
                numeric_value=outNum,
                count=count,
                SQLOctetLength = 0 ,
                DescUnsigned=0,
                Precision = precision,
                Scale = 0
            )
    #countStr = countStr + '||'
    return count, countStr



def doCharCNumericJob(count, countStr):
    num = 0

    for i in range(18):
        num = num * 10 + 9
        precision = i + 1
        for sql_k, sql_v in defType.sql_type_max_min.items():
            if  (precision > defType.sql_type_len[sql_k]):
                continue

            outNum = 0
            if  num > defType.sql_type_max_min[sql_k][2]:
                outNum = defType.sql_type_max_min[sql_k][2]
            else:
                outNum = num

            countStr = countStr + str(count) + ','
            count = count + 1

            printToFile(
                CDataType = 'SQL_C_NUMERIC',
                CDataLen =  19,
                ODBCDataType = 'SQL_CHAR',
                SQLMaxLength =  'SQL_CHAR',
                sqlValue=outNum,
                cValue=outNum,
                count=count,
                SQLOctetLength = 0 ,
                numeric_value=outNum,
                DescUnsigned=0,
                Precision = precision,

                Scale = 0
            )
    #countStr = countStr + '||'
    return count, countStr


def doTimeStampChar(count, countStr):
    for k,v in defType.sql_timestamp_exchange.items():
        Ctype = v.split(':')[0]
        SQLtype = v.split(':')[1]
        OCTtype = v.split(':')[2]
        year = 2017
        for i in range(12):
            mon = i + 1
            for j in range(4):
                timeIndex = j
                countStr = countStr + str(count) + ','
                count = count + 1
                FRAC = defType.sql_time_fac[timeIndex]
                if (Ctype == 'SQL_C_DATE' or Ctype == 'SQL_C_TIME'):
                    FRAC = "0"
                printToFile(   CDataType= Ctype,
                               SQLDataType=SQLtype,
                               ODBCDataType=SQLtype,
                               year=year,
                               mon=mon,
                               day=defType.sql_monthDay[mon],
                               hour=defType.sql_time_hour[timeIndex],
                               min=defType.sql_time_min[timeIndex],
                               second=defType.sql_time_second[timeIndex],
                               frac= FRAC,
                               CDataLen=defType.sql_time_len[Ctype],
                               SQLMaxLength=defType.sql_time_len[SQLtype],
                               SQLOctetLength=defType.sql_time_len[OCTtype],
                               count=count
                )
    return count,countStr
