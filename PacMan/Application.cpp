#include "Application.h"


Application::Application(int width, int height, const char* name)
{
	_window = new sf::RenderWindow(sf::VideoMode(width, height), name);
    sceneManager = SceneManager::getInstance();
    sceneManager->addScene(new TestScene1());
    sceneManager->addScene(new TestScene2());

    sceneManager->init();
}

Application::~Application()
{
}

void Application::start()
{
    while (_window->isOpen())
    {
        sf::Event event;
        while (_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window->close();
        }

        _window->clear();

        sceneManager->update(1.0);// TODO: deltaTime
        sceneManager->draw(_window);

        _window->display();
    }
}
