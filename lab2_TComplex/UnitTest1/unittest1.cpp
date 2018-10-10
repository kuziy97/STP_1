#include "stdafx.h"
//#include "CppUnitTest.h"
#include "../Проект1/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string s = "1-i*2";
			TComplex ai(s);
			TComplex aj(1, 2);
			TComplex c(0, 0);
			string str = "2+0*i";
			c = ai + aj;
			Assert::AreEqual(str, c.GetTComplexSTR());
		}

		TEST_METHOD(TestMethod2)
		{
			string s = "1-i*2";
			TComplex ai(s);
			TComplex aj(1, 2);
			TComplex c(0, 0);
			string str = "5+0*i";
			c = ai * aj;
			Assert::AreEqual(str, c.GetTComplexSTR());
		}
		TEST_METHOD(TestMethod3)
		{
			string s = "1-i*2";
			TComplex ai(s);
			TComplex aj(1, 2);
			TComplex c(0, 0);
			string str = "0-4*i";
			c = ai - aj;
			Assert::AreEqual(str, c.GetTComplexSTR());
		}

		TEST_METHOD(TestMethod4)
		{
			string s = "2+i*3";
			TComplex ai(s);
			TComplex aj(-4, 1);
			TComplex c(0, 0);
			//string str = "--0.8*i";
			c = ai / aj;
			Assert::AreEqual(c.GetRe(),(float)-5./17);
			Assert::AreEqual(c.GetIm(), (float)-14. / 17);
		}

		TEST_METHOD(TestMethod5)
		{
			string s = "1-i*2";
			TComplex ai(s);
			//TComplex aj(1, 2);
			TComplex c(0, 0);
			string str = "-3-4*i";
			c = ai*ai;
			Assert::AreEqual(str, c.GetTComplexSTR());
		}
		
		TEST_METHOD(TestMethod6)
		{
			string s = "2+i*3";
			TComplex ai(s);
			//TComplex aj(1, 2);
			TComplex c(0, 0);
			string str = "-2-3*i";
			c=ai.Minus();
			Assert::AreEqual(str, c.GetTComplexSTR());
		}

	};
}