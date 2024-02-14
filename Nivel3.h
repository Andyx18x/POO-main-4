#ifndef NIVEL3_H
#define NIVEL3_H
#include "Player.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.h"
#include "Nivel.h"
#include "Nivel2.h"

class Nivel3 : public Nivel{
public:
	Nivel3(Nivel2 &m_nivel);
	void Draw(RenderWindow &w) override;
	void Update(Game &g) override;
	
private:
};

#endif

