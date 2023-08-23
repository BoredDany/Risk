#include "Carta.h"
#include <cstring>

Carta::Carta(int terr, std::string fig, std::string cont, std::string pai) {
    this->territorio = terr;
    this->figura = fig;
    this->continente = cont;
    this->pais = pai;
}

int Carta::getTerritorio(){
    return territorio;
};
std::string Carta::getFigura() {
    return figura;
}

std::string Carta::getPais(){
    return pais;
};

std::string Carta::getContinente() {
    return continente;
}