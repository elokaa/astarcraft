#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AStarCraft/AstarCraftSource.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AStarCraftUnitTests
{
	TEST_CLASS(PointTests)
	{
	public:

		TEST_METHOD(TestEqualOperatorOverload)
		{
			//given
			Point a(23, 45);
			Point b(23, 45);

			//when
			bool equals = a == b;

			//then
			Assert::IsTrue(equals);
		}

		TEST_METHOD(TestPlusOperatorOverloadInRightDirection)
		{
			//given
			Point a(23, 45);
			Direction b('R');
			Point expectedPoint(24, 45);

			//when
			Point newPoint = a + b;

			//then
			Assert::IsTrue(newPoint == expectedPoint);
		}

		TEST_METHOD(TestPlusOperatorOverloadInUpDirection)
		{
			//given
			Point a(23, 45);
			Direction b('U');
			Point expectedPoint(23, 44);

			//when
			Point newPoint = a + b;

			//then
			Assert::IsTrue(newPoint == expectedPoint);
		}

		TEST_METHOD(TestPlusOperatorOverloadInLeftDirection)
		{
			//given
			Point a(23, 45);
			Direction b('L');
			Point expectedPoint(22, 45);

			//when
			Point newPoint = a + b;

			//then
			Assert::IsTrue(newPoint == expectedPoint);
		}

		TEST_METHOD(TestPlusOperatorOverloadInDownDirection)
		{
			//given
			Point a(23, 45);
			Direction b('D');
			Point expectedPoint(23, 46);

			//when
			Point newPoint = a + b;

			//then
			Assert::IsTrue(newPoint == expectedPoint);
		}

	};
}