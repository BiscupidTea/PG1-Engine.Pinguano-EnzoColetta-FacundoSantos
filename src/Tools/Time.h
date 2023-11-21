#pragma once
#include "GLFW/glfw3.h"

class Time
{
private:
	static float deltaTime;
	static double lastDeltaTime;

public:

	Time();
	static void Update(float currentTime);
	static float GetDeltaTime();
};

