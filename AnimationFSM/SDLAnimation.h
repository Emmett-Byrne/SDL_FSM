#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <string>

class SDLAnimation
{
public:
	SDLAnimation(char* texturePath, SDL_Renderer* renderer);
	void setPosition(SDL_Rect pos);
	void addFrame(SDL_Rect frame);
	void setFrame(int frameID);
	void nextFrame();
	void render(SDL_Renderer* renderer);

private: 
	SDL_Texture* texture;
	SDL_Rect position;
	std::vector<SDL_Rect> frameList;
	int currentFrame;
};

