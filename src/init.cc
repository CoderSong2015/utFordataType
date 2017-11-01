
#include "init.h"



void initDesc(CDescRec *cdr, TESTDATA_TABLE  map){
    cdr->m_ODBCDataType     = map.m_ODBCDataType     ;                        
    cdr->m_SQLDataType      = map.m_SQLDataType      ;                        
    cdr->m_SQLMaxLength     = map.m_SQLMaxLength     ;                         
    cdr->m_SQLUnsigned      = map.m_DescUnsigned      ;

    cdr->m_DescUnsigned     = map.m_DescUnsigned     ;                         
    cdr->m_SQLCharset       = map.m_SQLCharset       ;                       
    cdr->m_SQLDatetimeCode  = map.m_SQLDatetimeCode  ;                 
    cdr->m_SQLOctetLength   = map.m_SQLOctetLength   ;    
    cdr->m_ODBCPrecision    = map.Precision;
    cdr->m_ODBCScale        = map.Scale;
}


