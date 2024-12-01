#pragma once
#include "SFMLlibs.h"

class Snake {
public:

	void addSegment();
	void nextPosition();
	Vector2f getTile();
	void setTile();

private:
	vector<RectangleShape> snek;

};