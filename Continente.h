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
    Continente(char * nombre);
    char * get_nombre();
    std::list<Pais> get_paises();
    void set_nombre(char * nombre);
    void aggPais(Pais& pais);
};

#endif //RISK_CONTINENTE_H