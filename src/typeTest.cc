// Copyright 2005, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A sample program demonstrating using Google C++ testing framework.
//
// Author: wan@google.com (Zhanyong Wan)


// This sample shows how to write a simple unit test for a function,
// using Google C++ testing framework.
//
// Writing a unit test using Google C++ testing framework is easy as 1-2-3:


// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include "sqltocconv.h"
#include "cdesc.h"
#include "gtest/gtest.h"
#include "commonFunction.h"
namespace {

class Num : public testing::TestWithParam<int>{  
  protected:  
  virtual void SetUp() {  
      
      tmpDesc = new CDescRec();
  }

  CDescRec * tmpDesc;  
};  
/*
TEST_F(NumberToNumberTest, Target) {
  convSQLNumberToNumber(&src, tmpDesc, SQL_TINYINT, &target, size, SQL_C_LONG);
  EXPECT_EQ(127, target);  
  EXPECT_EQ(3, size);  
  EXPECT_EQ(4, size);
  
  EXPECT_EQ(3, size);  
}  
  
TEST_F(NumberToNumberTest, Size) {  
  convSQLNumberToNumber(&src, tmpDesc, SQL_TINYINT, &target, size, SQL_C_LONG);
  EXPECT_EQ(4, size);  
}  
*/
TEST_P(Num, Testmultiple){
    int n = GetParam();
   
    callSub(n, tmpDesc);
    
}

int NumberToNumberCaseNumber[] = {
0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287};
INSTANTIATE_TEST_CASE_P(MyPrimeParamTest,
    Num,
    ::testing::ValuesIn(NumberToNumberCaseNumber)); //::testing::Values for input directly
/*
TEST_P(Num, Toooo){
    int n = GetParam();
    EXPECT_EQ(SQL_TINYINT,n);
}

int TestCaseNumber[] = {0, 1};
INSTANTIATE_TEST_CASE_P(Test,
    Num,
    ::testing::ValuesIn(TestCaseNumber)); //::testing::Values for input directly

*/

}  // namespace

