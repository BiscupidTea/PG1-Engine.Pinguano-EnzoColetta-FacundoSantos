#include "Animation.h"

namespace animation
{
	Animation::Animation(float xPosition, float yPosition, float frameWidth, float frameHeight, float spriteWidth, float spriteHeight, float durationTime)
	{
		animationDuration = durationTime;
		currentTime = time.GetDeltaTime();
		currentFrame = 0;
		Frame frame;

		frame.uvArray[0].u = xPosition / spriteWidth;
		frame.uvArray[0].v = yPosition / spriteHeight;

		frame.uvArray[1].u = xPosition + frameWidth / spriteWidth;
		frame.uvArray[1].v = yPosition / spriteHeight;

		frame.uvArray[2].u = xPosition / spriteWidth;
		frame.uvArray[2].v = yPosition + frameHeight / spriteHeight;

		frame.uvArray[3].u = xPosition + frameWidth / spriteWidth;
		frame.uvArray[3].v = yPosition + frameHeight / spriteHeight;

		frames.push_back(frame);
	}

	Animation::Animation(float xPosition, float yPosition, float frameWidth, float frameHeight, float spriteWidth, float spriteHeight, float durationTime, int frameCount)
	{
		animationDuration = durationTime;
		currentTime = time.GetDeltaTime();
		currentFrame = 0;
		int xCurrentFrame = 0;

		for (int i = 0; i < frameCount; i++)
		{
			Frame frame;

			frame.uvArray[0].u = xPosition + xCurrentFrame / spriteWidth;
			frame.uvArray[0].v = yPosition / spriteHeight;

			frame.uvArray[1].u = xPosition + frameWidth + xCurrentFrame / spriteWidth;
			frame.uvArray[1].v = yPosition / spriteHeight;

			frame.uvArray[2].u = xPosition + xCurrentFrame / spriteWidth;
			frame.uvArray[2].v = yPosition + frameHeight / spriteHeight;

			frame.uvArray[3].u = xPosition + frameWidth + xCurrentFrame / spriteWidth;
			frame.uvArray[3].v = yPosition + frameHeight / spriteHeight;

			frames.push_back(frame);
			xCurrentFrame += spriteWidth;
		}
	}

	void Animation::UpdateAnimation()
	{
		currentTime += time.GetDeltaTime() * 1000;

		if (currentTime > animationDuration)
		{
			currentTime -= animationDuration;
		}

		currentFrame = static_cast<int>(currentTime) / animationDuration;
	}

	Frame Animation::GetCurrentFrame()
	{
		return frames[currentFrame];
	}

	vector<Frame> Animation::GetFrames()
	{
		return frames;
	}
}