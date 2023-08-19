#include "Carta.h"
#include <cstring>

Carta::Carta(int terr, const char * fig, const char * pai) {
    int long_fig = strlen(fig);
    int long_pai = strlen(pai);
    this->territorio = terr;
    this->figura = new char[long_fig+1];
    strcpy(this->figura, fig);
    this->pais = new char [long_pai+1];
    strcpy(this->pais, pai);
}

char *Carta::getFigura() {
    return figura;
}

char *Carta::getPais() {
    return pais;
}

int Carta::getTerritorio() {
    return territorio;
}