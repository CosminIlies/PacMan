#include "Application.h"


Application::Application(int width, int height, const char* name)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), name);
    sceneManager = SceneManager::getInstance();
    sceneManager->addScene(new MainMenu(window));
    sceneManager->addScene(new TestScene1(window));
    sceneManager->addScene(new GameOver(window));

    sceneManager->init();
}
Application* Application::instance = nullptr;

void Application::init(int width, int height, const char* name)
{
    instance = new Application(width, height, name);
}

Application* Application::getInstance()
{
    return instance;
}

Application::~Application()
{
}

void Application::start()
{
    float deltaTime = 0;
    float oldTime = 0;

    while (window->isOpen())
    {


        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        window->setView(sceneManager->getActiveScene()->getCamera()->normalView);

        sceneManager->update(deltaTime);
        sceneManager->draw(window);
        
        window->display();

        deltaTime = clock() - oldTime;
        oldTime = clock();
    }
}

void Application::stop()
{
    window->close();
}
