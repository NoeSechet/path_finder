#include "Board.h"

Board::Board(sf::RenderWindow &window, sf::Vector2u dim = {10, 10})
	: m_Win(window), m_Dim(dim)
{
	for (unsigned int i = 0; i < dim.y; i += 1) {
		m_Board.push_back(std::vector<Block>(dim.x));
		for (unsigned int j = 0; j < dim.x; j += 1) {
			m_Board[i][j].SetPosition(sf::Vector2f(i, j));
		}
	}
}

Board::~Board()
{

}

void Board::Draw() const
{
	for (auto line : m_Board) {
		for (Block block : line) {
			block.Draw(m_Win);
		}
	}
}

void Board::PrintBoard() const
{
	for (auto line : m_Board) {
		for (Block block : line)
			std::cout << block.GetStatus() << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}