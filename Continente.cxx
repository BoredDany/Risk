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
bool Continente::lleno(){
    std::list<Pais>::iterator it = paises.begin();
    bool lleno = true;
    for(it = paises.begin();it != paises.end();it++){
        if(it->get_id_jugador() == 0){
            lleno = false;
        }
    }
    return lleno;
}

void Continente::ocuparPais(int idJugador, int idPais){
    std::list<Pais>::iterator it = paises.begin();
    for(it = paises.begin();it != paises.end();it++){
        if(idPais == it->get_id()){
            it->set_id_jugador(idJugador);
            it->set_unidades(it->get_unidades()+1);
        }
    }
}