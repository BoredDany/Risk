#ifndef __JUGADOR__H__
#define __JUGADOR__H__
#include <iostream>

class Jugador{
	private:
		int id;
		char color[10];
		char alias[20];
		int unidades;
		std::list<Cartas> cartas;
		char estado[10];
	public:
		Jugador();
		void setId(int id);
		void setColor(char color[]);
		void setAlias(char alias[]);
		void setUnidades(int unidades);
		void setCartas(std::list<Cartas> cartas);
		void setEstado(char Estado[]);
		int getId();
		char* getColor();
		char* getAlias();
		int getUnidades();
		std::list<Cartas> getCartas();
		char* getEstado();
		void fortificar();
		void atacar();
		void reclamarCartas(); 

};

#endif