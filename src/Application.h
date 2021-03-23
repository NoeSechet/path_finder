#pragma once
#include <iostream>
#include <fstream>
#include <strstream>
#include <algorithm>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>

#include "board/Board.h"

class Application
{
public:
	Application();
	~Application() {}

	bool Init();
	void Run();

private:
	bool m_Running = true;
	Board m_Board;

	sf::RenderWindow m_Win;
	sf::Event m_Event;

	sf::Clock m_Clock;
	float m_ElapsedTime = 0.0f;

private:
};