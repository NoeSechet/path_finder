#include "Application.h"

Application::Application()
    : m_Board(Board(m_Win, {20, 20}))
{
}

bool Application::Init()
{
    m_Win.create(sf::VideoMode(1920, 1080), "path_finder");
    m_Win.setFramerateLimit(60);
	
    return true;
}

void Application::Run()
{
    while (m_Running)
    {
        m_Win.clear(sf::Color::Black);
        while (m_Win.pollEvent(m_Event))
        {
            if (m_Event.type == sf::Event::Closed)
                m_Running = false;
            if (m_Event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                m_Running = false;
            }
        }
        m_Board.Draw();
        m_Win.display();
    }
}