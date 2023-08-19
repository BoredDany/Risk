//
// Created by Estudiante on 19/08/2023.
//

#ifndef __JUGADOR__H__
#define __JUGADOR__H__
#include <iostream>
#include <list>
#include "Carta.h"

class Jugador{
private:
    int id;
    char * color;
    char * alias;
    int unidades;
    std::list<Carta> cartas;
    char * estado;
public:
    Jugador();
    Jugador (int id, const char * color, const char * alias,
             int unidades,std::list<Carta> cartas);
    void setId(int idN);
    void setColor(const char * color);
    void setAlias(const char * aliasN);
    void setUnidades(int unidadesN);
    void setCartas(std::list<Carta> cartasN);
    void setEstado(const char * EstadoN);

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
