from preDefine import defType
from createTestData import functionList,functionListForUnsign
from createTestData import return0
from printTofile import printToFile,printNumeric,printNumericTest
from printTofile import printTimeStamp
def doSignedJob(count, countStr):
    for sql_k, sql_v in defType.sql_type_max_min.items():
        for c_k, c_v in defType.sql_c_max_min.items():
            for i in range(3):
                countStr = countStr + str(count) + ','
                count += 1
                outputData = functionList.get(i, return0)(sql_v[i], c_v[i])
                printToFile(c_k, sql_k, outputData, count, 0)
    #countStr = countStr + '||'
    return count, countStr

def doUnsignedJob(count, countStr):
    for sql_k, sql_v in defType.sql_type_max_min_unsigned.items():
        for c_k, c_v in defType.sql_c_max_min.items():
            for i in range(2):
                countStr = countStr + str(count) + ','
                count += 1
                outputData = functionListForUnsign.get(i, return0)(sql_v[i], c_v[i + 1])
                printToFile(c_k, sql_k, outputData, count, 1)
    return count, countStr


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

def doNumericJob(count, countStr):
    num = 0

    for i in range(18):
        num = num * 10 + 9
        precision = i + 1
        for c_k, c_v in defType.sql_c_max_min.items():
            if (defType.sql_c_type_isUnsigned[c_k] == 1) or (precision > defType.sql_c_max_numlen[c_k]):
                continue
            if  num > defType.sql_c_max_min[c_k][2]:
                countStr = countStr + str(count) + ','
                count = count + 1

                printNumeric(precision, 0, 0, defType.sql_c_max_min[c_k][2], count, c_k, defType.sql_c_max_min[c_k][2])
            else:
                countStr = countStr + str(count) + ','
                count = count + 1
                printNumeric(precision, 0, 0, num, count, c_k, num)
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
            if num > defType.sql_c_max_min[c_k][2]:
                countStr = countStr + str(count) + ','
                count = count + 1
                printNumeric(precision, 0, 0, -(defType.sql_c_max_min[c_k][2] + 1), count, c_k, -(defType.sql_c_max_min[c_k][2] + 1))
            else:
                countStr = countStr + str(count) + ','
                count = count + 1
                printNumeric(precision, 0, 0, -num, count, c_k, -num)
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
            if num > defType.sql_c_max_min[c_k][2]:
                countStr = countStr + str(count) + ','
                count = count + 1
                printNumeric(precision, 0, 0, defType.sql_c_max_min[c_k][2], count, c_k, defType.sql_c_max_min[c_k][2])
            else:
                countStr = countStr + str(count) + ','
                count = count + 1
                printNumeric(precision, 0, 1, num, count, c_k, num)
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
            printNumeric(nowPre, scale + 1, 0, data2 , count, defType.SQL_C_DOUBLE, num)
    #countStr = countStr + '||'
    return count, countStr

def doTimeStamp(count, countStr):
    for k,v in defType.sql_timestamp_exchange.items():
        Ctype = v.split(':')[0]
        SQLtype = v.split(':')[1]
        year = 2017
        for i in range(12):
            mon = i + 1
            for j in range(4):
                timeIndex = j
                countStr = countStr + str(count) + ','
                count = count + 1
                printTimeStamp(Ctype,
                               SQLtype,
                               year,
                               mon,
                               defType.sql_monthDay[mon],
                               defType.sql_time_hour[timeIndex],
                               defType.sql_time_min[timeIndex],
                               defType.sql_time_second[timeIndex],
                               defType.sql_time_fac[timeIndex],
                               defType.sql_time_len[Ctype],
                               defType.sql_time_len[SQLtype],
                               count)
    return count,countStr