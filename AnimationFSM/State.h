#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <typeinfo>

#include <Input.h>
#include <PlayerFSM.h>
#include <Debug.h>
#include <SDLAnimation.h>

class State
{
public:
	virtual void handleInput() {}

	virtual void update() {}

	virtual void render(SDL_Renderer* renderer) {};

	virtual void idle(PlayerFSM* a, SDLAnimation& t_animation)
	{
		DEBUG_MSG("State::Idling");
	}
	virtual void jumping(PlayerFSM* a, SDLAnimation& t_animation)
	{
		DEBUG_MSG("State::Jumping");
	}
	virtual void climbing(PlayerFSM* a, SDLAnimation& t_animation)
	{
		DEBUG_MSG("State::Climbing");
	}
	virtual void falling(PlayerFSM* a, SDLAnimation& t_animation)
	{
		DEBUG_MSG("State::Climbing");
	}
	virtual void walking(PlayerFSM* a, SDLAnimation& t_animation)
	{
		DEBUG_MSG("State::Climbing");
	}
};

#endif // ! ANIMATION_H

