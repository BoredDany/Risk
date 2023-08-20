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
    string nombre_archivo;
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
            cout<<"PRUEBA DE JUGADOR";
            Carta carta (3, "hola", "jajaaj");
            std::list<Carta> cartas;
            cartas.push_back(carta);
            string color = "rojo", alias = "player";
            Jugador jugador (1,&color[0],&alias[0],cartas);
            cout<<"SE PRUEBA EL TAD JUGADOR: "<<endl;
            cout<<"ID: "<<jugador.getId()<< endl;
            cout<<"COLOR: "<<jugador.getColor()<< endl;
            cout<<"ALIAS: "<<jugador.getAlias()<< endl;
            cout<<"UNIDADES: "<<jugador.getUnidades()<< endl;
            cout<<"CARTAS: "<< endl;
            std::list<Carta>::iterator iC = jugador.getCartas().begin();
            for(iC = jugador.getCartas().begin() ; iC != jugador.getCartas().begin() ; iC++){
                cout<<"Carta:"<< endl;
                cout<<"Territorio: "<<iC->getTerritorio()<< endl;
                cout<<"Figura: "<<iC->getFigura()<< endl;
                cout<<"Pais: "<<iC->getPais()<< endl;
            }

        }
        else {
            cout << "Comando invalido" << endl;
        }

        limpiar(cd);

    } while (comando != "salir");
}
