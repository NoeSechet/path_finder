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

void Block::SetType(BLOCK_TYPE type)
{
	switch (type) {
		case BLOCK_TYPE::COMM: m_Rect.setFillColor(sf::Color::White); break;
		case BLOCK_TYPE::START: m_Rect.setFillColor(sf::Color::Blue); break;
		case BLOCK_TYPE::END: m_Rect.setFillColor(sf::Color::Magenta); break;
		default: m_Rect.setFillColor(sf::Color::White); break;
	}
	m_Type = type;
}
