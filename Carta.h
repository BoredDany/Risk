//
// Created by Estudiante on 18/08/2023.
//

#ifndef RISK_TADCARTA_H
#define RISK_TADCARTA_H
#include<string>

class Carta {
private:
    int territorio;
    std::string figura;
    std::string pais;
    std::string continente;
public:
    Carta (int terr, std::string fig, std::string cont, std::string pai);
    int getTerritorio();
    std::string getFigura();
    std::string getContinente();
    std::string getPais();
};
#endif //RISK_TADCARTA_H
