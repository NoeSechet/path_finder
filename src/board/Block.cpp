#include "Block.h"

void Block::Draw(sf::RenderWindow& window) const
{
	window.draw(m_Rect);
}

void Block::SetPosition(sf::Vector2f newPos, float offset) {
	m_Pos = newPos;
	m_Rect.setPosition(sf::Vector2f(
		newPos.x * offset,
		newPos.y * offset
	));
}

void Block::SetIsWall(bool isWall)
{
	m_IsWall = isWall;
	if (isWall) {
		m_Rect.setFillColor(sf::Color::White);
	}
	else {
		m_Rect.setFillColor(sf::Color::Red);
	}
}

bool Block::IsClicked(sf::Vector2i mousePos) const
{
	sf::Vector2f rec_pos = m_Rect.getPosition();
	sf::Vector2f rec_dim = m_Rect.getSize();

	return (
		mousePos.x >= rec_pos.x && mousePos.x <= rec_pos.x + rec_dim.x &&
		mousePos.y >= rec_pos.y && mousePos.y <= rec_pos.y + rec_dim.y
	);
}
