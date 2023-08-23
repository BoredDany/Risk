//
// Created by Estudiante on 23/08/2023.
//

#ifndef RISK_CONTINENTE_H
#define RISK_CONTINENTE_H
#include "Pais.h"
#include<list>

class Continente{

private:
    char * nombre;
    std::list<Pais> paises;
public:
    Continente(char * nombre, std::list<Pais>& paises);
    char * get_nombre(char * nombre);
    std::list<Pais> get_paises();
    void set_nombre(char * nombre);
    void set_paises(std::list<Pais> paises);
};

#endif //RISK_CONTINENTE_H