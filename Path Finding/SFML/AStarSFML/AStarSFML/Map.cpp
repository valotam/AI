#include "Map.h"

Map::Map(sf::Vector2i size, int tileSize)
{
	this->size = size;
	this->tileSize = tileSize;
	map.resize(size.x, std::vector<int>(size.y, true));
}

void Map::draw(sf::RenderWindow* window)
{
	for(int x = 0; x < size.x; ++x)
	{
		for(int y = 0; y < size.y; ++y)
		{
			sf::RectangleShape shape;
			shape.setPosition(y * tileSize, x * tileSize);
			shape.setSize(sf::Vector2f(tileSize, tileSize));
			shape.setOutlineColor(sf::Color::Black);
			shape.setOutlineThickness(-1);

			int cellValue = getValue(sf::Vector2i(x, y));

			if(cellValue == TILE_EMPTY)
			{
				shape.setFillColor(sf::Color(96, 96, 96));
			}
			else if(cellValue == TILE_SOLID)
			{
				shape.setFillColor(sf::Color(34, 34, 34));
			}
			else if(cellValue == TILE_END)
			{
				shape.setFillColor(sf::Color(64, 0, 0));
			}
			else if(cellValue == TILE_START)
			{
				shape.setFillColor(sf::Color(0, 64, 0));
			}
			else if (cellValue == TILE_VISITED)
			{
				shape.setFillColor(sf::Color(221, 221, 221));
			}
			else if(cellValue == TILE_PATH)
			{
				shape.setFillColor(sf::Color(225, 185, 115));
			}

			window->draw(shape);
		}
	}
}

void Map::reset()
{
	for(int x = 0; x < size.x; ++x)
	{
		for(int y = 0; y < size.y; ++y)
		{
			if(map[x][y] == TILE_VISITED)
			{
				map[x][y] = TILE_EMPTY;
			}
			else if(map[x][y] == TILE_PATH)
			{
				map[x][y] = TILE_EMPTY;
			}
		}
	}
}

sf::Vector2i Map::getSize() const
{
	return size;
}

void Map::setMap(std::vector<std::vector<int>> map)
{
	for (int x = 0; x < size.x; ++x)
	{
		for (int y = 0; y < size.y; ++y)
		{
			this->map[x][y] = map[x][y];
		}
	}
}

void Map::setValue(sf::Vector2i position, int value)
{
	map[position.x][position.y] = value;
}

int Map::getValue(sf::Vector2i position)
{
	return map[position.x][position.y];
}

Map::~Map()
{
}
