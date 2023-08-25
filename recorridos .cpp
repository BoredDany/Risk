//RECORRRER JUGADORES
#include <iostream>
#include <list>
#include <vector>
#include "mainFunctions.h"
#include "Carta.h"
#include "Jugador.h"
#include "Continente.h"
#include "Pais.h"

int main(){

    cout<<"CARTAS"<<endl;
    std::list<Carta>::iterator it = cartas.begin();
    for( ; it != cartas.end() ; it++){
        cout<<"carta: "<<it->getId()<<" en "<<it->getContinente()<<" - "<<it->getPais()<<endl;
    }
    cout<<"CONTINENTES"<<endl;
    std::list<Continente>::iterator itC = continentes.begin();
    for(itC = continentes.begin() ; itC != continentes.end() ; itC++){
        cout<<"Continente "<<itC->get_nombre()<<" tiene "<<itC->get_paises().size()<<" paises:"<<endl;
        std::list<Pais> paisesAux = itC->get_paises();
        std::list<Pais>::iterator itp = paisesAux.begin();
        for(itp = paisesAux.begin( ); itp != paisesAux.end() ; itp++){
            cout<<itp->get_id()<<":"<<itp->get_nombre()<<" - "<<itp->get_continente()<<endl;
        }
    }
    cout<<"JUGADORES"<<endl;
    int k = 0, j = 0;
    std::vector<Jugador>::iterator itJ = jugadores.begin();
    for (itJ = jugadores.begin(); itJ != jugadores.end(); itJ++) {
        cout << "------JUGADOR " << k + 1 << "-------" << endl;
        cout << "ID: " << itJ->getId() << " ; COLOR: " << itJ->getColor() <<
             " ; ALIAS: " << itJ->getAlias() << " ; UNIDADES: " << itJ->getUnidades() << endl;
        cout << "HAY " << itJ->getCartas().size() << " CARTAS: " << endl;

        std::list<Carta> auxCartas = itJ->getCartas();
        std::list<Carta>::iterator itC = auxCartas.begin();

        for (itC = auxCartas.begin(); itC != auxCartas.end(); itC++) {
            cout << "Carta " << j + 1 << ": " << itC->getId() << ";"
                 << itC->getPais() << ";" << itC->getFigura() << ";"
                 << itC->getContinente() << endl;
            ++j;
        }
        ++k;
        cout << endl;
        j = 0;
    }
}