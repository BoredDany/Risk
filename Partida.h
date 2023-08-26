//
// Created by Estudiante on 25/08/2023.
//

#ifndef RISK_PARTIDA_H
#define RISK_PARTIDA_H

#include "Continente.h"
#include "Carta.h"
#include "Jugador.h"
#include<list>
#include<vector>

class Partida{
private:
    int id;
    std::vector<Jugador> jugadores;
    std::list<Carta> cartas;
    std::list<Continente> tablero;
public:
    Partida(int id);
    std::vector<Jugador> get_jugadores();
    std::list<Carta> get_cartas();
    std::list<Continente> get_tablero();
    void set_id(int id);
    int countLines(std::string archivo_cartas);
    void cargarCartas(std::string archivo_cartas);
    bool buscarColorRepetido (std::string color);
    void asignarUnidades();
    void inicializarJugadores();
    bool repetido(std::string nombre);
    void inicializarTablero();
    void llenarContinentes();
    void aggConexion(int pais, int vecino);
    void cargarConexiones(std::string archivo);
    bool tableroLleno();
    bool paisLleno(int id);
    void ocuparPais(int id, int idPais);
    Carta obtenerCarta(int idPais);
    void ubicarUnidades(bool& inicializado);
    void mostrarInicializacion();
};
#endif //RISK_PARTIDA_H
