#include "Time.h"

float Time::deltaTime = 0;
double Time::lastDeltaTime = glfwGetTime();

Time::Time()
{
	lastDeltaTime = 0;
}

void Time::Update(float currentTime)
{
	deltaTime = currentTime - lastDeltaTime;
	lastDeltaTime = currentTime;
}

float Time::GetDeltaTime()
{
	return deltaTime;
}