#include "Block.h"

void Block::Draw(sf::RenderWindow& window) const
{
	window.draw(m_Rect);
}