#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(){
	m_player.setSize(Vector2f(100,20));
	m_player.setFillColor({128,128,128});
	m_player.setOutlineThickness(1.0f);
	m_player.setOutlineColor({255,255,255});
	m_player.setPosition(400,570);
	
}

void Player::Update(){
	auto p = m_player.getPosition();
	
	if(Keyboard::isKeyPressed(Keyboard::A) or (Keyboard::isKeyPressed(Keyboard::Left))){
		m_player.move(-6,0);
	}
	if((Keyboard::isKeyPressed(Keyboard::D)) or (Keyboard::isKeyPressed(Keyboard::Right))){
		m_player.move(6,0);
	}
	
	LimitesPlayer();
	
	
}

void Player::LimitesPlayer(){
	if(m_player.getPosition().x < 0){
		m_player.setPosition(0, m_player.getPosition().y);
	}else{
		if(m_player.getPosition().x + m_player.getGlobalBounds().width > 800){
			m_player.setPosition(800 - m_player.getGlobalBounds().width, m_player.getPosition().y);
		}
	}
	
}
