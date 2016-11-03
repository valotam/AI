#include "BoundingBox.h"

BoundingBox::BoundingBox()
{
	center.x = 0;
	center.y = 0;
	halfDimension = 0;
}

BoundingBox::BoundingBox(float x, float y, float halfDimension)
{
	center.x = x;
	center.y = y;
	this->halfDimension = halfDimension;
}

void BoundingBox::setPosition(float x, float y)
{
	center.x = x;
	center.y = y;
}

bool BoundingBox::containsPoint(Point point)
{
	return (center.x - halfDimension <= point.x && center.x + halfDimension >= point.x) &&
		(center.y - halfDimension <= point.y && center.y + halfDimension >= point.y);
}

bool BoundingBox::intersects(BoundingBox boundingBox)
{
	return (center.x - halfDimension < boundingBox.center.x + boundingBox.halfDimension) &&
		(center.x + halfDimension > boundingBox.center.x - boundingBox.halfDimension) &&
		(center.y - halfDimension < boundingBox.center.y + boundingBox.halfDimension) &&
		(center.y + halfDimension > boundingBox.center.y - boundingBox.halfDimension);
}

void BoundingBox::draw(sf::RenderWindow * window)
{
	sf::RectangleShape shape;
	shape.setPosition(sf::Vector2f(center.x - halfDimension, center.y - halfDimension));
	shape.setSize(sf::Vector2f(halfDimension * 2, halfDimension * 2));
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineThickness(1);
	window->draw(shape);
}