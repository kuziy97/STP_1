#include "stdafx.h"
#include "CppUnitTest.h"
#include "../STP3/TPNumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			TPNumber A("-2F4.FF", 16, 2);
			TPNumber c("0", 16, 2);
			string str = "-2F4.FF";
			c = A.Copy();
			Assert::AreEqual(str, c.GetPString());
		}

		TEST_METHOD(TestMethod2)
		{
			TPNumber A("2F4.FF0", 16, 3);
			TPNumber B("503.020", 16, 3);
			string str = "7F8.010";
			TPNumber c = A + B;
			Assert::AreEqual(str, c.GetPString());
		}

		TEST_METHOD(TestMethod3)
		{
			TPNumber A("2F4.FF", 16, 2);
			TPNumber B(1235, 16, 2);
			TPNumber c(0, 16, 2);
			string str = "-1DE.01";
			c = A - B;
			Assert::AreEqual(str, c.GetPString());
		}

		TEST_METHOD(TestMethod4)
		{
			TPNumber A("2F4.FF", 16, 2);
			TPNumber B(1235, 16, 2);
			TPNumber c(0, 16, 2);
			string str = "E43EA.30";
			c = A * B;
			Assert::AreEqual(str, c.GetPString());
		}

		TEST_METHOD(TestMethod5)
		{
			TPNumber A("2F4.FF", 16, 6);
			TPNumber B(1235, 16, 6);
			TPNumber c(0, 16, 6);
			string str = "0.9CEA71";
			c = A / B;
			Assert::AreEqual(str, c.GetPString());
		}

		TEST_METHOD(TestMethod6)
		{
			TPNumber A("2F4.FF", 16, 6);
			TPNumber c(0, 16, 2);
			string str = "0.005692";
			c = A.Reverse();
			Assert::AreEqual(str, c.GetPString());
		}

		TEST_METHOD(TestMethod7)
		{
			TPNumber A("2F4.FF", 16, 2);
			TPNumber c(0, 16, 2);
			string str = "8BE73.10";
			c = A * A;
			Assert::AreEqual(str, c.GetPString());
		}
	};
}