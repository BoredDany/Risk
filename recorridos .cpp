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

    cout<<"JUGADORES"<<endl;
    for(int i = 0 ; i < risk.get_jugadores().size() ; i++){
        cout<<"Jugador "<<i+1<<" tiene "<<risk.get_jugadores()[i].getCartas().size()<<endl;
        cout<<risk.get_jugadores()[i].getId()<<" , "<<risk.get_jugadores()[i].getColor()<<endl;
        list<Carta> cartasJ = risk.get_jugadores()[i].getCartas();
        std::list<Carta>::iterator it = cartasJ.begin();
        for(it = cartasJ.begin();it != cartasJ.end();it++){
            cout<<it->getPais()<<endl;
        }
    }


    cout<<"CONTINENTES Y PAISES"<<endl;
    std::list<Continente> ca = risk.get_tablero();
    std::list<Continente>::iterator it = ca.begin();
    for(it = ca.begin();it != ca.end();it++){
        cout<<it->get_nombre()<<" tiene "<<it->get_paises().size()<<endl;
        std::list<Pais>p=it->get_paises();
        std::list<Pais>::iterator itp = p.begin();
        for(itp = p.begin();itp != p.end();itp++){
            cout<<itp->get_id()<<":"<<itp->get_nombre()<<" en "<<itp->get_continente()<<endl;
        }
    }

}