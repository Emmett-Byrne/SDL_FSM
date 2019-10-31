#include <Idle.h>
#include <Jumping.h>
#include <Climbing.h>
#include <Falling.h>
#include <Walking.h>

void Walking::handleInput() {}
void Walking::update() 
{
	animation.nextFrame();
}

void Walking::render(SDL_Renderer* renderer)
{
	animation.render(renderer);
}

void Walking::idle(PlayerFSM* a, SDLAnimation& t_animation)
{
	std::cout << "Walking -> Idle" << std::endl;
	a->setCurrent(new Idle(t_animation));
	delete this;
}

void Walking::jumping(PlayerFSM* a, SDLAnimation& t_animation)
{
}

void Walking::climbing(PlayerFSM* a, SDLAnimation& t_animation)
{
}

void Walking::falling(PlayerFSM* a, SDLAnimation& t_animation)
{
}

void Walking::walking(PlayerFSM* a, SDLAnimation& t_animation)
{
}
