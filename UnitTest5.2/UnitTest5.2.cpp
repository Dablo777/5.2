#include "pch.h"
#include "CppUnitTest.h"
#include "../lab5.2/lab5.2.cpp"  // ���� �� ������ ��������� �����

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab5_2
{
    TEST_CLASS(UnitTestLab5_2)
    {
    public:
        // ���� ��� ������� A() � ����������� ���������� x � n
        TEST_METHOD(TestMethodA_Positive)
        {
            double result = A(2.0, 3);  // ���������� � x = 2, n = 3
            Assert::AreEqual(result, 0, 0.00001, L"������� � ������� A() ��� ���������� ��������� x � n.");
        }

        // ���� ��� ������� A() � ������ ���������� x
        TEST_METHOD(TestMethodA_SmallX)
        {
            double result = A(0.01, 2);  // ���������� � x = 0.01, n = 2
            Assert::AreEqual(result, 0, 0.00001, L"������� � ������� A() ��� ����� ��������� x.");
        }

        // ���� ��� ������� S() � ������ ���������� eps
        TEST_METHOD(TestMethodS_SmallEps)
        {
            double s;
            int n;
            double result = S(2.0, 1.0e-5, n, s);  // ���������� � x = 2, eps = 1e-5
            Assert::AreEqual(s, 4, 0.00001, L"������� � ������� S() ��� ����� eps.");
            Assert::AreEqual(n, 5, L"������ ����� �������� ��� S() ��� ����� eps.");
        }

        // ���� ��� ������� S() � ������� ��������� x
        TEST_METHOD(TestMethodS_LargeX)
        {
            double s;
            int n;
            double result = S(10.0, 1.0e-5, n, s);  // ���������� � x = 10, eps = 1e-5
            Assert::AreEqual(s, 20, 0.00001, L"������� � ������� S() ��� �������� ������� x.");
            Assert::AreEqual(n, 5, L"������ ����� �������� ��� S() ��� �������� ������� x.");
        }

        // ���� ��� ������� S() � ���� ����� eps
        TEST_METHOD(TestMethodS_TinyEps)
        {
            double s;
            int n;
            double result = S(2.0, 1.0e-10, n, s);  // ���������� � x = 2, eps = 1e-10
            Assert::AreEqual(s, 4, 0.00001, L"������� � ������� S() ��� ���� ������ eps.");
            Assert::AreEqual(n, 5, L"������ ����� �������� ��� S() ��� ���� ������ eps.");
        }
    };
}
