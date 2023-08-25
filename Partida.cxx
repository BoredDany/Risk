#include "Continente.h"
#include "Carta.h"
#include "Jugador.h"
#include "Partida.h"
#include<list>
#include<vector>
#include<string>
#include <fstream>
#include <iostream>
#include <sstream>

Partida::Partida(int id){
    this->id = id;
}
std::vector<Jugador> Partida::get_jugadores() {
    return jugadores;
}
std::list<Carta> Partida::get_cartas(){
    return cartas;
}
std::list<Continente> Partida::get_tablero(){
    return tablero;
}
void Partida::set_id(int id){
    this->id = id;
}
int Partida::countLines(std::string archivo_cartas){
    int i = 0;
    std::string line;
    std::ifstream inputFile(archivo_cartas);
    if(inputFile.is_open()){
        while(getline(inputFile,line)){
            i++;
        }
        inputFile.clear();
        inputFile.seekg(0);
    }else{
        std::cout<<"No se pudo abrir archivo"<<std::endl;
    }
    inputFile.close();
    return i;
}
void Partida::cargarCartas(std::string archivo_cartas){
    std::ifstream inputFile(archivo_cartas);
    std::string line, word;
    int territorio, size = countLines(archivo_cartas);
    std::string figura, pais, continente;

    //terreno; pais; figura; continente
    if(inputFile.is_open()){
        for(int i = 0 ; i < size ; i++){
            getline(inputFile,line);
            std::stringstream str(line);
            getline(str,word,';');
            territorio = stoi(word);
            getline(str,word,';');
            pais = word;
            getline(str,word,';');
            figura = word;
            getline(str,word,';');
            continente = word;
            cartas.push_back(Carta (territorio,figura,continente,pais));
        }

    }else{
        std::cout<<"Archivo no leido"<<std::endl;
    }
    inputFile.close();
}
bool Partida::buscarColorRepetido (std::string color){
    for(int i = 0 ; i < jugadores.size() ; i++){
        if(jugadores[i].getColor() == color){
            return true;
        }
    }
    return false;
}
void Partida::asignarUnidades(){
    int unidades = 0, numJ = jugadores.size();
    switch(numJ){
        case 3:
            unidades = 35;
            break;
        case 4:
            unidades = 30;
            break;
        case 5:
            unidades = 25;
            break;
        case 6:
            unidades = 20;
            break;
    }
    for(int i = 0 ; i < jugadores.size() ; i++){
        jugadores[i].setUnidades(unidades);
    }
}
void Partida::inicializarJugadores(){
    int numJ = 0, id = 1, colorN = 0;
    std::string color, alias;
    bool repetido = false;
    do{
        std::cout<<"Ingrese cantidad de jugadores (entre 3 y 6): \n$";
        std::cin>>numJ;
    }while(numJ < 3 || numJ > 6);

    for(int i = 0 ; i < numJ ; i++){
        std::cout<<"Jugador "<<i+1<<std::endl;
        std::cout<<"Alias:";
        std::cout<< "\n$";
        std::cin>>alias;
        std::cout<<"Ingrese numero para elegir color: \n1. verde\n"
              "2. azul\n"
              "3. rojo\n"
              "4. amarillo\n"
              "5. rosado\n"
              "6. morado\n$";
        do{
            std::cin>>colorN;
            switch (colorN) {
                case 1:
                    color = "verde";
                    break;
                case 2:
                    color = "azul";
                    break;
                case 3:
                    color = "rojo";
                    break;
                case 4:
                    color = "amarillo";
                    break;
                case 5:
                    color = "rosado";
                    break;
                case 6:
                    color = "morado";
                    break;
            }
            repetido = buscarColorRepetido(color);
            if(colorN < 1 || colorN > 6){
                std::cout<<"Color invalido\n$";
            }
            if(repetido){
                std::cout<<"Color repetido\n$";
            }else{
                repetido = false;
            }
        }while(colorN < 1 || colorN > 6 || repetido);
        Jugador nuevo(id,color,alias);
        jugadores.push_back(nuevo);
        id++;
    }
    asignarUnidades();
    std::cin.ignore();
}
bool Partida::repetido(std::string nombre){
    std::list<Continente>::iterator itCo = tablero.begin();
    for( itCo = tablero.begin() ; itCo != tablero.end() ; itCo++){
        if(nombre == itCo->get_nombre()){
            return true;
        }
    }
    return false;
}
void Partida::inicializarTablero(){
    std::list<Carta>::iterator it = cartas.begin();
    for( it = cartas.begin(); it != cartas.end() ; it++){
        bool rep = repetido(it->getContinente());
        if(!rep){
            Continente c(it->getContinente());
            tablero.push_back(c);
        }
    }
}
void Partida::llenarContinentes() {
    std::list<Carta>::iterator it = cartas.begin();
    std::list<Continente>::iterator itCo = tablero.begin();

    for( itCo = tablero.begin(); itCo != tablero.end() ; itCo++){
        for( it = cartas.begin(); it != cartas.end() ; it++){
            if(itCo->get_nombre() == it->getContinente()){
                Pais p(it->getId(),it->getPais(),it->getContinente());
                itCo->aggPais(p);
            }
        }
    }
}

void Partida::aggConexion(int pais, int vecino){
    std::list<Continente>::iterator it = tablero.begin();
    for(it = tablero.begin();it != tablero.end();it++){
        it->aggConexion(pais,vecino);
    }
}

void Partida::cargarConexiones(std::string archivo){
     std::ifstream file (archivo);
     int size = countLines(archivo);
     std::string line, word;

     if(file.is_open()){
         for(int i = 0 ; i<size ; i++){
            getline(file,line,'\n');
            std::stringstream ss(line);
            getline(ss,word,'-');
            int pais = stoi(word);
            while(getline(ss,word,';')){
                int vecino = stoi(word);
                aggConexion(pais,vecino);
            }
         }


     }else{
         std::cout<<"Archivo de conexiones no leido"<<std::endl;
     }
     file.close();
}
