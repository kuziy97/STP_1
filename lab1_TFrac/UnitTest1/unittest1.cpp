#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Проект9/Header.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Drobi a(-4, 7), b(1, 8);
			string str="-25/56";
			Drobi c = a + b;
			Assert::AreEqual(str,c.GetFractString());
		}

		TEST_METHOD(TestMethod2)
		{
			Drobi a(-4, 7), b(1, 8);
			string str = "-39/56";
			Drobi c = a - b;
			Assert::AreEqual(str, c.GetFractString());
		}

		TEST_METHOD(TestMethod3)
		{
			Drobi a(-4, 7), b(1, 8);
			string str = "-32/7";
			Drobi c = a / b;
			Assert::AreEqual(str, c.GetFractString());
		}

		TEST_METHOD(TestMethod4)
		{
			Drobi a(-4, 7), b(1, 8);
			string str = "-1/14";
			Drobi c = a * b;
			Assert::AreEqual(str, c.GetFractString());
		}

		TEST_METHOD(TestMethod5)
		{
			Drobi a(-4, 7), b(1, 1);
			string str = "-7/4";
			Drobi c = power(Drobi(-4, 7), -1);
			Assert::AreEqual(str, c.GetFractString());
		}

		TEST_METHOD(TestMethod6)
		{
			Drobi a(-4, 7), b(1, 1);
			string str = "-7/4";
			Drobi c = rev(a);
			Assert::AreEqual(str, c.GetFractString());
		}
	};
}