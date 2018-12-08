#include <cassert>
#include "CppUnitTest.h"
#include "stdafx.h"
#include <assert.h>
#include "TFracEditor_test.h"
#include "../STP7/TFracEditor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TFracEditor_Test
{
	TEST_CLASS(TFracEditor_Test)
	{
	public:

		TEST_METHOD(Constructor)
		{
			TFracEditor editor;
			assert(editor.getFraction() == "0/1");
		}

		TEST_METHOD(IsZero)
		{
			TFracEditor editor;
			assert(editor.isZeroFraction());
			editor.addDigit(8);
			assert(!editor.isZeroFraction());
		}

		TEST_METHOD(AddSignAndAddDigit)
		{
			TFracEditor editor;
			editor.addDigit(9);
			assert(editor.changeSign() == "-9");
			assert(editor.changeSign() == "9");
		}

		TEST_METHOD(AddZero)
		{
			TFracEditor editor;
			editor.addDigit(8);
			editor.addZero();
			assert(editor.getFraction() == "80");
		}

		TEST_METHOD(Clear)
		{
			TFracEditor editor;
			editor.addDigit(5);
			editor.addDigit(-1);
			//assert(editor.clear() == "0/1");
			Assert::AreEqual(std::string("5-1"), editor.getFraction());
		}


		TEST_METHOD(removeLastDigit)
		{
			TFracEditor editor;
			editor.addDigit(8);
			editor.changeSign();
			assert(editor.removeLastDigit() == "0/1");
		}
		
		TEST_METHOD(addDivider)
		{
			TFracEditor editor;
			editor.addDigit(108);
			editor.addDivider();
			editor.addDigit(18);
			assert(editor.getFraction() == "6/1");
		}

		TEST_METHOD(Set)
		{
			TFracEditor editor;
			editor.setFraction("-2/3");
			editor.setFraction("7//2");
			Assert::AreEqual(std::string("-2/3"), editor.getFraction());
		}
	};
}