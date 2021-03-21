#include "Application.h"

Application::Application()
{
    
}

bool Application::Init()
{
    m_Win.create(sf::VideoMode(1200, 800), "workshop");
    m_Win.setFramerateLimit(60);

    m_Circle.setRadius(50);
    m_Circle.setFillColor(sf::Color::Blue);
	
    return true;
}

void Application::Run()
{
    float rotAngle = 0.0f;

    while (m_Running)
    {

        while (m_Win.pollEvent(m_Event))
        {
            if (m_Event.type == sf::Event::Closed)
                m_Running = false;
            if (m_Event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                m_Running = false;
            }

        }

        m_Win.clear(sf::Color::Black);

        m_Win.draw(m_Circle);
        m_Win.display();
    }
}