#include <iostream>
#include <AnimatedSprite.h>
#include <Player.h>
#include <Input.h>
#include <Debug.h>
#include <SDL.h>
#include <SDL_image.h>
#include "SDLAnimation.h"


using namespace std;

SDLAnimation createAnim(int startPosX, SDL_Renderer* renderer);

int main(int argc, char* argv[])
{


	SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Texture* texture;
	texture = IMG_LoadTexture(renderer, "assets\\grid.png");
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	bool isRunning = true;

	SDLAnimation anim = createAnim(3, renderer);

	Player player("assets\\grid.png", renderer);
	player.setAnimations(createAnim(3, renderer), createAnim(88, renderer), createAnim(173, renderer), createAnim(256, renderer), createAnim(343, renderer));
	Input input;
	
	int frameRate = 10;
	int frameDelay = 1000 / frameRate;
	Uint32 frameStart;
	int frameTime; 

	// Start the game loop
	while (isRunning)
	{
		frameStart = SDL_GetTicks();

		int frame = 0;


		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_UP:
					input.setCurrent(Input::Action::UP);
					break;
				case SDLK_DOWN:
					input.setCurrent(Input::Action::DOWN);
					break;
				case SDLK_RIGHT:
					input.setCurrent(Input::Action::RIGHT);
					break;
				case SDLK_LEFT:
					input.setCurrent(Input::Action::LEFT);
					break;
				case SDLK_SPACE:
					input.setCurrent(Input::Action::SPACE);
					break;
				case SDLK_ESCAPE:
					isRunning = false;
				default:
					break;
				}
				break;

			case SDL_KEYUP:
				break;

			case SDL_QUIT:
				isRunning = false;
				break;

			default:
				break;
			}
		}
		
		player.handleInput(input);
		player.update();

		SDL_RenderClear(renderer);
		player.render(renderer);
		SDL_RenderPresent(renderer);

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return EXIT_SUCCESS;
};

SDLAnimation createAnim(int startPosX, SDL_Renderer* renderer)
{
	SDLAnimation anim("assets\\grid.png", renderer);
	SDL_Rect pos{ 100,100,84,84 };
	anim.setPosition(pos);

	SDL_Rect frame1{ 3,startPosX, 84, 84 };
	SDL_Rect frame2{ 88,startPosX, 84, 84 };
	SDL_Rect frame3{ 173,startPosX, 84, 84 };
	SDL_Rect frame4{ 256,startPosX, 84, 84 };
	SDL_Rect frame5{ 343,startPosX, 84, 84 };
	SDL_Rect frame6{ 428,startPosX, 84, 84 };
	anim.addFrame(frame1);
	anim.addFrame(frame2);
	anim.addFrame(frame3);
	anim.addFrame(frame4);
	anim.addFrame(frame5);
	anim.addFrame(frame6);

	return anim;
}

