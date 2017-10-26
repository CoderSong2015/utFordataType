
#include "init.h"



void initDesc(CDescRec *cdr, TESTDATA_TABLE  map){
    cdr->m_ODBCDataType                 = map.m_ODBCDataType; //1
    cdr->m_SQLDatetimeCode              = map.m_SQLDatetimeCode; //2
    cdr->m_DescPrecision                = map.m_DescPrecision; //3
    cdr->m_DescScale                    = map.m_DescScale; //4
    cdr->m_DescUnsigned                 = map.m_DescUnsigned; //5
    cdr->m_SQLCharset                   = map.m_SQLCharset; //6
    cdr->m_SQLMaxLength                 = map.m_SQLMaxLength; //7

    cdr->m_SQLDataType                  = map.m_SQLDataType;
    cdr->m_SQLOctetLength               = map.m_SQLOctetLength;
    cdr->m_ODBCPrecision                = map.m_ODBCPrecision;
    cdr->m_ODBCScale                    = map.m_ODBCScale;
    cdr->m_SQLUnsigned                  = map.m_SQLUnsigned;

}


