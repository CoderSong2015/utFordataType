from preDefine import defType
from createTestData import functionList,functionListForUnsign
from createTestData import return0
from printTofile import printToFile,printNumeric,printNumericTest

def doSignedJob(count):
    for sql_k, sql_v in defType.sql_type_max_min.items():
        for c_k, c_v in defType.sql_c_max_min.items():
            for i in range(3):
                print(count, end=',')
                count += 1
                outputData = functionList.get(i, return0)(sql_v[i], c_v[i])
                printToFile(c_k, sql_k, outputData, count, 0)
    return count

def doUnsignedJob(count):
    for sql_k, sql_v in defType.sql_type_max_min_unsigned.items():
        for c_k, c_v in defType.sql_c_max_min.items():
            for i in range(2):
                print(count, end=',')
                count += 1
                outputData = functionListForUnsign.get(i, return0)(sql_v[i], c_v[i + 1])
                printToFile(c_k, sql_k, outputData, count, 1)
    return count


def doNumericJobTest(count):
    num = 0
    for i in range(18):
        num = num * 10 + 9
        precision = i + 1

        count += 1
        print(count, end=',')
        printNumericTest(precision, 0, 0, num, count)
    return count

def doNumericJob(count):
    num = 0

    for i in range(18):
        num = num * 10 + 9
        precision = i + 1
        for c_k, c_v in defType.sql_c_max_min.items():
            if (defType.sql_c_type_isUnsigned[c_k] == 1) or (precision > defType.sql_c_max_numlen[c_k]):
                continue
            if  num > defType.sql_c_max_min[c_k][2]:
                printNumeric(precision, 0, 0, defType.sql_c_max_min[c_k][2], count, c_k, num)
            else:
                printNumeric(precision, 0, 0, num, count, c_k, num)

            count = count + 1
            print(count, end=',')
    return count

def doNumericJobMinus(count):
    num = 0

    for i in range(18):
        num = num * 10 + 9
        precision = i + 1
        for c_k, c_v in defType.sql_c_max_min.items():
            if (defType.sql_c_type_isUnsigned[c_k] == 1) or (precision > defType.sql_c_max_numlen[c_k]):
                continue
            if num > defType.sql_c_max_min[c_k][2]:
                printNumeric(precision, 0, 0, -(defType.sql_c_max_min[c_k][2] + 1), count, c_k, num)
            else:
                printNumeric(precision, 0, 0, -num, count, c_k, num)
            count = count + 1
            print(count, end=',')
    return count
def doNumericJobUnsigned(count):
    num = 0

    for i in range(18):
        num = num * 10 + 9
        precision = i + 1
        for c_k, c_v in defType.sql_c_max_min.items():
            if (defType.sql_c_type_isUnsigned[c_k] == 0) or (precision > defType.sql_c_max_numlen[c_k]):
                continue
            if num > defType.sql_c_max_min[c_k][2]:
                printNumeric(precision, 0, 0, defType.sql_c_max_min[c_k][2], count, c_k, num)
            else:
                printNumeric(precision, 0, 1, num, count, c_k, num)
            count = count + 1
            print(count, end=',')
    return count

def doNumericJobScale(count):
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
            printNumeric(nowPre, scale + 1, 0, data2 , count, defType.SQL_C_DOUBLE, num)
            count = count + 1
            print(count, end=',')
    return count

def doTimeStamp(count):
    pass