#include "Jugador.h"
#include <cstring>

Jugador::Jugador(){

}

Jugador::Jugador(int id, const char *color, const char *alias, int unidades, std::list<Carta> cartas) {
    this->id = id;
    int len_color = strlen(color);
    int len_alias = strlen(alias);
    int len_estado = strlen(estado);
    this->color = new char [len_color+1];
    strcpy(this->color, color);
    this->alias = new char [len_alias+1];
    strcpy(this->alias, alias);
    this->unidades = unidades;
    this->cartas = cartas;
    this->estado = new char [10];
    strcpy(this->estado, "neutro");
}
void Jugador::setId(int idN) {
    this->id = idN;
}

void Jugador::setColor(const char *colorN){
    strcpy(this->color, colorN);
}

void Jugador::setAlias(const char * aliasN){
    strcpy(this->alias, aliasN);
}

void Jugador::setUnidades(int unidadesN){
    this->unidades = unidadesN;
}

void Jugador::setCartas(std::list<Carta> cartasN){
    this->cartas = cartasN;
}

void Jugador::setEstado(const char * estadoN){
    strcpy(this->estado, estadoN);
}

int Jugador::getId() {
    return id;
}

char * Jugador::getColor() {
    return color;
}

char * Jugador::getAlias(){
    return alias;
}

int Jugador::getUnidades(){
    return unidades;
}

std::list<Carta> Jugador::getCartas(){
    return cartas;
}

char * Jugador::getEstado(){
    return estado;
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