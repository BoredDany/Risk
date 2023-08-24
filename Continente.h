//
// Created by Estudiante on 24/08/2023.
//

#ifndef RISK_CONTINENTE_H
#define RISK_CONTINENTE_H
#include "Pais.h"
#include<string>
#include<list>

class Continente{
private:
    std::string nombre;
    std::list<Pais> paises;
public:
    Continente(std::string nombre);
    std::string get_nombre();
    std::list<Pais> get_paises();
    void aggPais(Pais p);
    void setNombre(std::string nombre);
};

#endif //RISK_CONTINENTE_H
