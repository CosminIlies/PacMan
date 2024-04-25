#include "Application.h"


Application::Application(int width, int height, const char* name)
{
	_window = new sf::RenderWindow(sf::VideoMode(width, height), name);
    sceneManager = SceneManager::getInstance();
    sceneManager->addScene(new TestScene1(_window));
    sceneManager->addScene(new TestScene2(_window));

    sceneManager->init();
}

Application::~Application()
{
}

void Application::start()
{
    float deltaTime = 0;
    float oldTime = 0;
    
    while (_window->isOpen())
    {


        sf::Event event;
        while (_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window->close();
        }

        _window->clear();
        _window->setView(sceneManager->getActiveScene()->getCamera()->view);

        sceneManager->update(deltaTime);
        sceneManager->draw(_window);
        
        _window->display();

        deltaTime = clock() - oldTime;
        oldTime = clock();
    }
}
