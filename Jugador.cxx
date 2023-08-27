#include "Jugador.h"
#include <cstring>

Jugador::Jugador(){

}

Jugador::Jugador(int id, std::string color, std::string alias) {
    this->id = id;
    this->color = color;
    this->alias = alias;
    this->unidades = 0;
}

int Jugador::getId() {
    return id;
}

std::string Jugador::getColor() {
    return color;
}

std::string Jugador::getAlias(){
    return alias;
}

int Jugador::getUnidades(){
    return unidades;
}

std::list<Carta> Jugador::getCartas(){
    return cartas;
}

void Jugador::setId(int idN) {
    this->id = idN;
}

void Jugador::setColor(std::string colorN){
    this->color = colorN;
}

void Jugador::setAlias( std::string aliasN){
    this->alias = aliasN;
}

void Jugador::setUnidades(int unidadesN){
    this->unidades = unidadesN;
}

void Jugador::setCartas(std::list<Carta> cartasN){
    this->cartas = cartasN;
}

void Jugador::agregarCarta(Carta carta) {
    cartas.push_back(carta);
}

void Jugador::quitarCarta(int idP) {
    std::list<Carta>::iterator it = cartas.begin();
    std::list<Carta>::iterator itE = cartas.end();
    for(it = cartas.begin();it != cartas.end();it++){
        if(it->getId() == idP){
            itE = it;
            cartas.erase(itE);
        }
    }
}

void Jugador::fortificar(){
    std::cout<< "Vamos a fortificar" << std::endl;
}

void Jugador::reclamarCartas(){
    std::cout<< "Vamos a reclamar cartas" << std::endl;
}
