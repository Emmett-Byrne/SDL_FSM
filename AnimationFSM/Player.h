#ifndef PLAYER_H
#define PLAYER_H

#include <Input.h>
#include <PlayerFSM.h>
#include "SDLAnimation.h"

class Player
{
private:
	PlayerFSM m_state;
	SDLAnimation* m_currentAnimation;
	SDLAnimation m_idleAnim;
	SDLAnimation m_climbingAnim;
	SDLAnimation m_jumpingAnim;
	SDLAnimation m_walkingAnim;
	SDLAnimation m_fallingAnim;
	Player();

public:
	Player(char* texturePath, SDL_Renderer* renderer);
	~Player();
	void setAnimations(SDLAnimation idle, SDLAnimation climbing, SDLAnimation jumping, SDLAnimation running, SDLAnimation falling);
	void handleInput(Input);
	void update();
	void render(SDL_Renderer* renderer);
};

#endif // !PLAYER_H
