#include <Idle.h>
#include <Jumping.h>
#include <Climbing.h>
#include <Falling.h>
#include <Walking.h>

#include <string>

void Climbing::update()
{
	animation.nextFrame();
}

void Climbing::render(SDL_Renderer* renderer)
{
	animation.render(renderer);
}

void Climbing::idle(PlayerFSM* a, SDLAnimation& t_animation)
{
	std::cout << "Climbing -> Idle" << std::endl;
	a->setCurrent(new Idle(t_animation));
	delete this;
}
void Climbing::jumping(PlayerFSM* a, SDLAnimation& t_animation)
{
}

void Climbing::climbing(PlayerFSM* a, SDLAnimation& t_animation)
{
}

void Climbing::falling(PlayerFSM* a, SDLAnimation& t_animation)
{
	std::cout << "Climbing -> Falling" << std::endl;
	a->setCurrent(new Falling(t_animation));
	delete this;
}

void Climbing::walking(PlayerFSM* a, SDLAnimation& t_animation)
{
}
