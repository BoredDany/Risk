//
// Created by Estudiante on 18/08/2023.
//

#ifndef RISK_TADCARTA_H
#define RISK_TADCARTA_H
class Carta {
private:
    int territorio;
    char * figura;
    char  * pais;
    char  * continente;
public:
    Carta (int terr, char * fig, char * cont, char * pai);
    int getTerritorio();
    char * getFigura();
    char * getContinente();
    char * getPais();
};
#endif //RISK_TADCARTA_H
