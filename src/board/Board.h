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
	std::vector<std::vector<Block>> m_Board;

	//sf::RectangleShape m_RectTest;

public:
	Board(sf::RenderWindow& m_Win, sf::Vector2u dim);
	~Board();

	void Draw() const;

	void PrintBoard() const;

};