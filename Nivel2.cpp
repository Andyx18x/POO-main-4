#include "Nivel2.h"
#include "Game.h"
#include "Menu.h"
#include "Nivel3.h"
#include "GameOver.h"
#include "Nivel1.h"

Nivel2::Nivel2(Nivel1 &m_nivel) {
	
	m_ball.IncrementarNivel(4.5f);
	m_ball.setBallMoving(false);
	
	
	m_stats.CargarStats(m_nivel.VerVidas(),m_nivel.VerPuntaje(),m_nivel.VerNivel());
	m_stats.IncrementarNivel();
	
	
	for (int i = 0; i < rowCount; ++i) {
		for (int j = 0; j < columnCount; ++j) {
			if ((i + j) % 2 == 0) { // Se a�aden bloques en posiciones donde la suma de �ndices es par
				float x = j * (blockWidth + 6.f) + 5.f;
				float y = i * (blockHeight + 6.f) + 5.f;
				m_blocks.emplace_back(x, y, blockWidth, blockHeight, Color::Red);
			}
		}
	}
	
}


void Nivel2::Update(Game &g){
	
	
	if(Keyboard::isKeyPressed(Keyboard::Escape)){
		g.SetScene(new Menu());
		m_stats.ResetStats();
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Space)){
		m_ball.setBallMoving(true);
		m_stats.CambiarColores();
		m_stats.draw_text(false);
	}
	
	
	if(m_ball.Colisiona(m_player)){
		m_ball.Rebotar();
	}
	
	for(auto it = m_blocks.begin();it!=m_blocks.end();it++){
		if(m_ball.Colisiona(*it)){
			m_stats.aumentarpuntaje(25);
			m_blocks.erase(it);
			m_ball.Rebotar();
			break;
		}
	}
	
	
	if(m_blocks.empty()){
		g.SetScene(new Nivel3(*this));
		
	}
	
	if(m_ball.falling()){
		m_stats.decrementar_vidas(1);
	}
	
	if(m_stats.VerVidas() == 0){
		m_stats.GuardarScore(VerPuntaje());
		g.SetScene(new GameOver());
	}
	
	m_stats.actualizarStats();
	m_ball.Update();
	m_player.Update();
	
}

void Nivel2::Draw(RenderWindow &w){
	w.clear({0,0,0});
	m_ball.Draw(w);
	m_player.Draw(w);
	
	m_stats.DrawStats(w);
	
	for(auto &bloque : m_blocks){
		bloque.Draw(w);
	}
}

int Nivel2::VerPuntaje(){
	return m_stats.MostrarPuntajeTotal();
}
int Nivel2::VerNivel(){
	return m_stats.ObtenerNivel();
}
int Nivel2::speed_ball(){
	return m_ball.ball_speed();
}

int Nivel2::VerVidas(){
	return m_stats.VerVidas();
}
