//
// Created by Estudiante on 24/08/2023.
//

#ifndef RISK_CONEXION_H
#define RISK_CONEXION_H
#include <list>

class Conexion{
private:
    int id;
    std::list<int> vecinos;
public:
    Conexion(int id);
    int getId();
    std::list<int> getVecinos();
    void aggVecino(int v);
};
#endif //RISK_CONEXION_H
