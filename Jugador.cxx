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