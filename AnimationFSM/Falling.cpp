#include <Idle.h>
#include <Jumping.h>
#include <Climbing.h>
#include <Falling.h>
#include <Walking.h>

void Falling::handleInput() {}
void Falling::update()
{
	animation.nextFrame();
}

void Falling::render(SDL_Renderer* renderer)
{
	animation.render(renderer);
}

void Falling::idle(PlayerFSM* a, SDLAnimation& t_animation)
{
	std::cout << "Falling -> Idle" << std::endl;
	a->setCurrent(new Idle(t_animation));
	delete this;
}

void Falling::jumping(PlayerFSM* a, SDLAnimation& t_animation)
{
}

void Falling::climbing(PlayerFSM* a, SDLAnimation& t_animation)
{
}

void Falling::falling(PlayerFSM* a, SDLAnimation& t_animation)
{
}

void Falling::walking(PlayerFSM* a, SDLAnimation& t_animation)
{
	std::cout << "Falling -> Walking" << std::endl;
	a->setCurrent(new Walking(t_animation));
	delete this;
}
