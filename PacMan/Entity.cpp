#include "Entity.h"

#include "SceneManager.h"


Entity::Entity(const char * texturePath, const char* name):name(name), position(sf::Vector2f(0, 0)), rotation(0), scale(sf::Vector2f(1,1))
{

	if (!_texture.loadFromFile(texturePath))
	{
		LOG_ERROR("Texture not loaded");
	}

	_sprite.setTexture(_texture);
	_sprite.setPosition(position);
	_sprite.setRotation(rotation);
	_sprite.setScale(scale);
	_sprite.setOrigin(sf::Vector2f(_texture.getSize().x / 2.0f, _texture.getSize().y / 2.0f));
}

Entity::Entity(const char* texturePath, const char* name, sf::Vector2f position, float rot, sf::Vector2f scale):name(name), position(position), rotation(rot), scale(scale)
{
	if (!_texture.loadFromFile(texturePath))
	{
		LOG_ERROR("Texture not loaded");
	}

	_sprite.setTexture(_texture);
	_sprite.setPosition(position);
	_sprite.setRotation(rotation);
	_sprite.setScale(scale);
}

Entity::~Entity()
{
}

void Entity::update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
		LOG_TRACE("Prev Scene");
		SceneManager::getInstance()->previousScene();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
		LOG_INFO("Next Scene");
		SceneManager::getInstance()->nextScene();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
		LOG_WARNING("Next Scene");

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
		LOG_ERROR("Next Scene");
	}


	updateTransformations();
}

void Entity::draw(sf::RenderWindow* window)
{
	window->draw(_sprite);
}
