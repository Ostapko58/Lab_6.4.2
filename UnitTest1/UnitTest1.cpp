#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.4.2/Lab_6.4.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int* arr = new int[5]{18,-22,50,68,-108};

			Assert::AreEqual(search(arr, 5, arr[0], 1), 68);
			delete[] arr;
		}
	};
}
