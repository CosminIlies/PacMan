#include "SceneManager.h"
SceneManager* SceneManager::_instance = NULL;

void SceneManager::addScene(Scene* scene)
{
	_scenes.push_back(scene);
}

void SceneManager::nextScene()
{
	if (_activeScene <  _scenes.size() - 1) {
		setActiveScene(_activeScene + 1);
	}
}

void SceneManager::previousScene()
{
	if (_activeScene > 0) {
		setActiveScene(_activeScene - 1);
	}
}

void SceneManager::setActiveScene(int sceneNr)
{
	_scenes[_activeScene]->cleanUp();
	_activeScene = sceneNr;
	_scenes[_activeScene]->init();
}

void SceneManager::reloadScene()
{
	setActiveScene(_activeScene);
}

void SceneManager::init()
{
	_scenes[_activeScene]->init();
}

void SceneManager::update(float deltaTime)
{
	_scenes[_activeScene]->update(deltaTime);
}

void SceneManager::draw(sf::RenderWindow* window)
{
	_scenes[_activeScene]->draw(window);
}
