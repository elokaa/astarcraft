#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AStarCraft/AstarCraftSource.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AStarCraftUnitTests
{
	TEST_CLASS(DirectionTests)
	{
	public:

		TEST_METHOD(TestAssignmentAssignsCorrectValue)
		{
			//given
			Direction a('R');
			Direction b('L');

			//when
			a = b;

			//then
			Assert::IsTrue(a == b);
		}

	};
}