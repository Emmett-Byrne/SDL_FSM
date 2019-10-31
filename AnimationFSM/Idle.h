#ifndef IDLE_H
#define IDLE_H

#include <State.h>
#include "SDLAnimation.h"
#include <SDL.h>
#include <SDL_image.h>

class Idle : public State
{
public:
	Idle(SDLAnimation& t_animation) : animation(t_animation) {};
	~Idle() {};
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

#endif // !IDLE_H