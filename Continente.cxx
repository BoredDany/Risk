//
// Created by Estudiante on 23/08/2023.
//
#include "Continente.h"
#include<cstring>

Continente::Continente(char * nombre){
    this->nombre = new char [strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}
char * Continente::get_nombre(){
    return nombre;
}
std::list<Pais> Continente::get_paises(){
    return paises;
}
void Continente::set_nombre(char * nombre){
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}
void Continente::aggPais(Pais& pais){
    this->paises.push_back(pais);
}