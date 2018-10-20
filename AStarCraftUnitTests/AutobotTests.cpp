#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AStarCraft/AstarCraftSource.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AStarCraftUnitTests
{
	TEST_CLASS(AutobotTests)
	{
	public:

		TEST_METHOD(TestMoveRightWillMoveBotToTheRight)
		{
			//given
			AutoBot bot(5, 5, 'R');
			AutoBot botAfterMoveRight(6, 5, 'R');

			//when
			bot.move('R');

			//then
			Assert::IsTrue(bot.getPosition() == botAfterMoveRight.getPosition());
			Assert::IsTrue(bot.getDirection() == botAfterMoveRight.getDirection());
		}

		TEST_METHOD(TestMoveUpWillMoveBotUp)
		{
			//given
			AutoBot bot(5, 5, 'R');
			AutoBot botAfterMoveUp(5, 4, 'U');

			//when
			bot.move('U');

			//then
			Assert::IsTrue(bot.getPosition() == botAfterMoveUp.getPosition());
			Assert::IsTrue(bot.getDirection() == botAfterMoveUp.getDirection());
		}

		TEST_METHOD(TestMoveLeftWillMoveBotToTheLeft)
		{
			//given
			AutoBot bot(5, 5, 'R');
			AutoBot botAfterMoveLeft(4, 5, 'L');

			//when
			bot.move('L');

			//then
			Assert::IsTrue(bot.getPosition() == botAfterMoveLeft.getPosition());
			Assert::IsTrue(bot.getDirection() == botAfterMoveLeft.getDirection());
		}

		TEST_METHOD(TestMoveDownWillMoveBotDown)
		{
			//given
			AutoBot bot(5, 5, 'R');
			AutoBot botAfterMoveDown(5, 6, 'D');

			//when
			bot.move('D');

			//then
			Assert::IsTrue(bot.getPosition() == botAfterMoveDown.getPosition());
			Assert::IsTrue(bot.getDirection() == botAfterMoveDown.getDirection());
		}

		TEST_METHOD(TestUndoLastMoveWillRevertToLastMove)
		{
			//given
			AutoBot bot(5, 5, 'R');
			Point expectedPosition(5, 5);
			Direction expectedDirection('R');

			//when
			bot.move('D');
			bot.undoLastMove();

			//then
			Assert::IsTrue(bot.getPosition() == expectedPosition);
			Assert::IsTrue(bot.getDirection() == expectedDirection);
		}

	};
}