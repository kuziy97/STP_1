#include "stdafx.h"
#include "CppUnitTest.h"
#include <assert.h>
#include "../STP8/TComplexEditor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TComplexEditorTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Constructor)
		{
			TComplexEditor test;
			Assert::AreEqual(test.getNumber(), std::to_string(0.0) + " + i*" + std::to_string(0.0));
		}
		TEST_METHOD(TestIsZero)
		{
			TComplexEditor test;
			Assert::AreEqual(test.isZero(), true);
			test.addDigit(5);
			Assert::AreEqual(test.isZero(), false);
		}
		TEST_METHOD(AddSignAndAddDigit)
		{
			TComplexEditor test;
			test.addDigit(5);
			Assert::AreEqual(test.changeSign(), (std::string)"-5");
			Assert::AreEqual(test.changeSign(), (std::string)"5");
		}
		TEST_METHOD(AddZeroAndAddSplit)
		{
			TComplexEditor test;
			test.addDigit(5);
			test.addZero();
			Assert::AreEqual(test.getNumber(), std::to_string(50.0) + " + i*" + std::to_string(0.0));
			test.addSplit();
			test.addZero();
			test.addDigit(2);
			Assert::AreEqual(test.getNumber(), std::to_string(50.0) + " + i*" + std::to_string(2.0));
		}
		TEST_METHOD(BackSpace)
		{
			TComplexEditor test;
			test.addDigit(5);
			test.changeSign();
			Assert::AreEqual(test.backspace(), (std::string)"0");
		}
		TEST_METHOD(Clear)
		{
			TComplexEditor test;
			test.addDigit(5);
			test.addDigit(6);
			test.changeSign();
			Assert::AreEqual(test.clear(), (std::string)"0");
		}
		TEST_METHOD(WriteString)
		{
			TComplexEditor test;
			std::string number = "3";
			test.setNumber(number);
			Assert::AreEqual(test.getNumber(), std::to_string(3.0) + " + i*" + std::to_string(0.0));
		}
	};
}