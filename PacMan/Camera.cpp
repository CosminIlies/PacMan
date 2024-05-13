#include "Camera.h"

Camera::Camera(sf::RenderWindow *window):normalView(window->getDefaultView())
{
	position = normalView.getCenter();
	rotation = normalView.getRotation();
	size = normalView.getSize();
}

Camera::~Camera()
{
}

void Camera::update()
{
	normalView.setCenter(position);
	normalView.setRotation(rotation);
	normalView.setSize(size);
}
