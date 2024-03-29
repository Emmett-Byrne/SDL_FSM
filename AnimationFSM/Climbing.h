#ifndef CLIMBING_H
#define CLIMBING_H

#include <State.h>
#include "SDLAnimation.h"

class Climbing : public State
{
public:
	Climbing(SDLAnimation& t_animation) : animation(t_animation) {};
	~Climbing() {};
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