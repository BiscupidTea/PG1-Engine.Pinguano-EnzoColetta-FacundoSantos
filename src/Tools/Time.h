#pragma once
#include "GLFW/glfw3.h"

class Time
{
private:
	float deltaTime = 0;

public:

	Time();
	float GetDeltaTime();
};

