#include <Idle.h>
#include <Jumping.h>
#include <Climbing.h>
#include <Falling.h>
#include <Walking.h>

#include <string>

void Jumping::update()
{
	animation.nextFrame();
}

void Jumping::render(SDL_Renderer* renderer)
{
	animation.render(renderer);
}

void Jumping::idle(PlayerFSM* a, SDLAnimation& t_animation)
{
}
void Jumping::jumping(PlayerFSM* a, SDLAnimation& t_animation)
{
}
void Jumping::climbing(PlayerFSM* a, SDLAnimation& t_animation)
{
	std::cout << "Jumping -> Climbing" << std::endl;
	a->setCurrent(new Climbing(t_animation));
	delete this;
}

void Jumping::falling(PlayerFSM* a, SDLAnimation& t_animation)
{
	std::cout << "Jumping -> Falling" << std::endl;
	a->setCurrent(new Falling(t_animation));
	delete this;
}

void Jumping::walking(PlayerFSM* a, SDLAnimation& t_animation)
{
}
