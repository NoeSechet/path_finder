#include "Board.h"

Board::Board(sf::RenderWindow &window, sf::Vector2u dim = {20, 20}, float offset = 26.0f)
	: m_Win(window), m_Dim(dim), m_Offset(offset)
{
	for (unsigned int i = 0; i < dim.y; i += 1) {
		m_Board.push_back(std::vector<Block>(dim.x));
		for (unsigned int j = 0; j < dim.x; j += 1) {
			m_Board[i][j].SetPosition(sf::Vector2f(i, j), m_Offset);
		}
	}
	m_Board[dim.y / 4][dim.x / 4].SetType(BLOCK_TYPE::START);
	m_Board[dim.y - dim.y / 4][dim.x - dim.x / 4].SetType(BLOCK_TYPE::END);
}

Board::~Board()
{

}

/*
	I could optimize that part (directly get the clicked block
	instead of parsing through all the blocks
*/
void Board::ToggleWall(sf::Vector2i mousePos, bool shiftPressed)
{
	for (auto &line : m_Board) {
		for (Block &block : line) {
			if (block.IsClicked(mousePos) && block.GetType() == BLOCK_TYPE::COMM) {
				block.SetIsWall(shiftPressed);
			}
		}
	}
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