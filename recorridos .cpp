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

}