#include "Snake.h"

Snake::Snake()
{
	this->snek.emplace_back(RectangleShape(Vector2f(32,32)));
	this->previousPos.emplace_back();
	this->snek.at(0).setPosition({320,320});
	this->snek.at(0).setFillColor(Color::Red);
}

Snake::~Snake(){}

void Snake::move()
{
	for (int i = 0; i < this->segments; i++)
	{
		this->previousPos.at(i) = Vector2f(this->snek.at(i).getPosition().x, this->snek.at(i).getPosition().y);
	}
	
	this->snek.at(0).setPosition(this->X() + 32 * this->facing.x, this->Y() + 32 * this->facing.y);

	for (int i = 1; i < this->segments; i++)
	{
		this->previousPos.at(i) = Vector2f(this->previousPos.at(i - 1));

		this->snek.at(i).setPosition(this->previousPos.at(i-1));
	}
}

void Snake::addSegment()
{
	this->segments += 1;
	this->snek.emplace_back(RectangleShape({ 32,32 }));
	this->snek.at(this->segments).setFillColor(Color::Red);
	this->previousPos.emplace_back(Vector2f(this->snek.at(segments).getPosition().x, this->snek.at(segments).getPosition().y));
	for (int i = 1; i <= this->segments; i++)
	{
		this->previousPos.at(i) = Vector2f(this->snek.at(i-1).getPosition().x, this->snek.at(i-1).getPosition().y);
		
		snek.at(i).setPosition(this->previousPos.at(i-1));
	}
}

void Snake::changeDirection()
{
	if (Keyboard::isKeyPressed(Keyboard::W) && this->facing.y != 1)
	{
		this->facing.x = 0;
		this->facing.y = -1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S) && this->facing.y != -1)
	{
		this->facing.x = 0;
		this->facing.y = 1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::A) && this->facing.x != 1)
	{
		this->facing.x = -1;
		this->facing.y = 0;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D) && this->facing.x != -1)
	{
		this->facing.x = 1;
		this->facing.y = 0;
	}

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		this->addSegment();
	}

}




vector<RectangleShape> Snake::drawSnek()
{
	return this->snek;
}

float Snake::X()
{
	return this->snek.at(0).getPosition().x;
}

float Snake::Y()
{
	return this->snek.at(0).getPosition().y;
}