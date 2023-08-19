#include "Jugador.h"
#include <cstring>

Jugador::Jugador(){

}

Jugador::setId(int idN){
	this->id = idN;
}

Jugador::setColor(char colorN[]){
	strcpy(this->color, colorN);
}

Jugador::setAlias(char aliasN[]){
	strcpy(this->alias, aliasN);
}

Jugador::setUnidades(int unidadesN){
	this->unidades = unidadesN;
}

Jugador::setCartas(std::list<Cartas> cartasN){
	std::list<Cartas>::iterator itCartasN = cartasN.begin();
	std::list<Cartas>::iterator itCartas = this->cartas.begin();
	for(;itCartas!=cartas.end();itCartas++){
		*itCartas = *itCartasN;
		itCartasN++;
	}
}

Jugador::setEstado(char estadoN[]){
	strcpy(this->estado, estadoN);
}

Jugador::getId(){
	return id;
}

Jugador::getColor(){
	return color;
}

Jugador::getAlias(){
	return alias;
}

Jugador::getUnidades(){
	return unidades;
}

Jugador::getCartas(){
	return cartas;
}

Jugador::getEstado(){
	return estado;
}

Jugador::fortificar(){
	std::cout<< "Vamos a fortificar" << std::endl;
}

Jugador::atacar(){
	std::cout<< "Vamos a atacar" << std::endl;
}

Jugador::reclamarCartas(){
	std::cout<< "Vamos a reclamar cartas" << std::endl;
}
