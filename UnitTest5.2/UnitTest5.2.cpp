#include "pch.h"
#include "CppUnitTest.h"
#include "../lab5.2/lab5.2.cpp"  // Путь до вашего основного файла

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab5_2
{
    TEST_CLASS(UnitTestLab5_2)
    {
    public:
        // Тест для функції A() з позитивними значеннями x і n
        TEST_METHOD(TestMethodA_Positive)
        {
            double result = A(2.0, 3);  // тестування з x = 2, n = 3
            Assert::AreEqual(result, 0, 0.00001, L"Помилка в функції A() при позитивних значеннях x і n.");
        }

        // Тест для функції A() з малими значеннями x
        TEST_METHOD(TestMethodA_SmallX)
        {
            double result = A(0.01, 2);  // тестування з x = 0.01, n = 2
            Assert::AreEqual(result, 0, 0.00001, L"Помилка в функції A() при малих значеннях x.");
        }

        // Тест для функції S() з малими значеннями eps
        TEST_METHOD(TestMethodS_SmallEps)
        {
            double s;
            int n;
            double result = S(2.0, 1.0e-5, n, s);  // тестування з x = 2, eps = 1e-5
            Assert::AreEqual(s, 4, 0.00001, L"Помилка в функції S() при малих eps.");
            Assert::AreEqual(n, 5, L"Невірне число ітерацій для S() при малих eps.");
        }

        // Тест для функції S() з великим значенням x
        TEST_METHOD(TestMethodS_LargeX)
        {
            double s;
            int n;
            double result = S(10.0, 1.0e-5, n, s);  // тестування з x = 10, eps = 1e-5
            Assert::AreEqual(s, 20, 0.00001, L"Помилка в функції S() при великому значенні x.");
            Assert::AreEqual(n, 5, L"Невірне число ітерацій для S() при великому значенні x.");
        }

        // Тест для функції S() з дуже малим eps
        TEST_METHOD(TestMethodS_TinyEps)
        {
            double s;
            int n;
            double result = S(2.0, 1.0e-10, n, s);  // тестування з x = 2, eps = 1e-10
            Assert::AreEqual(s, 4, 0.00001, L"Помилка в функції S() при дуже малому eps.");
            Assert::AreEqual(n, 5, L"Невірне число ітерацій для S() при дуже малому eps.");
        }
    };
}
