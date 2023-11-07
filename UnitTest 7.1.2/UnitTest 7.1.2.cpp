#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.1.2/Lab 7.1.2.cpp"
#include <stdio.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourProjectTests
{
    TEST_CLASS(MatrixFunctionsTest)
    {
    public:
        TEST_METHOD(TestSortMatrix)
        {
            int matrix[8][5] = { { 10, 25, 8, 16, 32 },
                                { 42, 19, 33, 7, 27 },
                                { 11, 31, 20, 15, 29 },
                                { 30, 13, 14, 12, 48 },
                                { 44, 23, 36, 28, 50 },
                                { 17, 46, 35, 49, 38 },
                                { 21, 37, 22, 9, 46 },
                                { 34, 50, 41, 39, 18 }, };

            int* matrixPtr[8];
            for (int i = 0; i < 8; ++i) {
                matrixPtr[i] = matrix[i];
            }

            int sortingKeys[] = { 1, -1, -1 };
            SortMatrix(matrixPtr, 8, 5, sortingKeys, 0, 0);

            int expected[8][5] = { { 10, 25, 8, 16, 32 },
                                { 11, 31, 20, 15, 29 },
                                { 17, 46, 35, 49, 38 },
                                { 21, 37, 22, 9, 46 },
                                { 30, 13, 14, 12, 48 },
                                { 34, 50, 41, 39, 18 },
                                { 42, 19, 33, 7, 27 },
                                { 44, 23, 36, 28, 50 }, };

            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 5; ++j) {
                    Assert::AreEqual(matrix[i][j], expected[i][j]);
                }
            }
        }

        TEST_METHOD(TestCalculateAndReplace)
        {
            int matrix[8][5] = { { 20, 12, 35, 7, 8 },
                                { 18, 29, 41, 33, 9 },
                                { 16, 11, 25, 14, 27 },
                                { 47, 6, 28, 19, 22 },
                                { 13, 38, 30, 42, 37 },
                                { 15, 31, 16, 10, 50 },
                                { 49, 46, 17, 50, 24 },
                                { 36, 34, 42, 25, 21 }, };

            int* matrixPtr[8];
            for (int i = 0; i < 8; ++i) {
                matrixPtr[i] = matrix[i];
            }

            int sum = 0;
            int count = 0;
            CalculateAndReplace(matrixPtr, 8, 5, sum, count, 0, 0);

            int expected[8][5] = { { 0, 12, 0, 0, 8 },
                                   { 18, 0, 0, 0, 0 },
                                   { 16, 0, 0, 14, 0 },
                                   { 0, 6, 28, 0, 22 },
                                   { 0, 38, 30, 42, 0 },
                                   { 0, 0, 16, 10, 50 },
                                   { 0, 46, 0, 0, 24 },
                                   { 36, 34, 42, 0, 0 } };

            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 5; ++j) {
                    Assert::AreEqual(matrix[i][j], expected[i][j]);
                }
            }

            Assert::AreEqual(sum, 561);
            Assert::AreEqual(count, 21);
        }
    };
}
