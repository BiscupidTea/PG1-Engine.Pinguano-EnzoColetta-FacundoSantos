#pragma once
#include "Window.h"
#include "dll-Exp-Inp.h"


class EXPORT InputSystem
{
private:
	GLFWwindow* window;
public:
	enum KeyCode
	{
		q = GLFW_KEY_Q,
		w = GLFW_KEY_W,
		e = GLFW_KEY_E,
		r = GLFW_KEY_R,
		t = GLFW_KEY_T,
		y = GLFW_KEY_Y,
		u = GLFW_KEY_U,
		i = GLFW_KEY_I,
		o = GLFW_KEY_O,
		p = GLFW_KEY_P,
		a = GLFW_KEY_A,
		s = GLFW_KEY_S,
		d = GLFW_KEY_D,
		f = GLFW_KEY_F,
		g = GLFW_KEY_G,
		h = GLFW_KEY_H,
		j = GLFW_KEY_J,
		k = GLFW_KEY_K,
		l = GLFW_KEY_L,
		z = GLFW_KEY_Z,
		x = GLFW_KEY_X,
		c = GLFW_KEY_C,
		v = GLFW_KEY_V,
		b = GLFW_KEY_B,
		n = GLFW_KEY_N,
		m = GLFW_KEY_M,
	};

	enum Action
	{
		Pressed = GLFW_PRESS,
		Reapeated = GLFW_REPEAT,
		Released = GLFW_RELEASE,
	};

	InputSystem(GLFWwindow* window);

	bool getKey(KeyCode key, Action keyAction);
};

