#include<iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include "Carta.h"
#include "Jugador.h"
#include "Continente.h"
#include "Conexion.h"
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



bool repetido(std::list<Continente>& continentes, std::string nombre){
    std::list<Continente>::iterator itCo = continentes.begin();
    for( ; itCo != continentes.end() ; itCo++){
        if(nombre == itCo->get_nombre()){
            return true;
        }
    }
    return false;
}

void inicializarTablero(std::list<Carta>& cartas, std::list<Continente>& continentes){
    std::list<Carta>::iterator it = cartas.begin();
    for( ; it != cartas.end() ; it++){
        if(!repetido(continentes, it->getContinente())){
            Continente c(it->getContinente());
            continentes.push_back(it->getContinente());
        }
    }


}

void llenarContinentes(std::list<Carta>& cartas, std::list<Continente>& continentes) {
    std::list<Carta>::iterator it = cartas.begin();
    std::list<Continente>::iterator itCo = continentes.begin();

    for( itCo = continentes.begin(); itCo != continentes.end() ; itCo++){
        for( it = cartas.begin(); it != cartas.end() ; it++){
            if(itCo->get_nombre() == it->getContinente()){
                Pais p(it->getId(),it->getPais(),it->getContinente());
                itCo->aggPais(p);
            }
        }
    }
}

void cargarConexiones(std::list<Continente>& continentes, std::string archivo){
   /* ifstream file (archivo);
    int size = countLines(archivo);
    std::string line, word;
    std::list<Conexion> vecinos;

    if(file.is_open()){
        for(int i = 0 ; i<size ; i++){
            getline(file, line, '\n');
            int id = stoi(line);
            getline(file,line,'\n');
            Conexion con(id);

            std::istringstream ss(line);

            while (std::getline(ss, word, ';')) {
                int v;
                std::istringstream(word) >> v;
                con.aggVecino(v);
            }
            vecinos.push_back(con);
        }

        cout<<"CONEXIONES DE PAISES"<<endl;
        std::list<Conexion>::iterator it = vecinos.begin();
        for(it = vecinos.begin();it != vecinos.end();it++){
            cout<<"Pais: "<<it->getId()<<" tiene vecinos:"<<endl;
            std::list<int> vecinosA = it->getVecinos();
            std::list<int>::iterator itv = vecinosA.begin();
            for(itv = vecinosA.begin();itv != vecinosA.end();itv++){
                cout<<*itv<<" - ";
            }
        }
    }else{
        cout<<"Archivo de conexiones no leido"<<endl;
    }
    file.close();*/
}

void inicializarJuego(){
    /*cargarGrafoRebuscado();
    crearPartidaRisk();*/
}