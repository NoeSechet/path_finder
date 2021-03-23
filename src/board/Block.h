#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

class Block
{
private:
	bool m_IsObtacle = false;
	sf::Vector2f m_Pos = { 0.0,0.0 };
	sf::RectangleShape m_Rect;

public:
	Block()
	{
		m_Rect.setFillColor(sf::Color::White);
		m_Rect.setSize({ 25.0, 25.0 });
	}
	~Block() = default;

	int GetStatus() const { return m_IsObtacle; }
	void SetPosition(sf::Vector2f newPos) {
		m_Pos = newPos;
		m_Rect.setPosition(sf::Vector2f(
			newPos.x * 30,
			newPos.y * 30
		));
	}

	void Draw(sf::RenderWindow& window) const;
};