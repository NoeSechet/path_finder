#pragma once

#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Block.h"

class Board
{
private:
	sf::RenderWindow &m_Win;
	sf::Vector2u m_Dim;
	float m_Offset;
	std::vector<std::vector<Block>> m_Board;
	//sf::RectangleShape m_RectTest;

public:
	Board(sf::RenderWindow& m_Win, sf::Vector2u dim, float offset);
	~Board();

	void ToggleWall(sf::Vector2i mousePos, bool shiftPressed);
	void Draw() const;
	void PrintBoard() const;

};