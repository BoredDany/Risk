//
// Created by Estudiante on 23/08/2023.
//
#include <cstring>
#include "Pais.h"

Pais::Pais(int id, char *nombre, char *continente) {
    this->id = id;
    this->nombre = new char [strlen(nombre)+1];
    strcpy(this->nombre,nombre);
    this->continente = new char [strlen(continente)+1];
    strcpy(this->continente,continente);
}

int Pais::get_id() {
    return id;
}

char * Pais::get_nombre() {
    return nombre;
}

char * Pais::get_continente() {
    return continente;
}

int Pais::get_unidades() {
    return unidades;
}

int Pais::get_id_jugador() {
    return id_jugador;
}

void Pais::set_unidades(int unidades) {
    this->unidades = unidades;
}

void Pais::set_id_jugador(int id_jugador) {
    this->id_jugador = id_jugador;
}