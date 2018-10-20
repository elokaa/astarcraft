#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//------------------------------------------------------------------------------------------------

typedef vector<vector<char>> Map;

//------------------------------------------------------------------------------------------------

class Direction {
private:
	int dx{ 1 };
	int dy{ 0 };
	char notation{ 'R' };

public:
	explicit Direction(char notation) : notation(notation) {
		switch (notation)
		{
		case 'U':
			dy = -1;
			dx = 0;
			break;
		case 'D':
			dy = 1;
			dx = 0;
			break;
		case 'L':
			dx = -1;
			dy = 0;
			break;
		case 'R':
			dx = 1;
			dy = 0;
			break;
		default:
			break;
		}
	}

	Direction() = default;

	bool operator == (const Direction &other) const {
		return notation == other.notation;
	}

	void operator = (const Direction &other) {
		dx = other.dx;
		dy = other.dy;
		notation = other.notation;
	}

	int getDx() const {
		return dx;
	}

	int getDy() const {
		return dy;
	}

	char getNotation() const {
		return notation;
	}

	string toString() const {
		return string(1, notation);
	}
};

//------------------------------------------------------------------------------------------------

struct Point {
	int x{ 0 };
	int y{ 0 };

	Point(int x, int y) :x(x), y(y) {}

	Point() = default;

	Point operator + (const Direction &direction) const {
		return Point(x + direction.getDx(), y + direction.getDy());
	}

	Point operator += (const Direction &direction) {
		this->x += direction.getDx();
		this->y += direction.getDy();

		return Point(x, y);
	}

	bool operator == (const Point &other) const {
		return x == other.x && y == other.y;
	}

	bool operator == (const string &other) const {
		string str = toString();
		return str == other;
	}

	string toString() const {
		string x = to_string(this->x);
		string y = to_string(this->y);

		return x + " " + y;
	}
};

//------------------------------------------------------------------------------------------------

struct Directable {
protected:
	Point position;
	Direction direction;

public:
	Directable(int x, int y, char direction) {
		position = Point(x, y);
		this->direction = Direction(direction);
	}

	Directable(Point position, Direction direction) : position(position), direction(direction) {}

	Directable() = default;

	string toString() const {
		string point = position.toString();
		string direction = this->direction.toString();

		return point + " " + direction;
	}
};

//------------------------------------------------------------------------------------------------

struct Placement : public Directable {
	Placement(int x, int y, char direction) : Directable(x, y, direction) { }

	Placement(Point position, Direction direction) : Directable(position, direction) {}
};

//------------------------------------------------------------------------------------------------

class AutoBot : public Directable {
private:
	int id{ 0 };
	vector<pair<Point, char>> history;

public:
	AutoBot(int id, int x, int y, char direction) : id(id), Directable(x, y, direction) { }

	AutoBot(int x, int y, char direction) : Directable(x, y, direction) { }

	AutoBot(Point position, Direction direction) : Directable(position, direction) {}

	AutoBot() = default;

	Point getPosition() const {
		return position;
	}

	Direction getDirection() const {
		return direction;
	}

	const Point move(const char direction) {
		return move(Direction(direction));
	}

	const Point move(const Direction &direction) {
		history.push_back(pair<Point, char>(position, this->direction.getNotation()));

		position += direction;
		this->direction = direction;

		return position;
	}

	const Point move() {
		history.push_back(pair<Point, char>(position, direction.getNotation()));

		position += direction;

		return position;
	}

	void undoLastMove() {
		if (!history.size())
		{
			return;
		}

		pair<Point, char> lastMove = history.back();
		history.pop_back();

		position = lastMove.first;
		direction = Direction(lastMove.second);
	}

	void changeDirection(const char direction) {
		this->direction = Direction(direction);
	}

	void changeDirection(const Direction &direction) {
		this->direction = direction;
	}

	bool operator == (const AutoBot &other) const {
		return id == other.id;
	}
};
//------------------------------------------------------------------------------------------------


class BotMap {
private:
	Map map;
	const int MAP_WIDTH = 19;
	const int MAP_HEIGHT = 10;
	const string VALID_CELL_VALUES = "#.URDL";

public:
	explicit BotMap(Map map) : map(map) {}

	char getCellValue(Point position) {
		return map[position.y][position.x];
	}

	char getCellValue(int x, int y) {
		return map[y][x];
	}

	bool isCellVoidAtPosition(Point position) {
		return getCellValue(position) == '#';
	}

	bool isCellEmptyAtPosition(Point position) {
		return getCellValue(position) == '.';
	}

	bool isPositionValid(Point position) {
		return position.y >= 0 && position.y < MAP_HEIGHT
			&& position.x >= 0 && position.x < MAP_WIDTH;
	}

	void setValueAtPosition(Point position, char value) {

		if (!isPositionValid(position) || !VALID_CELL_VALUES.find(value))
		{
			return;
		}

		while (map.size() <= position.y) {
			map.push_back({});
		}

		while (map[position.y].size() <= position.x) {
			map[position.y].push_back('#');
		}

		map[position.y][position.x] = value;
	}
};

//-------------------------------------------------------------------------------------------------

struct IBotEngine {
	virtual string computePlacementsForBotsInMap(BotMap &map, vector<AutoBot> &bots) = 0;
};

class NaiveBotEngine : public IBotEngine {
private:
	string output{ "" };

public:
	virtual string computePlacementsForBotsInMap(BotMap &map, vector<AutoBot> &bots) {
		for (auto bot : bots) {
			Point position;
			bot.move();

			//while()
		}
	}
};