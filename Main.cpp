//
// Created by Estudiante on 13/08/2023.
//
#include <iostream>
#include "mainFunctions.h"
#include "Carta.h"
#include "Partida.h"
using namespace std;

int main() {

    string comando, comando_ayuda;
    string cd[5];
    string archivo_cartas = "cartas.txt";
    string archivo_conexiones = "Conexiones.txt";
    bool hayEspacio = false, inicializado = false;
    Partida risk(0);

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
                if(!inicializado){
                    cout << "Juego no incializado" << endl;
                }else{
                    if(!turnonumerico(cd[1])){
                        int turno = stoi(cd[1]);
                        if(turnoValido(risk.get_jugadores(), turno)){
                            if(turnoCorrecto(risk.get_jugadores(), turno)){
                                cout << "Turno para el jugador " << cd[1] << " :recibido" << endl;
                            }else{
                                cout << "Jugador fuera del turno" << endl;
                            }
                        }else{
                            cout << "Jugador no valido" << endl;
                        }
                    }else{
                        cout << "Turno debe ser un numero" << endl;
                    }
                }

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
            if(inicializado){
                cout << "Juego en curso\n";
            }else{
                risk.set_id(1);
                risk.cargarCartas(archivo_cartas);
                risk.inicializarJugadores();
                risk.inicializarTablero();
                risk.llenarContinentes();
                risk.cargarConexiones(archivo_conexiones);
                risk.ubicarUnidades(inicializado);
                risk.mostrarInicializacion();
            }
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
        else {
            cout << "Comando invalido" << endl;
        }

        limpiar(cd);

    } while (comando != "salir" || comando == "");
}