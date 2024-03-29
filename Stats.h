#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


using namespace sf;

class Stats {
public:
	Stats();
	void aumentarpuntaje(int puntos);
	int obtenerpuntaje();
	int MostrarPuntajeTotal();
	void actualizarStats();
	void DrawStats(RenderWindow &w);
	void IncrementarNivel();
	int ObtenerNivel();
	void CambiarColores();
	void ResetStats();
	void decrementar_vidas(int m_v);
	bool draw_text(bool dr);
	int VerVidas();
	void CargarVidas(int vidas);
	
	void CargarStats(int vidas, int puntaje, int nivel);
	void GuardarScore(int puntos);
	
protected:
	
	int m_nivel = 1, PuntajeTotal = 0,  m_vidas = 2;
	Font m_font; bool is_draw;
	
	Text score_text; Text txt_vidas;
	Text nivel_game;
	Text comenzar_jugar;
};

#endif

