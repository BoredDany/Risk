#include <list>
#include "Conexion.h"

Conexion::Conexion(int id) {
    this->id = id;
}

int Conexion::getId() {
    return id;
}

std::list<int> Conexion::getVecinos() {
    return vecinos;
}

void Conexion::aggVecino(int v) {
    this->vecinos.push_back(v);
}
