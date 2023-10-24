#include "Time.h"

Time::Time()
{
	deltaTime = glfwGetTime();
}

float Time::GetDeltaTime()
{
	return glfwGetTime();
}