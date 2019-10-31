#include <Idle.h>
#include <Jumping.h>
#include <Climbing.h>
#include <Falling.h>
#include <Walking.h>

#include <string>

void Idle::handleInput() {}
void Idle::update() 
{
	animation.nextFrame();
}

void Idle::render(SDL_Renderer* renderer)
{
	animation.render(renderer);
}


void Idle::idle(PlayerFSM* a, SDLAnimation& t_animation)
{
}

void Idle::jumping(PlayerFSM* a, SDLAnimation& t_animation)
{
	std::cout << "Idle -> Jumping" << std::endl;
	a->setCurrent(new Jumping(t_animation));
	delete this;
}
void Idle::climbing(PlayerFSM* a, SDLAnimation& t_animation)
{
	std::cout << "Idle -> Climbing" << std::endl;
	a->setCurrent(new Climbing(t_animation));
	delete this;
}

void Idle::falling(PlayerFSM* a, SDLAnimation& t_animation)
{
}

void Idle::walking(PlayerFSM* a, SDLAnimation& t_animation)
{
	std::cout << "Idle -> Walking" << std::endl;
	a->setCurrent(new Walking(t_animation));
	delete this;
}
