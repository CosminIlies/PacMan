#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"Entity.h"
#include "Camera.h"

class Scene {
public:
	Scene(sf::RenderWindow* window) { _camera = new Camera(window); }

	virtual void init() = 0;
	void update(float deltaTime) {
		for (Entity *entity: _entities) {
			bool sceenChanged = entity->update(deltaTime);
			if (sceenChanged) {
				return;
			}
		}
		_camera->update();
	} 
	void draw(sf::RenderWindow* window) {
		for (Entity* entity : _entities) {
			entity->draw(window);
		}
	}
	virtual void cleanUp(){
		for (Entity* entity : _entities) {
			delete entity;
		}
		_entities.clear();
		delete _camera;
	}

	inline Camera* getCamera() {
		return _camera;
	}

	void addEntity(Entity* entity) {
		_entities.push_back(entity);
	}
	void removeEntity(Entity* entity) {
		for (int i = 0; i < _entities.size(); i++) {
			if (_entities[i] == entity) {
				_entities.erase(_entities.begin() + 1);
				return;
			}
		}
	}
	Entity* getEntityByName(const char* name) {
		for (Entity *entity : _entities) {
			if (entity->name == name) {
				return entity;
			}
		}
	}
protected:
	std::vector<Entity*> _entities;
	Camera* _camera;

};