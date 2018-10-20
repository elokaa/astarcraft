#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AStarCraft/AstarCraftSource.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AStarCraftUnitTests
{
	TEST_CLASS(DirectableTests)
	{
	public:

		TEST_METHOD(TestToStringReturnsCorrectRepresentation)
		{
			//given
			AutoBot directableBot(3, 49, 'U');
			string expected = "3 49 U";

			//when
			string rep = directableBot.toString();

			//then
			Assert::IsTrue(rep == expected);
		}

	};
}