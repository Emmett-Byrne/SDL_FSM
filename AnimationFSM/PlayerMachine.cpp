#include <PlayerFSM.h>
#include <Idle.h>

PlayerFSM::PlayerFSM()
{
}

PlayerFSM::~PlayerFSM() {}

void PlayerFSM::setCurrent(State* s)
{
	m_current = s;
}

State* PlayerFSM::getCurrent()
{
	return m_current;
}

void PlayerFSM::setPrevious(State* s)
{
	m_previous = s;
}

State* PlayerFSM::getPrevious()
{
	return m_previous;
}

void PlayerFSM::idle(SDLAnimation& t_animation)
{
	m_current->idle(this, t_animation);
}

void PlayerFSM::jumping(SDLAnimation& t_animation)
{
	m_current->jumping(this, t_animation);
}

void PlayerFSM::climbing(SDLAnimation& t_animation)
{
	m_current->climbing(this, t_animation);
}

void PlayerFSM::falling(SDLAnimation& t_animation)
{
	m_current->falling(this, t_animation);
}

void PlayerFSM::walking(SDLAnimation& t_animation)
{
	m_current->walking(this, t_animation);
}
