#include "pch.h"
#include "CppUnitTest.h"
#include "../lab10.1_A/lab10.1_A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101A
{
	TEST_CLASS(UnitTest101A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Students students[5];
			students[0].grade_physics = 5;
			students[1].grade_physics = 4;
			students[2].grade_physics = 3;
			students[3].grade_physics = 5;
			students[4].grade_physics = 2;

			int result = CountHighPhysicsGrades(students, 5);

			Assert::AreEqual(3, result);
		}
	};
}
