#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab5_r\lab5_r.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(calculate_Tests)
	{
	public:
		TEST_METHOD(calculateYPositiveX_3)
		{
			double x = 3;
			double n = 4;

			double actual = calculateYPositiveX(x, n);
			double expected = 5.5;

			Assert::AreEqual(expected, actual);
		}

	public:
		TEST_METHOD(calculateYNegativeX__3)
		{
			double x = -3;
			double n = 4;

			double actual = calculateYNegativeX(x, n);
			double expected = -30;

			Assert::AreEqual(expected, actual);
		}
	};

	TEST_CLASS(valid_Tests)
	{
	public:
		TEST_METHOD(valid_inputN_getN10_exeptionNotThrown)
		{
			int n = 10;
			try
			{
				checkValidN(n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}

	public:
		TEST_METHOD(valid_inputN_getN10_exeptionThrown)
		{
			int n = 2;
			try
			{
				checkValidN(n);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};
}
