#include "SDLAnimation.h"

SDLAnimation::SDLAnimation(char* texturePath, SDL_Renderer* renderer) :
	currentFrame(0)
{
	texture = IMG_LoadTexture(renderer, texturePath);
}

void SDLAnimation::setPosition(SDL_Rect pos)
{
	position = pos;
}

void SDLAnimation::addFrame(SDL_Rect frame)
{
	frameList.push_back(frame);
}

void SDLAnimation::setFrame(int frameID)
{
	currentFrame = frameID;
}

void SDLAnimation::nextFrame()
{
	currentFrame++;
	if (currentFrame >= frameList.size())
	{
		currentFrame = 0;
	}
}

void SDLAnimation::render(SDL_Renderer* renderer)
{
	if (frameList.size() > 0)
	{
		SDL_RenderCopy(renderer, texture, & frameList.at(currentFrame), & position);
	}
}
