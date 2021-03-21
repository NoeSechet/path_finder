#pragma once
#include <iostream>
#include <fstream>
#include <strstream>
#include <algorithm>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>


class Application
{
public:
	Application();
	~Application() {}

	bool Init();
	void Run();

private:
	bool m_Running = true;

	sf::RenderWindow m_Win;
	sf::CircleShape m_Circle;
	sf::Event m_Event;

	sf::Clock m_Clock;
	float m_ElapsedTime = 0.0f;

private:
};