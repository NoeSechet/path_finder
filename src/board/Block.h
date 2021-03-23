#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

class Block
{
private:
	bool m_IsWall = false;
	sf::Vector2f m_Pos = { 0.0,0.0 };
	sf::RectangleShape m_Rect;

public:
	Block()
	{
		m_Rect.setFillColor(sf::Color::White);
		m_Rect.setSize({ 25.0, 25.0 });
	}
	~Block() = default;

	int GetStatus() const { return m_IsWall; }
	void SetPosition(sf::Vector2f newPos, float offset);

	void Draw(sf::RenderWindow& window) const;
	bool IsClicked(sf::Vector2i mousePos) const;
	void SetIsWall(bool isWall);
};