#include "Entity.h"

#include "SceneManager.h"




Entity::Entity(Sprite* sprite, const char* name, sf::Vector2f position, float rot, sf::Vector2f scale):name(name), position(position), rotation(rot), scale(scale)
{
	this->sprite = sprite;

	if (this->sprite == nullptr)
		return;
	this->sprite->updateSprite(position, rotation, scale, 0.0f);
}

Entity::Entity(Entity& entity) {
	name = entity.name;
	position = entity.position;
	rotation = entity.rotation;
	scale = entity.scale;
	this->sprite = new Sprite(* entity.sprite);
}

Entity::~Entity()
{
	if (sprite == nullptr)
		return;
	delete sprite;
}

void Entity::update(float deltaTime)
{

	if (sprite == nullptr)
		return;

	sprite->updateSprite(position, rotation, scale, deltaTime);
}

void Entity::draw(sf::RenderWindow* window)
{
	if (sprite == nullptr)
		return;

	window->draw(sprite->sprite);
}
