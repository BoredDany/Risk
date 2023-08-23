#include "Jugador.h"
#include <cstring>

Jugador::Jugador(){

}

Jugador::Jugador(int id, std::string color, std::string alias) {
    this->id = id;
    this->color = color;
    this->alias = alias;
    this->unidades = 0;
    this->estado = "neutro";
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

std::string Jugador::getEstado(){
    return estado;
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

void Jugador::setEstado(std::string estadoN){
    this->estado = estadoN;
}

void Jugador::agregarCarta(Carta carta) {
    cartas.push_back(carta);
}

void Jugador::fortificar(){
    std::cout<< "Vamos a fortificar" << std::endl;
}

void Jugador::atacar(){
    std::cout<< "Vamos a atacar" << std::endl;
}

void Jugador::reclamarCartas(){
    std::cout<< "Vamos a reclamar cartas" << std::endl;
}
