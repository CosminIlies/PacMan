#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"Entity.h"

class Scene {
public:

	virtual void init() = 0;
	void update(float deltaTime) {
		for (Entity *entity: _entities) {
			entity->update(deltaTime);
		}
	} 
	void draw(sf::RenderWindow* window) {
		for (Entity* entity : _entities) {
			entity->draw(window);
		}
	}
	virtual void cleanUp() = 0;

protected:

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

	std::vector<Entity*> _entities;

};