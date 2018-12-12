#include "stdafx.h"
#include "CppUnitTest.h"
#include <assert.h>
#include "../STP8/TComplexEditor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TComplexEditorTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Constructor)
		{
			TComplexEditor test;
			Assert::AreEqual(test.get(), to_string(0.0) + " + i*" + to_string(0.0));
		}
		TEST_METHOD(Zero)
		{
			TComplexEditor test;
			Assert::AreEqual(test.isZero(), true);
			test.addDigit(9);
			Assert::AreEqual(test.isZero(), false);
		}
		TEST_METHOD(SignAndDigit)
		{
			TComplexEditor test;
			test.addDigit(9);
			Assert::AreEqual(test.changeSign(), (std::string)"-9");
			Assert::AreEqual(test.changeSign(), (std::string)"9");
		}
		TEST_METHOD(ZeroAndSplit)
		{
			TComplexEditor test;
			test.addDigit(9);
			test.addZero();
			Assert::AreEqual(test.get(), std::to_string(90.0) + " + i*" + std::to_string(0.0));
			test.addSplit();
			test.addZero();
			test.addDigit(2);
			Assert::AreEqual(test.get(), std::to_string(90.0) + " + i*" + std::to_string(2.0));
		}
		TEST_METHOD(BackSpace)
		{
			TComplexEditor test;
			test.addDigit(7);
			test.changeSign();
			Assert::AreEqual(test.backspace(), (string)"0");
		}
		TEST_METHOD(Clear)
		{
			TComplexEditor test;
			test.addDigit(3);
			test.addDigit(2);
			test.changeSign();
			Assert::AreEqual(test.clear(), (string)"0");
		}
		TEST_METHOD(SetAndGet)
		{
			TComplexEditor test;
			string number = "2+i*3";
			test.set(number);
			test.backspace();
			test.backspace();
			test.backspace();
			test.backspace();
			test.backspace();
			test.backspace();
			Assert::AreEqual(to_string(9.0) + " + i*" + to_string(0.0), test.get());
		}
	};
}