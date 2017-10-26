#ifndef __COMMONFUNCTION_L__
#define __COMMONFUNCTION_L__

#include "cdesc.h"
#include "gtest/gtest.h"
#include <iostream>
#include <sstream> 
#include "sqltocconv.h"
#include "template.h"
using namespace std;

void callSubCtosql(int , CDescRec* );
void commonSwitchctosql(int, SQLPOINTER, int );
#endif
