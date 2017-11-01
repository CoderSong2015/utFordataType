import sys

class defType:
    SQL_BIGINT			=	(-5)
    SQL_TINYINT			=	(-6)
    SQL_BIT				=	(-7)
    SQL_UNKNOWN_TYPE    =	0
    SQL_CHAR		    =	1
    SQL_NUMERIC		    =	2
    SQL_DECIMAL		    =	3
    SQL_INTEGER		    =	4
    SQL_SMALLINT	    =	5
    SQL_FLOAT		    =	6
    SQL_REAL		    =	7
    SQL_DOUBLE		    =	8
    SQL_DATETIME		=	9
    SQL_VARCHAR			=	12

    SQL_DATE            = 9
    SQL_TIME            = 10
    SQL_TIMESTAMP       = 11
    SQL_BINARY          = -2
    SQL_SIGNED_OFFSET   = -20
    SQL_UNSIGNED_OFFSET = -22

    sql_type = {
        SQL_BIGINT			:	'SQL_BIGINT'            ,
        SQL_TINYINT			:	'SQL_TINYINT'           ,
        #SQL_BIT				:	'SQL_BIT'               ,
        SQL_UNKNOWN_TYPE    :	'SQL_UNKNOWN_TYPE'      ,
        #SQL_CHAR		    :	'SQL_CHAR'              ,
        #SQL_NUMERIC		    :	'SQL_NUMERIC'           ,
        #SQL_DECIMAL		    :	'SQL_DECIMAL'           ,
        SQL_INTEGER		    :	'SQL_INTEGER'           ,
        SQL_SMALLINT	    :	'SQL_SMALLINT'          ,
        #SQL_FLOAT		    :	'SQL_FLOAT'             ,
        SQL_REAL		    :	'SQL_REAL'              ,
        SQL_DOUBLE		    :	'SQL_DOUBLE'            ,
        #SQL_DATETIME		:	'SQL_DATETIME'          ,
        #SQL_VARCHAR			:	'SQL_VARCHAR'
    }
    sql_isunsigned = {
        SQL_BIGINT	        : 0,
        SQL_TINYINT		    : 0,
        #SQL_BIT			    : 0,
        SQL_UNKNOWN_TYPE    : 0,
        #SQL_CHAR		    : 0,
        # SQL_NUMERIC		    :	'SQL_NUMERIC'           ,
        # SQL_DECIMAL		    :	'SQL_DECIMAL'           ,
        SQL_INTEGER		    : 0,
        SQL_SMALLINT	    : 0,
        #SQL_FLOAT		    : 0,
        SQL_REAL		    : 0,
        SQL_DOUBLE		    : 0,
        # SQL_DATETIME		:	'SQL_DATETIME'          ,
        # SQL_VARCHAR			:	'SQL_VARCHAR'
    }
    sql_type_max_min = {
        SQL_BIGINT			:   [-2**63, 0, 2**63 -1],
        SQL_TINYINT			:	[-127, 0, 127],
        #SQL_BIT				:	[0, 0, 1],
        #SQL_CHAR		    :	[-127, 0, 127],
        #SQL_NUMERIC		    :	[],
        #SQL_DECIMAL		    :	[],
        SQL_INTEGER		    :	[-2147483648, 0, 2147483647],
        SQL_SMALLINT	    :	[-32768, 0,32767],
        #SQL_FLOAT		    :	[-1.7976931348623157e+308, 0, 1.7976931348623157e+308],
        SQL_REAL		    :	[-1.17549435e-38, 0, 1.17549435e+38],
        SQL_DOUBLE		    :	[-1.7976931348623157e+308, 0, 1.7976931348623157e+308],
        #SQL_DATETIME		:	[],
        #SQL_VARCHAR			:	[]
    }

    sql_type_max_min_unsigned= {
        SQL_BIGINT		 :  [0, 2 **64 -1 ],
        SQL_TINYINT		 :	[0, 255],
        #SQL_BIT			 :	[0, 1],
        # SQL_CHAR		    :	[-127, 0, 127],
        # SQL_NUMERIC		    :	[],
        # SQL_DECIMAL		    :	[],
        SQL_INTEGER		 :	[0, 4294967295],
        SQL_SMALLINT	 :	[0, 65535],
        # SQL_DATETIME		:	[],
        # SQL_VARCHAR			:	[]
    }
    SQL_C_CHAR   		=		SQL_CHAR
    SQL_C_LONG   		=		SQL_INTEGER
    SQL_C_SHORT  		=		SQL_SMALLINT
    SQL_C_FLOAT  		=		SQL_REAL
    SQL_C_DOUBLE 		=		SQL_DOUBLE

    SQL_C_NUMERIC		=		SQL_NUMERIC
    SQL_C_DEFAULT		=		99


    SQL_C_DATE			=	SQL_DATE
    SQL_C_TIME			=	SQL_TIME
    SQL_C_TIMESTAMP	    =			SQL_TIMESTAMP
    SQL_C_BINARY		=		SQL_BINARY
    SQL_C_BIT			=	SQL_BIT
    SQL_C_TINYINT		=		SQL_TINYINT
    SQL_C_SLONG		    =		(SQL_C_LONG+SQL_SIGNED_OFFSET)
    SQL_C_SSHORT		=		(SQL_C_SHORT+SQL_SIGNED_OFFSET)
    SQL_C_STINYINT		=		(SQL_TINYINT+SQL_SIGNED_OFFSET)
    SQL_C_ULONG		    =		(SQL_C_LONG+SQL_UNSIGNED_OFFSET)
    SQL_C_USHORT		=		(SQL_C_SHORT+SQL_UNSIGNED_OFFSET)
    SQL_C_UTINYINT		=		(SQL_TINYINT+SQL_UNSIGNED_OFFSET)
    SQL_C_SBIGINT       =       (SQL_BIGINT+SQL_SIGNED_OFFSET)
    SQL_C_UBIGINT       =       (SQL_BIGINT+SQL_UNSIGNED_OFFSET)

    sql_c_type = {
        #SQL_C_CHAR   		:	'SQL_C_CHAR   '   ,
        SQL_C_LONG   		:	'SQL_C_LONG   '   ,
        SQL_C_SHORT  		:	'SQL_C_SHORT  '   ,
        SQL_C_FLOAT  		:	'SQL_C_FLOAT  '   ,
        SQL_C_DOUBLE 		:	'SQL_C_DOUBLE '   ,
        SQL_C_BIT			:	'SQL_C_BIT	'     ,
        SQL_C_TINYINT		:	'SQL_C_TINYINT'   ,
        SQL_C_SLONG		    :	'SQL_C_SLONG	' ,
        SQL_C_SSHORT		:	'SQL_C_SSHORT'    ,
        SQL_C_STINYINT		:	'SQL_C_STINYINT'  ,
        SQL_C_ULONG		    :	'SQL_C_ULONG	' ,
        SQL_C_USHORT		:	'SQL_C_USHORT'    ,
        SQL_C_UTINYINT		:	'SQL_C_UTINYINT'  ,
        SQL_C_SBIGINT       :   'SQL_C_SBIGINT'   ,
        SQL_C_UBIGINT       :   'SQL_C_UBIGINT'   ,
    }

    sql_c_type_isUnsigned = {
        SQL_C_LONG   	    :0 ,
        SQL_C_SHORT  		:0 ,
        SQL_C_FLOAT  		:0 ,
        SQL_C_DOUBLE 		:0 ,
        SQL_C_BIT			:0 ,
        SQL_C_TINYINT		:0 ,
        SQL_C_SLONG		    :0 ,
        SQL_C_SSHORT		:0 ,
        SQL_C_STINYINT		:0 ,
        SQL_C_ULONG		    :1 ,
        SQL_C_USHORT		:1,
        SQL_C_UTINYINT		:1,
        SQL_C_SBIGINT       :0 ,
        SQL_C_UBIGINT       :1 ,
    }
    sql_c_max_min = {
        #SQL_C_CHAR   		:	[-127, 0, 127],
        SQL_C_LONG   		:	[-2147483648, 0, 2147483647],
        SQL_C_SHORT  		:	[-32768, 0,32767],
        SQL_C_FLOAT  		:	[-3.40E+38, 0, 3.40E+38],
        SQL_C_DOUBLE 		:	[-1.7976931348623157e+308, 0, 1.7976931348623157e+308],
        SQL_C_BIT			:	[0, 0, 1],
        SQL_C_TINYINT		:	[-127, 0, 127],
        SQL_C_SLONG		    :	[-2147483648, 0, 2147483647],
        SQL_C_SSHORT		:	[-32768, 0,32767],
        SQL_C_STINYINT		:	[-127, 0, 127],
        SQL_C_ULONG		    :	[0, 0, 4294967295],
        SQL_C_USHORT		:	[0, 0, 65535],
        SQL_C_UTINYINT		:	[0, 0, 255],
        SQL_C_SBIGINT       :   [-2**63, 0, 2**63 -1],
        SQL_C_UBIGINT       :   [0, 0, 2**64 -1],
    }

    sql_c_Len = {
        #SQL_C_CHAR   	    :	1,
        SQL_C_LONG   		:	4,
        SQL_C_SHORT  		:	2,
        SQL_C_FLOAT  		:	8,
        SQL_C_DOUBLE 		:	8,
        SQL_C_BIT			:	1,
        SQL_C_TINYINT	    :	1,
        SQL_C_SLONG		    :	4,
        SQL_C_SSHORT		:	2,
        SQL_C_STINYINT		:	1,
        SQL_C_ULONG		    :	4,
        SQL_C_USHORT		:	2,
        SQL_C_UTINYINT		:	1,
        SQL_C_SBIGINT       :   8,
        SQL_C_UBIGINT       :   8,

    }
    sql_type_len = {
        SQL_BIGINT	     :	8              ,
        SQL_TINYINT		 :	1              ,
        #SQL_BIT			 :	1              ,
        SQL_UNKNOWN_TYPE :	0              ,
        # SQL_CHAR		    :	'SQL_CHAR'              ,
        # SQL_NUMERIC		    :	'SQL_NUMERIC'           ,
        # SQL_DECIMAL		    :	'SQL_DECIMAL'           ,
        SQL_INTEGER		    : 4           ,
        SQL_SMALLINT	    : 2           ,
        #SQL_FLOAT		    : 4           ,
        SQL_REAL		    : 4           ,
        SQL_DOUBLE		    : 8           ,
        #SQL_DATETIME		:	'SQL_DATETIME'          ,
        # SQL_VARCHAR			:	'SQL_VARCHAR'
    }
    sql_type_Datatype = {
        SQL_BIGINT	     :	'SQLTYPECODE_LARGEINT'              ,
        SQL_TINYINT		 :	'SQLTYPECODE_TINYINT'              ,
        #SQL_BIT			 :	'SQLTYPECODE_BPINT_UNSIGNED'              ,
        SQL_UNKNOWN_TYPE :	'0'              ,
        # SQL_CHAR		    :	'SQL_CHAR'              ,
        # SQL_NUMERIC		    :	'SQL_NUMERIC'           ,
        # SQL_DECIMAL		    :	'SQL_DECIMAL'           ,
        SQL_INTEGER		    : 'SQLTYPECODE_INTEGER'           ,
        SQL_SMALLINT	    : 'SQLTYPECODE_SMALLINT'           ,
        #SQL_FLOAT		    : 'SQLTYPECODE_IEEE_FLOAT'           ,
        SQL_REAL		    : 'SQLTYPECODE_IEEE_REAL'           ,
        SQL_DOUBLE		    : 'SQLTYPECODE_IEEE_DOUBLE',
        #SQL_DATETIME		:	'SQL_DATETIME'          ,
        # SQL_VARCHAR			:	'SQL_VARCHAR'
    }

    sql_c_max_numlen = {
        SQL_C_LONG   	    :	10,
        SQL_C_SHORT  		:	5,
        SQL_C_FLOAT  		:	0,
        SQL_C_DOUBLE 		:	0,
        SQL_C_BIT			:	1,
        SQL_C_TINYINT	    :	3,
        SQL_C_SLONG		    :	10,
        SQL_C_SSHORT		:	5,
        SQL_C_STINYINT		:	3,
        SQL_C_ULONG		    :	10,
        SQL_C_USHORT		:	5,
        SQL_C_UTINYINT		:	3,
        SQL_C_SBIGINT       :   18,
        SQL_C_UBIGINT       :   20,

    }

    SQL_JAN = 1
    SQL_FEB = 2
    SQL_MAR = 3
    SQL_APR = 4
    SQL_MAY = 5
    SQL_JUN = 6
    SQL_JLY = 7
    SQL_AUG = 8
    SQL_SEP = 9
    SQL_OCT = 10
    SQL_NOV = 11
    SQL_DEC = 12

    sql_monthDay = {
        SQL_JAN : 31,
        SQL_FEB : 28,
        SQL_MAR : 31,
        SQL_APR : 30,
        SQL_MAY : 31,
        SQL_JUN : 30,
        SQL_JLY : 31,
        SQL_AUG : 31,
        SQL_SEP : 30,
        SQL_OCT : 31,
        SQL_NOV : 30,
        SQL_DEC : 31,
    }

    sql_timestamp_exchange = {
        1:'SQL_C_DATE:SQL_DATE:OCT_DATE',
        2:'SQL_C_DATE:SQL_TIMESTAMP:OCT_TIMESTAMP',
        3:'SQL_C_TIME:SQL_TIME:OCT_TIME',
        4:'SQL_C_TIME:SQL_TIMESTAMP:OCT_TIMESTAMP',
        5:'SQL_C_TIMESTAMP:SQL_DATE:OCT_DATE',
        6:'SQL_C_TIMESTAMP:SQL_TIME:OCT_TIME',
        7:'SQL_C_TIMESTAMP:SQL_TIMESTAMP:OCT_TIMESTAMP'
    }
    sql_time_len = {
        'SQL_C_DATE' : 6,
        'SQL_C_TIME' : 6,
        'SQL_C_TIMESTAMP' : 16,
        'SQL_DATE'   :4,
        'SQL_TIME'   :7,
        'SQL_TIMESTAMP' :11,
        'OCT_DATE'      :10,
        'OCT_TIME'      :8,
        'OCT_TIMESTAMP' :26,
    }
    sql_time_hour =   ['0', '12', '18','23']
    sql_time_min =    ['0', '30', '45','59']
    sql_time_second = ['0', '30', '45','59']
    sql_time_fac =    ['123456000', '234567000' , '345678000' ,'999999000' ]