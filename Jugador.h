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
    std::string color;
    std::string alias;
    int unidades;
    std::list<Carta> cartas;
    std::string estado;
public:
    Jugador();
    Jugador (int id, std::string color, std::string alias);
    void setId(int idN);
    void setColor(std::string color);
    void setAlias(std::string aliasN);
    void setUnidades(int unidadesN);
    void setCartas(std::list<Carta> cartasN);
    void setEstado(std::string EstadoN);

    void agregarCarta(Carta carta);

    int getId();
    std::string getColor();
    std::string getAlias();
    int getUnidades();
    std::list<Carta> getCartas();
    std::string getEstado();

    void fortificar();
    void atacar();
    void reclamarCartas();

};

#endif
