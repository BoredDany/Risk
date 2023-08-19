#ifndef __JUGADOR__H__
#define __JUGADOR__H__
#include <iostream>

class Jugador{
	private:
		int id;
		char color[10];
		char alias[20];
		int unidades;
		std::list<Carta> cartas;
		char estado[10];
	public:
		Jugador();
		void setId(int idN);
		void setColor(char colorN[]);
		void setAlias(char aliasN[]);
		void setUnidades(int unidadesN);
		void setCartas(std::list<Carta> cartasN);
		void setEstado(char EstadoN[]);
		int getId();
		char* getColor();
		char* getAlias();
		int getUnidades();
		std::list<Carta> getCartas();
		char* getEstado();
		void fortificar();
		void atacar();
		void reclamarCartas(); 

};

#endif