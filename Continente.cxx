#include "Continente.h"
#include <string>

Continente::Continente(std::string nombre){
    this->nombre = nombre;
}

std::string Continente::get_nombre(){
    return nombre;
}
std::list<Pais> Continente::get_paises(){
    return paises;
}
void Continente::aggPais(Pais p){
    this->paises.push_back(p);
}
void Continente::setNombre(std::string nombre){
    this->nombre = nombre;
}

void Continente::aggConexion(int pais, int vecino){
    std::list<Pais>::iterator it = paises.begin();
    for(it = paises.begin();it != paises.end();it++){
        if(pais == it->get_id()){
            it->agg_conexion(vecino);
        }
    }
}