#ifndef __TEMPLATE__
#define __TEMPLATE__

#include "cdesc.h"
#include "gtest/gtest.h"
#include <iostream>
#include <sstream> 
#include "sqltocconv.h"
using namespace std;
template <class T>  
T stringToNum(const string&str)  
{  
    istringstream iss(str);  
    T num;  
    iss >> num;  
    return num;  
}

#endif
