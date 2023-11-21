#include "pch.h"
#include "CppUnitTest.h"
#include"..\\lab6.1.rec\lab.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourTests
{
    TEST_CLASS(YourTestClass)
    {
    public:

        TEST_METHOD(TestPositiveSumLessThan575)
        {
            const int size = 23;
            int r[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };

            
            int positiveCount = 0;
            int positiveSum = 0; 

            
            computePositiveSumAndCount(r, size, positiveCount, positiveSum);

            
            Assert::IsTrue(positiveSum < 575);
        }
    };
}