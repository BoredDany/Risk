#include<iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Carta.h"
#include "Jugador.h"
#include "Continente.h"
using namespace std;

bool tiene_espacio(string comando, string cd[]) {
    bool space = false;

    for (int i = 0; i < comando.size(); i++) {
        if (comando[i] == ' ') {
            space = true;
        }
    }
    int i = 0;
    if (space) {
        std::istringstream ss(comando);
        std::string token;
        while (std::getline(ss, token, ' ')) {
            if (i < 5) {
                cd[i] = token;
                i++;
            } else {
                break;
            }
        }
    }
    return space;
}

void limpiar(string cd[]) {
    for (int i = 0; i < 5; i++) {
        cd[i] = "";
    }
};

void imprimir_ayuda() { // Despliega el menú con comandos disponibles

    cout << "\nCOMANDOS DISPONIBLES \n"
            "inicializar \n"
            "turno \n"
            "guardar \n"
            "guardar_comprimido \n"
            "salir \n"
            "costo_conquista \n"
            "conquista_mas_barata \n"
            "ayuda \n";
}

void descripcion_comando(string c) { // Imprime descripción de comando específico

    if (c == "ayuda") { // ayuda
        cout << "El comando ayuda te permite conocer todos los comandos que puedes "
                "usar en la app o conocer uno en específico. "<< endl;
        cout << "ayuda <comando>" << endl;
    }
    else if (c == "inicializar") { // inicializar
        cout << "El comando inicializar inicializa el juego y asigna territorios a "
                "los jugadores, puedes inicializar un juego nuevo solo escribiendo 'inicializar' "
                "o cargar un juego previamente guardado asi: \n"<< endl;
        cout << "inicializar <nombre_archivo>" << endl;
    }
    else if (c == "turno") { // turno
        cout << "El comando turno realiza las operaciones dentro del turno de un "
                "jugador (obtener nuevas unidades, atacar y fortificar) \n"<< endl;
        cout << "turno <id jugador>" << endl;
    }
    else if (c == "salir") { // salir
        cout << "El comando salir finaliza la ejecución de la aplicación." << endl;
    }
    else if (c == "guardar") { // guardar
        cout << "El comando guardar te permite conservar los datos de la partida "
                "(como nombre, color del jugador, etc.) en un archivo de texto. \n"<< endl;
        cout << "guardar <nombre_archivo>" << endl;
    }
    else if (c == "guardar_comprimido") { // guardar_comprimido
        cout << "El comando guardar_comprimido permitirá guardar los datos del "
                "juego (como nombre, color del jugador, etc.) en un archivo. \n "
                "binario (.bin) comprimido."<< endl;
        cout << "guardar_comprimido <nombre_archivo>" << endl;
    }
    else if (c == "costo_conquista") { // costo_conquista
        cout << "El comando costo_conquista permite calcular el costo y la "
                "secuencia de territorios que deben ser conquistados para "
                "controlar el territorio dado por el usuario en turno. \n"<< endl;
        cout << "costo_conquista <territorio>" << endl;
    }
    else if (c == "conquista_mas_barata") { // conquista_mas_barata
        cout << "El comando conquista más barata calcula el territorio que implica "
                "el menor número de perdida de unidades en el ejército"<< endl;
    }
    else {
        cout << "Comando no disponible" << endl;
    }
}
bool turnoValido(std::vector<Jugador> jugadores, int idJ){
    std::vector<Jugador>::iterator it = jugadores.begin();
    for(it = jugadores.begin();it != jugadores.end();it++){
        if(idJ == it->getId()){
            return true;
        }
    }
    return false;
}

bool turnoCorrecto(std::vector<Jugador> jugadores, int idJ){
    //para saber si el turno ingresado es el que corresponde
return true;
}

bool turnonumerico(std::string turno){
    for(char c: turno){
        if(isalpha(c)){
            return true;
        }
    }
    return false;
}