#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TPoly/TPoly.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TMemberConstructor)
		{
			TPoly::TMember test;
			TPoly::TMember test2(5, 4);
			Assert::AreEqual(test.getCoefficient(), 0);
			Assert::AreEqual(test.getDegree(), 0);
			Assert::AreEqual(test2.getCoefficient(), 5);
			Assert::AreEqual(test2.getDegree(), 4);
		}
		TEST_METHOD(TMemberSets)
		{
			TPoly::TMember test;
			test.setCoefficient(5);
			test.setDegree(4);
			Assert::AreEqual(test.getCoefficient(), 5);
			Assert::AreEqual(test.getDegree(), 4);
		}
		TEST_METHOD(TMemberEqually)
		{
			TPoly::TMember test(5, 4);
			TPoly::TMember test2(5, 4);
			TPoly::TMember test3(3, 4);
			Assert::IsTrue(test == test2);
			Assert::IsFalse(test == test3);
		}
		TEST_METHOD(TMemberDifferentiate)
		{
			TPoly::TMember test(5, 4);
			TPoly::TMember res(20, 3);
			Assert::IsTrue(test.differentiate() == res);
		}
		TEST_METHOD(TMemberCalculate)
		{
			TPoly::TMember test(5, 4);
			Assert::IsTrue(test.calculate(2) == 80);
		}
		TEST_METHOD(TMemberString)
		{
			TPoly::TMember test(5, 4);
			Assert::AreEqual(test.toString(), (std::string)"5*x^4");
		}
		TEST_METHOD(TPolyConstructor)
		{
			TPoly test(5, 4);
			TPoly test2;
			Assert::IsTrue(test.element(0) == TPoly::TMember(5, 4));
			Assert::AreEqual(test2.getDegree(), 0);
			Assert::AreEqual(test2.getCoefficient(0), 0);
		}
		TEST_METHOD(TPolyClear)
		{
			TPoly test(5, 4);
			test.clear();
			Assert::AreEqual(test.getDegree(), 0);
			Assert::AreEqual(test.getCoefficient(0), 0);
		}
		TEST_METHOD(TPolyPlus)
		{
			TPoly test(5, 4);
			TPoly res = test + TPoly::TMember(6, 5);
			Assert::AreEqual(res.getDegree(), 5);
			Assert::AreEqual(res.getCoefficient(5), 6);
			Assert::AreEqual(res.getCoefficient(4), 5);
			Assert::AreEqual(res.calculate(1), 11.0);
			TPoly res2 = test + test;
			Assert::AreEqual(res2.getDegree(), 4);
			Assert::AreEqual(res2.getCoefficient(4), 10);
		}
		TEST_METHOD(TPolyMinus)
		{
			TPoly test(5, 4);

			TPoly res = test - TPoly::TMember(6, 5);
			Assert::AreEqual(res.getDegree(), 5);
			Assert::AreEqual(res.getCoefficient(5), -6);
			Assert::AreEqual(res.getCoefficient(4), 5);
			Assert::AreEqual(res.calculate(1), -1.0);
		}
		TEST_METHOD(TPolyMultiplication)
		{
			TPoly test(5, 4);
			TPoly test1(3, 2);
			TPoly res = test * test1;

			Assert::AreEqual(res.getCoefficient(6), 15);
		}
		TEST_METHOD(TPolyEqually)
		{
			TPoly test(5, 4);
			TPoly test2(3, 2);
			TPoly test3(3, 2);
			Assert::IsFalse(test == test2);
			Assert::IsTrue(test2 == test3);
			Assert::IsTrue(test3 == test3);
		}
		TEST_METHOD(TPolyDifferentiate)
		{
			TPoly test = (TPoly(5, 4) + TPoly::TMember(3, 2)).differentiate();
			Assert::AreEqual(test.getCoefficient(1), 6);
			Assert::AreEqual(test.getCoefficient(3), 20);
		}
		TEST_METHOD(TPolyCalculate)
		{
			TPoly test = TPoly(5, 4) + TPoly::TMember(3, 2);
			Assert::AreEqual(test.calculate(1), 8.0);
		}




















		TEST_METHOD(test2) {
			TPoly test = TPoly(1, 2) + TPoly::TMember(1, 0); 
			TPoly test2 = TPoly(1, 2) + TPoly::TMember(0, 0); 
			TPoly test3 = test + test2; 

			Assert::AreEqual(test3.getCoefficient(2), 2);
			Assert::AreEqual(test3.getCoefficient(0), 1);
		}
	};
}
