#include "pch.h"
#include "CppUnitTest.h"
#include "..\Apartment.cpp"
#include "..\Samplings.cpp"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	private:
		Apartment app1{ "test1", 2, 2, 10 };
		Apartment app2{ "test2", 2, 3, 11 };
		Apartment app3{ "test3", 3, 4, 12 };
		Apartment app4{ "test4", 3, 5, 13 };
		Apartment app5{ "test5", 3, 6, 14 };
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::vector<Apartment> apartments;
			apartments.push_back(app1);
			apartments.push_back(app2);
			apartments.push_back(app3);
			apartments.push_back(app4);
			apartments.push_back(app5);
			std::vector<Apartment> sortedApartments = SamplingApartmentsByRoomCount(apartments, 2);
			Assert::IsTrue(sortedApartments.at(0) == app1);
			 sortedApartments = SamplingApartmentsByRoomCount(apartments, 3);
			Assert::IsTrue(sortedApartments.at(0) == app2);
			 sortedApartments = SamplingApartmentsByRoomCount(apartments, 4);
			Assert::IsTrue(sortedApartments.at(0) == app3);
			sortedApartments = SamplingApartmentsByRoomCount(apartments, 5);
			Assert::IsTrue(sortedApartments.at(0) == app4);
			sortedApartments = SamplingApartmentsByRoomCount(apartments, 6);
			Assert::IsTrue(sortedApartments.at(0) == app5);
		}
		TEST_METHOD(TestMethod2)
		{
			std::vector<Apartment> apartments;
			apartments.push_back(app1);
			apartments.push_back(app2);
			apartments.push_back(app3);
			apartments.push_back(app4);
			apartments.push_back(app5);
			std::vector<Apartment> sortedApartments = SamplingApartmentsByRoomCountAndFloorGap(apartments,3, std::tuple<int, int>(2, 3));
			Assert::IsTrue(sortedApartments.at(0) == app2);
		}
		TEST_METHOD(TestMethod3)
		{
			std::vector<Apartment> apartments;
			apartments.push_back(app1);
			apartments.push_back(app2);
			apartments.push_back(app3);
			apartments.push_back(app4);
			apartments.push_back(app5);
			std::vector<Apartment> sortedApartments = SamplingApartmentsByRoomCountAndFloorGap(apartments, 4, std::tuple<int, int>(4, 5));
			Assert::IsTrue(sortedApartments.empty());
		}
		TEST_METHOD(TestMethod4)
		{
			std::vector<Apartment> apartments;
			apartments.push_back(app1);
			apartments.push_back(app2);
			apartments.push_back(app3);
			apartments.push_back(app4);
			apartments.push_back(app5);
			std::vector<Apartment> sortedApartments = SamplingApartmentsByArea(apartments, 12);
			Assert::IsTrue(sortedApartments.at(0) == app4);
			Assert::IsTrue(sortedApartments.at(1) == app5);
		}
		TEST_METHOD(TestMethod5)
		{
			std::vector<Apartment> apartments;
			apartments.push_back(app1);
			apartments.push_back(app2);
			apartments.push_back(app3);
			apartments.push_back(app4);
			apartments.push_back(app5);
			std::vector<Apartment> sortedApartments = SamplingApartmentsByArea(apartments, 20);
			Assert::IsTrue(sortedApartments.empty());
		}
	};
}
