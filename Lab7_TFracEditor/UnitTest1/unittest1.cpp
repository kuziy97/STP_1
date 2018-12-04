#include "stdafx.h"
#include "CppUnitTest.h"
#include "../STP7/TFracEditor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			TFracEditor test;
			Assert::AreEqual(test.getNumber(), (std::string)"0/1");
		}

		TEST_METHOD(IsZero)
		{
			TFracEditor test;
			Assert::AreEqual(test.isZero(), true);
			test.addDigit(5);
			Assert::AreEqual(test.isZero(), false);
		}

		TEST_METHOD(AddSignAndAddDigit)
		{
			TFracEditor test;
			test.addDigit(8);
			Assert::AreEqual(test.changeSign(), (std::string)"-8");
			Assert::AreEqual(test.changeSign(), (std::string)"8");
		}

		TEST_METHOD(AddZeroAndAddSplit)
		{
			TFracEditor test;
			test.addDigit(3);
			test.addZero();
			Assert::AreEqual(test.getNumber(), (std::string)"30/1");
			test.addSplit();
			test.addZero();
			test.addDigit(3);
			Assert::AreEqual(test.getNumber(), (std::string)"30/3");
		}

		TEST_METHOD(BackSpace)
		{
			TFracEditor test;
			test.addDigit(8);
			test.changeSign();
			Assert::AreEqual(test.backspace(), (std::string)"0");
		}

		TEST_METHOD(Clear)
		{
			TFracEditor test;
			test.addDigit(7);
			test.addDigit(8);
			test.changeSign();
			Assert::AreEqual(test.clear(), (std::string)"0");
		}

		TEST_METHOD(WriteString)
		{
			TFracEditor test;
			std::string number = "8/1";
			test.setNumber(number);
			Assert::AreEqual(test.getNumber(), (std::string)"8/1");
		}


	};
}