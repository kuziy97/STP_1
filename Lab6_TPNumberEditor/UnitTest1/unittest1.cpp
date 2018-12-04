#include "stdafx.h"
#include "CppUnitTest.h"
#include "../STP6/TPNumberEditor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TPNumberEditorTest
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(Constructor)
		{
			TPNumberEditor test;
			Assert::AreEqual(test.getNumber(), (std::string)"0");
		}

		TEST_METHOD(TestIsZero)
		{
			TPNumberEditor test;
			Assert::AreEqual(test.isZero(), true);
			test.addDigit(5);
			Assert::AreEqual(test.isZero(), false);
		}

		TEST_METHOD(AddSignAndAddDigit)
		{
			TPNumberEditor test;
			test.addDigit(5);
			Assert::AreEqual(test.changeSign(), (std::string)"-5");
			Assert::AreEqual(test.changeSign(), (std::string)"5");
		}
		TEST_METHOD(AddZeroAndAddSplit)
		{
			TPNumberEditor test;
			test.addDigit(5);
			test.addZero();
			Assert::AreEqual(test.getNumber(), (std::string)"50");
			test.addSplit();
			test.addZero();
			test.addDigit(1);
			Assert::AreEqual(test.getNumber(), (std::string)"51");
		}
		TEST_METHOD(BackSpace)
		{
			TPNumberEditor test;
			test.addDigit(5);
			test.changeSign();
			Assert::AreEqual(test.backspace(), (std::string)"0");
		}
		TEST_METHOD(Clear)
		{
			TPNumberEditor test;
			test.addDigit(5);
			test.addDigit(6);
			test.changeSign();
			Assert::AreEqual(test.clear(), (std::string)"0");
		}
		TEST_METHOD(WriteString)
		{
			TPNumberEditor test;
			std::string number = "42";
			test.setNumber(number);
			Assert::AreEqual(test.getNumber(), number);
		}

		TEST_METHOD(SetAndGet)
		{
			TPNumberEditor test;
			std::string number = "10";
			test.SetBase(10);
			Assert::AreEqual(test.GetBaseAsStr(), number);
		}

	};
}
