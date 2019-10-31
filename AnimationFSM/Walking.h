#pragma once
#include "State.h"
#include "SDLAnimation.h"
class Walking :	public State
{
public:
	Walking(SDLAnimation& t_animation) : animation(t_animation) {};
	void handleInput();
	void update();
	void render(SDL_Renderer* renderer);
	void idle(PlayerFSM* a, SDLAnimation& t_animation);
	void jumping(PlayerFSM* a, SDLAnimation& t_animation);
	void climbing(PlayerFSM* a, SDLAnimation& t_animation);
	void falling(PlayerFSM* a, SDLAnimation& t_animation);
	void walking(PlayerFSM* a, SDLAnimation& t_animation);

private:
	SDLAnimation& animation;
};

