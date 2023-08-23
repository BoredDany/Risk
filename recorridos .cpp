//RECORRRER JUGADORES
#include <iostream>
#include <list>
#include "mainFunctions.h"
#include "Carta.h"
#include "Jugador.h"
#include "Continente.h"
#include "Pais.h"

            int main () {
                cout << "JUGADORES" << endl << endl;
                std::list<Jugador>::iterator itJ = players.begin();

                //recorrer jugadores con sus cartas
                int k = 0, j = 0;
                for (itJ = players.begin(); itJ != players.end(); itJ++) {
                    cout << "------JUGADOR" << k + 1 << "-------" << endl;
                    cout << "ID: " << itJ->getId() << " ; COLOR: " << itJ->getColor() <<
                         " ; ALIAS: " << itJ->getAlias() << " ; UNIDADES: " << itJ->getUnidades() << endl;
                    cout << "HAY " << itJ->getCartas().size() << " CARTAS: " << endl;

                    std::list<Carta> auxCartas = itJ->getCartas();
                    std::list<Carta>::iterator itC = auxCartas.begin();

                    for (itC = auxCartas.begin(); itC != auxCartas.end(); itC++) {
                        cout << "Carta " << j + 1 << ": " << itC->getTerritorio() << ";"
                             << itC->getPais() << ";" << itC->getFigura() << ";"
                             << itC->getContinente() << endl;
                        ++j;
                    }
                    ++k;
                    cout << endl;
                    j = 0;
                }

                //recorrer cartas

                std::list<Carta>::iterator it = cartas.begin();
                for( ; it != cartas.end() ; it++){
                    cout<<"carta: "<<it->getContinente()<<" - "<<it->getPais()<<endl;
                }

                //recorrer cartas de 1 jugador
                for(Carta c: jugador1.getCartas()){
                    cout<<"carta "<<c.getPais()<<endl;
                }
            }