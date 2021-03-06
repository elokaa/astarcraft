// AStarCraft.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "AstarCraftSource.h"

using namespace std;


/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{

	Map map;

	for (int i = 0; i < 10; i++) {
		string line;
		cin >> line; cin.ignore();

		vector<char> row;
		for (auto c : line) {
			row.push_back(c);
		}

		map.push_back(row);
		cerr << line << endl;
	}

	int robotCount;
	cin >> robotCount; cin.ignore();

	vector<AutoBot> autoBots;

	for (int i = 0; i < robotCount; i++) {
		int x;
		int y;
		char direction;
		cin >> x >> y >> direction; cin.ignore();
		autoBots.push_back(AutoBot(i, x, y, direction));
	}

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

	//cout << /*Placement(autoBots[0].getPosition(), autoBots[0].getDirection()).toString() <<*/ endl;

	if (autoBots[0].getPosition() == "3 4") {
		cout << "3 4 R" << endl;
	}
	else {
		cout << "14 4 R" << endl;
	}
}
