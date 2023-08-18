//
// Created by Estudiante on 13/08/2023.
//
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;
void imprimir_ayuda();
bool tiene_espacio(string comando, string cd[]);
void limpiar(string cd[]);
void descripcion_comando(string c);

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
            inicializarJuego();
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

    } while (comando != "salir");
}

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

void pruebaTAD(){

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

void inicializarJugadores(){
}

void cargarCartas(){
}

void inicializarTablero(){
}

void cargarGrafoRebuscado(){
};

void asignarUnidades(){
}

void inicializarJuego(){
    cargarCartas();
    inicializarTablero();
    cargarGrafoRebuscado();
    inicializarJugadores();
    asignarUnidades();
}

