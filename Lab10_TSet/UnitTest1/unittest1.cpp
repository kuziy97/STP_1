#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TSet/TFrac.h"
#include "../TSet/TSet.h"
#include "../TSet/TSet2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(constructor)
		{
			TSet<int> t1;
			Assert::AreEqual(t1.empty(), true);

			TSet<TFrac> t2;
			Assert::AreEqual(t2.empty(), true);

			TSet2<int> t3;
			Assert::AreEqual(t3.empty(), true);

			TSet2<TFrac> t4;
			Assert::AreEqual(t4.empty(), true);
		}

		TEST_METHOD(clearANDempty)
		{
			TSet<int> t1;
			t1.insert(1);
			t1.insert(2);
			t1.clear();
			Assert::AreEqual(t1.empty(), true);

			TSet<TFrac> t2;
			t2.insert(TFrac(1, 2));
			t2.insert(TFrac(7, 5));
			t2.clear();
			Assert::AreEqual(t2.empty(), true);

			TSet2<int> t3;
			t3.insert(1);
			t3.insert(2);
			t3.clear();
			Assert::AreEqual(t3.empty(), true);

			TSet2<TFrac> t4;
			t4.insert(TFrac(1, 2));
			t4.insert(TFrac(7, 5));
			t4.clear();
			Assert::AreEqual(t4.empty(), true);
		}

		TEST_METHOD(insert)
		{
			TSet<int> t1;
			t1.insert(1);
			t1.insert(2);
			Assert::IsTrue(t1.size() == 2);
			Assert::IsTrue(t1.getElement(0) == 1);
			Assert::IsTrue(t1.getElement(1) == 2);

			TSet<TFrac> t2;
			t2.insert(TFrac(1, 2));
			t2.insert(TFrac(7, 5));
			Assert::IsTrue(t2.size() == 2);
			Assert::IsTrue(t2.getElement(0) == TFrac(1, 2));
			Assert::IsTrue(t2.getElement(1) == TFrac(7, 5));

			TSet2<int> t3;
			t3.insert(1);
			t3.insert(2);
			Assert::IsTrue(t3.size() == 2);
			Assert::IsTrue(t3.getElement(0) == 1);
			Assert::IsTrue(t3.getElement(1) == 2);

			TSet2<TFrac> t4;
			t4.insert(TFrac(1, 2));
			t4.insert(TFrac(7, 5));
			Assert::IsTrue(t2.size() == 2);
			Assert::IsTrue(t2.getElement(0) == TFrac(1, 2));
			Assert::IsTrue(t2.getElement(1) == TFrac(7, 5));
		}

		TEST_METHOD(erase)
		{
			TSet<int> t1;
			t1.insert(1);
			t1.insert(2);
			t1.insert(3);
			t1.erase(4);
			t1.erase(2);
			Assert::IsTrue(t1.size() == 2);
			Assert::IsTrue(t1.getElement(0) == 1);
			Assert::IsTrue(t1.getElement(1) == 3);

			TSet<TFrac> t2;
			t2.insert(TFrac(1, 2));
			t2.insert(TFrac(7, 5));
			t2.insert(TFrac(3, 4));
			t2.erase(TFrac(5, 6));
			t2.erase(TFrac(7, 5));
			Assert::IsTrue(t2.size() == 2);
			Assert::IsTrue(t2.getElement(0) == TFrac(1, 2));
			Assert::IsTrue(t2.getElement(1) == TFrac(3, 4));

			TSet2<int> t3;
			t3.insert(1);
			t3.insert(2);
			t3.insert(3);
			t3.erase(4);
			t3.erase(2);
			Assert::IsTrue(t3.size() == 2);
			Assert::IsTrue(t3.getElement(0) == 1);
			Assert::IsTrue(t3.getElement(1) == 3);

			TSet2<TFrac> t4;
			t4.insert(TFrac(1, 2));
			t4.insert(TFrac(7, 5));
			t4.insert(TFrac(3, 4));
			t4.erase(TFrac(5, 6));
			t4.erase(TFrac(7, 5));
			Assert::IsTrue(t2.size() == 2);
			Assert::IsTrue(t2.getElement(0) == TFrac(1, 2));
			Assert::IsTrue(t2.getElement(1) == TFrac(3, 4));
		}
		
		TEST_METHOD(soderzhit)
		{
			TSet<int> t1;
			t1.insert(1);
			t1.insert(2);
			Assert::AreEqual(t1.soderzhit(1), true);
			Assert::AreEqual(t1.soderzhit(2), true);
			Assert::AreEqual(t1.soderzhit(3), false);

			TSet<TFrac> t2;
			t2.insert(TFrac(1, 2));
			Assert::AreEqual(t2.soderzhit(TFrac(1, 2)), true);
			Assert::AreEqual(t2.soderzhit(TFrac(3, 2)), false);

			TSet2<int> t3;
			t3.insert(1);
			Assert::AreEqual(t3.soderzhit(1), true);
			Assert::AreEqual(t3.soderzhit(3), false);

			TSet2<TFrac> t4;
			t4.insert(TFrac(1, 2));
			Assert::AreEqual(t4.soderzhit(TFrac(1, 2)), true);
			Assert::AreEqual(t4.soderzhit(TFrac(3, 2)), false);
		}
		
		TEST_METHOD(obedinenie)
		{
			TSet<int> t1;
			t1.insert(1);
			t1.insert(2);

			TSet<int> t2;
			t1.insert(3);
			t1.insert(4);

			TSet<int> t3 = t1.obedinenie(t2);
			Assert::IsTrue(t3.size() == 4);
			Assert::IsTrue(t3.getElement(0) == 1);
			Assert::IsTrue(t3.getElement(1) == 2);
			Assert::IsTrue(t3.getElement(2) == 3);
			Assert::IsTrue(t3.getElement(3) == 4);
			
			TSet<TFrac> t4;
			t4.insert(TFrac(1, 2));
			t4.insert(TFrac(3, 4));

			TSet<TFrac> t5;
			t5.insert(TFrac(5, 6));
			t5.insert(TFrac(7, 8));

			TSet<TFrac> t6 = t4.obedinenie(t5);
			Assert::IsTrue(t6.size() == 4);
			Assert::IsTrue(t6.getElement(0) == TFrac(1, 2));
			Assert::IsTrue(t6.getElement(1) == TFrac(3, 4));
			Assert::IsTrue(t6.getElement(2) == TFrac(5, 6));
			Assert::IsTrue(t6.getElement(3) == TFrac(7, 8));

			TSet2<int> t7;
			t7.insert(1);
			t7.insert(2);

			TSet2<int> t8;
			t8.insert(3);
			t8.insert(4);

			TSet2<int> t9 = t7.obedinenie(t8);
			Assert::IsTrue(t9.size() == 4);
			Assert::IsTrue(t9.getElement(0) == 1);
			Assert::IsTrue(t9.getElement(1) == 2);
			Assert::IsTrue(t9.getElement(2) == 3);
			Assert::IsTrue(t9.getElement(3) == 4);

			TSet<TFrac> t10;
			t10.insert(TFrac(1, 2));
			t10.insert(TFrac(3, 4));

			TSet<TFrac> t11;
			t11.insert(TFrac(5, 6));
			t11.insert(TFrac(7, 8));

			TSet<TFrac> t12 = t10.obedinenie(t11);
			Assert::IsTrue(t12.size() == 4);
			Assert::IsTrue(t12.getElement(0) == TFrac(1, 2));
			Assert::IsTrue(t12.getElement(1) == TFrac(3, 4));
			Assert::IsTrue(t12.getElement(2) == TFrac(5, 6));
			Assert::IsTrue(t12.getElement(3) == TFrac(7, 8));
		}
		
		TEST_METHOD(raznost)
		{
			TSet<int> t1;
			t1.insert(1);
			t1.insert(2);
			t1.insert(3);

			TSet<int> t2;
			t2.insert(3);
			t2.insert(4);

			TSet<int> t3 = t1.raznost(t2);
			Assert::IsTrue(t3.size() == 2);
			Assert::IsTrue(t3.getElement(0) == 1);
			Assert::IsTrue(t3.getElement(1) == 2);

			TSet<TFrac> t4;
			t4.insert(TFrac(1, 2));
			t4.insert(TFrac(3, 4));
			t4.insert(TFrac(5, 6));

			TSet<TFrac> t5;
			t5.insert(TFrac(5, 6));
			t5.insert(TFrac(7, 8));

			TSet<TFrac> t6 = t4.raznost(t5);
			Assert::IsTrue(t6.size() == 2);
			Assert::IsTrue(t6.getElement(0) == TFrac(1, 2));
			Assert::IsTrue(t6.getElement(1) == TFrac(3, 4));

			TSet2<int> t7;
			t7.insert(1);
			t7.insert(2);
			t7.insert(3);

			TSet2<int> t8;
			t8.insert(3);
			t8.insert(4);

			TSet2<int> t9 = t7.raznost(t8);
			Assert::IsTrue(t9.size() == 2);
			Assert::IsTrue(t9.getElement(0) == 1);
			Assert::IsTrue(t9.getElement(1) == 2);

			TSet<TFrac> t10;
			t10.insert(TFrac(1, 2));
			t10.insert(TFrac(3, 4));
			t10.insert(TFrac(5, 6));

			TSet<TFrac> t11;
			t11.insert(TFrac(5, 6));
			t11.insert(TFrac(7, 8));

			TSet<TFrac> t12 = t10.raznost(t11);
			Assert::IsTrue(t12.size() == 2);
			Assert::IsTrue(t12.getElement(0) == TFrac(1, 2));
			Assert::IsTrue(t12.getElement(1) == TFrac(3, 4));
		}
		
		TEST_METHOD(peresechenie)
		{
			TSet<int> t1;
			t1.insert(1);
			t1.insert(2);
			t1.insert(3);

			TSet<int> t2;
			t2.insert(3);
			t2.insert(4);

			TSet<int> t3 = t1.peresechenie(t2);
			Assert::IsTrue(t3.size() == 1);
			Assert::IsTrue(t3.getElement(0) == 3);

			TSet<TFrac> t4;
			t4.insert(TFrac(1, 2));
			t4.insert(TFrac(3, 4));
			t4.insert(TFrac(5, 6));

			TSet<TFrac> t5;
			t5.insert(TFrac(5, 6));
			t5.insert(TFrac(7, 8));

			TSet<TFrac> t6 = t4.peresechenie(t5);
			Assert::IsTrue(t6.size() == 1);
			Assert::IsTrue(t6.getElement(0) == TFrac(5, 6));

			TSet2<int> t7;
			t7.insert(1);
			t7.insert(2);
			t7.insert(3);

			TSet2<int> t8;
			t8.insert(3);
			t8.insert(4);

			TSet2<int> t9 = t7.peresechenie(t8);
			Assert::IsTrue(t9.size() == 1);
			Assert::IsTrue(t9.getElement(0) == 3);

			TSet<TFrac> t10;
			t10.insert(TFrac(1, 2));
			t10.insert(TFrac(3, 4));
			t10.insert(TFrac(5, 6));

			TSet<TFrac> t11;
			t11.insert(TFrac(5, 6));
			t11.insert(TFrac(7, 8));

			TSet<TFrac> t12 = t10.peresechenie(t11);
			Assert::IsTrue(t12.size() == 1);
			Assert::IsTrue(t12.getElement(0) == TFrac(5, 6));
		}
	};
}