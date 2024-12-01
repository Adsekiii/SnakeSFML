#pragma once
#include "SFMLlibs.h"

class Snake {
public:
	Snake();
	~Snake();
	void addSegment();
	void nextPosition();
	Vector2f getTile();
	void changeDirection();
	void move();

	vector<RectangleShape> drawSnek();

	float X();
	float Y();

private:
	vector<RectangleShape> snek;
	vector<Vector2f> previousPos;
	Vector2f facing;

	int segments = 0;

	void changeFacing();
};