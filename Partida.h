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

    bool paisExiste(int idP);
    bool jugadorOcupaPais(int idJ, int idP);
    bool paisVecino(int paisOrigen, int paisDestino);
    void elegirUbicacionAtaque(int posJug, int * paisOrigen, int * paisDestino);

    int buscarAtacado(int idP);
    int lanzarDados(int numDados);
    bool quitarUnidad(int idP);
    void atacar(int posAtacante, int origen, int destino);

    int calcularPaises(int idJ);
    void intercambioNormal(int posJ);
    void intercambioPorPaises(int posJ);
    bool intercambioPorCartasIguales(int posJ);
    void intercambiarCartas(int posJ, int gana);

    bool unidadesSuficientes(int posJ, int idP, int unidades);
    bool paisFortificable(int idJ, int idP);
    void moverUnidades(int posJ, int origen, int destino, int unidadesM);
    void fortificarTerritorio(int jugadorIndex);
};
#endif //RISK_PARTIDA_H
