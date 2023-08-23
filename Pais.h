//
// Created by Estudiante on 23/08/2023.
//

#ifndef RISK_TERRITORIO_H
#define RISK_TERRITORIO_H

class Pais{
private:
    int id;
    char * nombre;
    char * continente;
    int unidades;
    int id_jugador;
public:
    Pais(int id, char * nombre, char * continente);
    int get_id();
    char * get_nombre();
    char * get_continente();
    int get_unidades();
    int get_id_jugador();
    void set_unidades(int unidades);
    void set_id_jugador(int id_jugador);
};
#endif //RISK_TERRITORIO_H
