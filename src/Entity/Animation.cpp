#include "Animation.h"

namespace animation
{
	Animation::Animation()
	{
	
	}

	void Animation::AddFrame(float xPosition, float yPosition, float frameWidth, float frameHeight, float spriteWidth, float spriteHeight, float durationTime)
	{
		animationDuration = durationTime;
		currentTime = 0;
		currentFrame = 0;
		Frame frame;

		frame.uvArray[0].u = xPosition / spriteWidth;
		frame.uvArray[0].v = yPosition / spriteHeight;

		frame.uvArray[1].u = (xPosition + frameWidth) / spriteWidth;
		frame.uvArray[1].v = yPosition / spriteHeight;

		frame.uvArray[2].u = xPosition / spriteWidth;
		frame.uvArray[2].v = (yPosition + frameHeight) / spriteHeight;

		frame.uvArray[3].u = (xPosition + frameWidth) / spriteWidth;
		frame.uvArray[3].v = (yPosition + frameHeight) / spriteHeight;

		frames.push_back(frame);
	}

	void Animation::AddFrame(float xPosition, float yPosition, float frameWidth, float frameHeight, float spriteWidth, float spriteHeight, float durationTime, int frameCount)
	{
		animationDuration = durationTime;
		currentTime = 0;
		currentFrame = 0;
		int xCurrentFrame = 0;

		for (int i = 0; i < frameCount; i++)
		{
			Frame frame;

			frame.uvArray[0].u = (xPosition + xCurrentFrame) / spriteWidth;
			frame.uvArray[0].v = yPosition / spriteHeight;

			frame.uvArray[1].u = (xPosition + frameWidth + xCurrentFrame) / spriteWidth;
			frame.uvArray[1].v = yPosition / spriteHeight;

			frame.uvArray[2].u = (xPosition + xCurrentFrame) / spriteWidth;
			frame.uvArray[2].v = yPosition + frameHeight / spriteHeight;

			frame.uvArray[3].u = (xPosition + frameWidth + xCurrentFrame) / spriteWidth;
			frame.uvArray[3].v = (yPosition + frameHeight) / spriteHeight;

			frames.push_back(frame);
			xCurrentFrame += frameWidth;
		}
	}

	void Animation::UpdateAnimation()
	{
		currentTime += Time::GetDeltaTime() * 1000;

		while (currentTime > animationDuration)
		{
			currentTime -= animationDuration;
		}

		float frameLength = animationDuration / frames.size();
		currentFrame = static_cast<int>(currentTime / frameLength);
	}

	int Animation::GetCurrentFrame()
	{
		return currentFrame;
	}

	vector<Frame> Animation::GetFrames()
	{
		return frames;
	}
}