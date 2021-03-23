#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

enum class BLOCK_TYPE {
	COMM,
	START,
	END
};

class Block
{
private:
	bool m_IsWall = false;
	sf::Vector2f m_Pos = { 0.0,0.0 };
	sf::RectangleShape m_Rect;
	BLOCK_TYPE m_Type = BLOCK_TYPE::COMM;

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
	BLOCK_TYPE GetType() const { return m_Type; }
	void SetType(BLOCK_TYPE type);
};