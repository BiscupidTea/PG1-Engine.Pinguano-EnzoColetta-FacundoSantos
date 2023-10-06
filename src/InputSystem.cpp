#include "InputSystem.h"

InputSystem::InputSystem(GLFWwindow* window)
{
	this->window = window;
}

bool InputSystem::getKey(KeyCode key, Action keyAction)
{
	int state;

	switch (keyAction)
	{
	case InputSystem::Pressed:
		state = glfwGetKey(window, key);
		return state == Action::Pressed;
		break;

	case InputSystem::Reapeated:
		state = glfwGetKey(window, key);
		return state == Action::Reapeated;
		break;

	case InputSystem::Released:
		state = glfwGetKey(window, key);
		return state == Action::Released;
		break;
	default:
		return false;
		break;
	}
	return false;
}