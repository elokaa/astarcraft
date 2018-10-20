#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AStarCraft/AstarCraftSource.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AStarCraftUnitTests
{
	TEST_CLASS(BotMapTests)
	{
	public:

		TEST_METHOD(TestSetCellValueWillCreateNonExistentCells)
		{
			//given
			BotMap botMap({});
			Point position(6, 9);
			char expectedValue = 'U';

			//when
			botMap.setValueAtPosition(position, expectedValue);

			//then
			Assert::IsTrue(botMap.getCellValue(position) == expectedValue);
		}

	};
}