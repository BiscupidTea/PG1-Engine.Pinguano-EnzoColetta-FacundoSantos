#pragma once
#include "Tools/Frame.h"
#include "Tools/Time.h"
#include <iostream>
#include <vector>

using namespace std;

namespace animation
{
	class Animation
	{
	private:
		Time time;
		float animationDuration;
		float currentTime;
		int currentFrame;
		vector<Frame>frames;

	public:

		void AddAnimation(
			float xPosition, float yPosition,
			float frameWidth, float frameHeight,
			float spriteWidth, float spriteHeight,
			float durationTime);

		void AddAnimation(
			float xPosition, float yPosition,
			float frameWidth, float frameHeight,
			float spriteWidth, float spriteHeight,
			float durationTime, int frameCount);

		void UpdateAnimation();

		Frame GetCurrentFrame();

		vector<Frame> GetFrames();
	};
}

