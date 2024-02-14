#ifndef BALL_H
#define BALL_H
#include "Object.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class Ball : public Object{
public:
	Ball();
	void Update();
	void Rebotar();
	void IncrementarNivel(int speed);
	void Play();
	void setBallMoving(bool moving);
	int ball_speed();
	bool falling();
private:
	Vector2f m_speed;
	float velocity;
	
	bool ball_moving; bool is_falling;
	
};

#endif

