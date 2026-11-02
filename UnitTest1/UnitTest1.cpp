#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB2.5/Car.h"
#include "../LAB2.5/Lorry.h"
#include "../LAB2.5/Car.cpp"
#include "../LAB2.5/Lorry.cpp"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCarInitializationAndGetters)
		{
			Car testCar("Mazda", 4, 150.0);

			Assert::AreEqual(string("Mazda"), testCar.GetBrand());
			Assert::AreEqual(4, testCar.GetCylinders());
			Assert::AreEqual(150.0, testCar.GetPower());
		}

		TEST_METHOD(TestCarSettersValidation)
		{
			Car invalidCar;
			Assert::IsFalse(invalidCar.SetPower(-20.0));
			Assert::AreEqual(0.0, invalidCar.GetPower());
		}

		TEST_METHOD(TestLorryIncrement)
		{
			Car testCar("Mazda", 4, 150.0);
			Lorry testLorry(testCar, 15.0);

			Assert::AreEqual(15.0, testLorry.GetCapacity());
			++testLorry;
			Assert::AreEqual(25.0, testLorry.GetCapacity());
		}

		TEST_METHOD(TestLorryReassignBrand)
		{
			Car testCar("Mazda", 4, 150.0);
			Lorry testLorry(testCar, 15.0);
			testLorry.ReassignBrand("Volvo");

			Assert::AreEqual(string("Volvo"), testLorry.GetCar().GetBrand());
		}
	};
}
