#include "Carta.h"
#include <cstring>

Carta::Carta(int terr, char * fig, char * cont, char * pai) {
    this->territorio = terr;
    this->figura = new char[strlen(fig)+1];
    strcpy(this->figura, fig);
    this->continente = new char [strlen(cont)+1];
    strcpy(this->continente, cont);
    this->pais = new char[strlen(pai)+1];
    strcpy(this->pais, pai);
}

int Carta::getTerritorio(){
    return territorio;
};
char *Carta::getFigura() {
    return figura;
}

char * Carta::getPais(){
    return pais;
};

char *Carta::getContinente() {
    return continente;
}