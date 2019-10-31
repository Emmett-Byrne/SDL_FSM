#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Debug.h>

Player::Player(char* texturePath, SDL_Renderer* renderer) : m_idleAnim(texturePath, renderer),
m_climbingAnim(texturePath, renderer),
m_fallingAnim(texturePath, renderer),
m_jumpingAnim(texturePath, renderer),
m_walkingAnim(texturePath, renderer)
{
	m_state.setCurrent(new Idle(m_idleAnim));
	m_state.setPrevious(new Idle(m_idleAnim));
}

Player::~Player() {}

void Player::setAnimations(SDLAnimation idle, SDLAnimation walking, SDLAnimation jumping, SDLAnimation falling, SDLAnimation climbing)
{
	m_idleAnim = idle;
	m_climbingAnim = climbing;
	m_jumpingAnim = jumping;
	m_walkingAnim = walking;
	m_fallingAnim = falling;
}

void Player::handleInput(Input in)
{
	DEBUG_MSG("Handle Input");

	switch (in.getCurrent())
	{
	case Input::Action::SPACE:
		//std::cout << "Player Idling" << std::endl;
		m_state.idle(m_idleAnim);
		break;
	case Input::Action::UP:
		//std::cout << "Player Up" << std::endl;
		m_state.climbing(m_climbingAnim);
		break;
	case Input::Action::DOWN:
		//std::cout << "Player Down" << std::endl;
		m_state.falling(m_fallingAnim);
		break;
	case Input::Action::LEFT:
		//std::cout << "Player Left" << std::endl;
		m_state.jumping(m_jumpingAnim);
		break;
	case Input::Action::RIGHT:
		//std::cout << "Player Right" << std::endl;
		m_state.walking(m_walkingAnim);
		break;
	default:
		break;
	}
}

void Player::update()
{
	m_state.getCurrent()->update();
}

void Player::render(SDL_Renderer* renderer)
{
	m_state.getCurrent()->render(renderer);
}
