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
public:
    Carta (int terr, const char * fig, const char * pai);
    int getTerritorio();
    char * getFigura();
    char * getPais();
};
#endif //RISK_TADCARTA_H
