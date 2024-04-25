#include "Camera.h"

Camera::Camera(sf::RenderWindow *window):view(window->getDefaultView())
{
	position = view.getCenter();
	rotation = view.getRotation();
	size = view.getSize();
}

Camera::~Camera()
{
}

void Camera::update()
{
	view.setCenter(position);
	view.setRotation(rotation);
	view.setSize(size);
}
