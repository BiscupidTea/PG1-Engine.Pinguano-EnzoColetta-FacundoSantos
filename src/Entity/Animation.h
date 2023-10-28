#pragma once
#include "Tools/Frame.h"
#include "Tools/Time.h"
#include "Tools/dll-Exp-Inp.h"
#include <iostream>
#include <vector>

using namespace frame;
using namespace std;

namespace animation
{
	class EXPORT Animation
	{
	private:
		Time time;
		float animationDuration;
		float currentTime;
		int currentFrame;
		vector<Frame>frames;

	public:

		Animation();

		void AddFrame(
			float xPosition, float yPosition,
			float frameWidth, float frameHeight,
			float spriteWidth, float spriteHeight,
			float durationTime);

		void AddFrame(
			float xPosition, float yPosition,
			float frameWidth, float frameHeight,
			float spriteWidth, float spriteHeight,
			float durationTime, int frameCount);

		void UpdateAnimation();

		Frame GetCurrentFrame();

		vector<Frame> GetFrames();
	};
}

