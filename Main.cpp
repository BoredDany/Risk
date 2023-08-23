//
// Created by Estudiante on 13/08/2023.
//
#include <iostream>
#include <list>
#include "mainFunctions.h"
#include "Carta.h"
#include "Jugador.h"
using namespace std;

int main() {

    string comando, comando_ayuda;
    string cd[5];
    string archivo_cartas = "cartas.txt";
    std::list<Carta> cartas;
    bool hayEspacio = false, inicializado = false;

    cout << "BIENVENIDO A RISK - GRUPO 2" << endl;
    std::cout << "            a@@@@a             \n"
                 "        a@@@@@@@@@@@@a         \n"
                 "      a@@@@@@by@@@@@@@@a       \n"
                 "    a@@@@@S@C@E@S@W@@@@@@a     \n"
                 "    @@@@@@@@@@@@@@@@@@@@@@     \n"
                 "     `@@@@@@`\\\\//'@@@@@@'    \n"
                 "          ,,  ||  ,,           \n"
                 "         /(-\\ || /.)          \n"
                 "    ,---' /`-'||`-'\\ `----,   \n"
                 "   /( )__))   ||   ((,==( )\\  \n"
                 "_ ///_\\\\ _|| _\\ __\\ _\n"
                 "    ``    `` /MM\\   ''   ''   \n"
              << std::endl;

    do {

        cout << "\n$";
        getline(cin, comando);
        hayEspacio = tiene_espacio(comando, cd);

        if (hayEspacio) {

            if (cd[2] != "") {
                cout << "Numero de argumentos invalido" << endl;
            }
            else if (cd[0] == "ayuda") {
                descripcion_comando(cd[1]);
            }
            else if (cd[0] == "turno") {
                cout << "Turno para el jugador " << cd[1] << " :recibido" << endl;
            }
            else if (cd[0] == "guardar") {
                cout << "Guardar en archivo de texto '" << cd[1] << "' :recibido"<< endl;
            }
            else if (cd[0] == "guardar_comprimido") {
                cout << "Guardar en archivo binario '" << cd[1] << "' :recibido"<< endl;
            }
            else if (cd[0] == "inicializar") {
                cout << "Inicializar juego del archivo '" << cd[1] << "' :recibido"<< endl;
            }
            else if (cd[0] == "costo_conquista") {
                cout << "Costo de la conquista " << cd[1] << " :recibido" << endl;
            }
            else {
                cout << "Comando invalido" << endl;
            }

        }
        else if (comando == "inicializar") { // Operaciones para inicializar el juego
            cout << "Comando 'inicializar' recibido\n";
            //inicializarJuego();
        }
        else if (comando == "ayuda") { // Desplegar menú con los comandos disponibles
            imprimir_ayuda();
        }
        else if (comando == "salir") { // Salir del juego
            cout<<"Gracias por usar la app ;)"<<endl;
        }
        else if (comando == "turno" || comando == "guardar" ||
                 comando == "guardar_comprimido" ||
                 comando == "costo_conquista") {
            cout << "Comando incompleto, ingrese el parametro" << endl;
        }
        else if (comando == "conquista_mas_barata") { // Operaciones para indicar conquista más barata
            cout << "Comando 'conquista_mas_barata' recibido\n";
        }
        else if(comando == "test"){

            cargarCartas(cartas, archivo_cartas);
            std::list<Carta>::iterator it = cartas.begin();
            int i = 0;
            /*for(it = cartas.begin() ; it != cartas.end() ; it++){
                cout<<i+1<<": "<<it->getTerritorio()<<";"
                <<it->getPais()<<";"<<it->getFigura()<<";"
                <<it->getContinente()<<endl;
                i++;
            }*/

            cout<<"PRUEBA DE JUGADOR"<<endl<<endl;
            string color = "rojo", alias = "player1", color2 = "azul", alias2 = "player2";

            Jugador jugador1(22,&color[0],&alias[0], 4);
            jugador1.agregarCarta(*(next(cartas.begin(), 0)));
            jugador1.agregarCarta(*(next(cartas.begin(), 1)));

            Jugador jugador2(33,&color2[0],&alias2[0], 3);
            jugador2.agregarCarta(*(next(cartas.begin(), 2)));

            std::list<Jugador>players;
            players.push_back(jugador1);
            players.push_back(jugador2);

            cout<<"JUGADORES"<<endl<<endl;

            std::list<Jugador>::iterator itJ = players.begin();

            int k = 0, j = 0;
            for(itJ = players.begin() ; itJ != players.end() ; itJ++){
                cout<<"------JUGADOR"<<k+1<<"-------"<<endl;
                cout<<"ID: "<<itJ->getId()<<" ; COLOR: "<<itJ->getColor()<<
                " ; ALIAS: "<<itJ->getAlias()<<" ; UNIDADES: "<<itJ->getUnidades()<< endl;
                cout<<"HAY "<<itJ->getCartas().size()<<" CARTAS: "<< endl;

                std::list<Carta>auxCartas = itJ->getCartas();
                std::list<Carta>::iterator itC = auxCartas.begin();

                for(itC = auxCartas.begin() ; itC != auxCartas.end() ; itC++){
                    cout<<"Carta "<<j+1<<": "<<itC->getTerritorio()<<";"
                        <<itC->getPais()<<";"<<it->getFigura()<<";"
                        <<itC->getContinente()<<endl;
                    ++j;
                }
                ++k;
                cout<<endl;
                j = 0;
            }
        }
        else {
            cout << "Comando invalido" << endl;
        }

        limpiar(cd);

    } while (comando != "salir");
}
