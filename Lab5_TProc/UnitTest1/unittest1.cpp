#include "stdafx.h"
#include "CppUnitTest.h"

#include "../STP5/TProc.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TProcTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(ConstructorAndGetters)
		{
			TProc<int> test = TProc<int>();
			int lrget = test.Lop_Res_Get();
			int rget = test.Rop_Get();
			TOprtn operation = test.OprtnGet();
			Assert::IsTrue(lrget == int());
			Assert::IsTrue(rget == int());
			Assert::IsTrue(operation == None);
		}


		TEST_METHOD(Setters)
		{
			TProc<int> test = TProc<int>();
			int test1(2), test2(3);
			test.Lop_Res_Set(test1);
			test.Rop_Set(test2);
			test.OprtnSet(Add);
			Assert::IsTrue(test.Lop_Res_Get() == test1);
			Assert::IsTrue(test.Rop_Get() == test2);
			Assert::IsTrue(test.OprtnGet() == Add);
		}


		TEST_METHOD(Reset)
		{
			TProc<int> test = TProc<int>();
			test.Lop_Res_Set(int(1));
			test.Rop_Set(int(4));
			test.OprtnSet(Add);
			test.ReSet();
			Assert::IsTrue(test.Lop_Res_Get() == int());
			Assert::IsTrue(test.Rop_Get() == int());
			Assert::IsTrue(test.OprtnGet() == None);
		}


		TEST_METHOD(OprtnClear)
		{
			TProc<int> test = TProc<int>();
			test.OprtnSet(Sub);
			test.OprtnClear();
			Assert::IsTrue(test.OprtnGet() == None);
		}


		TEST_METHOD(OprtnRun)
		{
			TProc<int> test = TProc<int>();
			test.Lop_Res_Set(int(3));
			test.Rop_Set(int(4));
			test.OprtnSet(Mul);
			test.OprtnRun();
			Assert::IsTrue(test.Lop_Res_Get() == int(12));
			Assert::IsTrue(test.Rop_Get() == int(4));
			Assert::IsTrue(test.OprtnGet() == Mul);
		}



		TEST_METHOD(TestRun)
		{
			TProc<int> test = TProc<int>();

			test.Lop_Res_Set(int(5));
			test.OprtnSet(Add);
			Assert::IsTrue(test.Lop_Res_Get() == int(5));
			Assert::IsTrue(test.Rop_Get() == int());
			Assert::IsTrue(test.OprtnGet() == Add);

			test.Rop_Set(int(3));
			test.OprtnRun();
			test.OprtnSet(Mul);
			Assert::IsTrue(test.Lop_Res_Get() == 8);
			Assert::IsTrue(test.Rop_Get() == int(3));
			Assert::IsTrue(test.OprtnGet() == Mul);


			test.ReSet();
			Assert::IsTrue(test.Lop_Res_Get() == int());
			Assert::IsTrue(test.Rop_Get() == int());
			Assert::IsTrue(test.OprtnGet() == None);
		}

		TEST_METHOD(TestRun1)
		{
			TProc<int> test = TProc<int>();

			test.Lop_Res_Set(int(2));
			test.Rop_Set(int(1));
			test.OprtnSet(Dvd);
			test.OprtnRun();
			test.Rop_Set(int(3));
			test.OprtnSet(Add);
			test.OprtnRun();
			Assert::IsTrue(test.Lop_Res_Get() == int(5));
		}
	};
}