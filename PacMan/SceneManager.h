#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Scene.h"

class SceneManager
{
private:
	static SceneManager* _instance;
	SceneManager() {}

public:
	SceneManager(const SceneManager &obj) = delete;
    static SceneManager* getInstance()
    {
        if (_instance == NULL)
        {
            _instance = new SceneManager();
            return _instance;
        }
        else
        {
            return _instance;
        }
    }

	void addScene(Scene* scene);
	void nextScene();
	void previousScene();
	void setActiveScene(int sceneNr);
	void reloadScene();

	void init();
	void update(float deltaTime);
	void draw(sf::RenderWindow* window);
private:
	std::vector<Scene*> _scenes;
	int _activeScene = 0;
};

