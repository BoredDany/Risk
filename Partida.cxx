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
#include <time.h>

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
}//inicializar cartas
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
}//inicializar jugadores
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

    std::cout<<"\nColores disponibles:"<<std::endl;
    std::cout<<"\n1. verde\n2. azul\n3. rojo\n4. amarillo\n5. rosado\n6. morado"<<std::endl;

    for(int i = 0 ; i < numJ ; i++){
        std::cout<<"\nJUGADOR "<<i+1<<std::endl;
        std::cout<<"ALIAS:";
        std::cout<< "\n$";
        std::cin>>alias;
        std::cout<<"Color:\n$";
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
}//cargar tablero
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
}//vecinos
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
bool Partida:: tableroLleno(){
    std::list<Continente>::iterator it = tablero.begin();
    bool llenoTab = true;
    for(it = tablero.begin();it != tablero.end();it++){
        if(!it->lleno()){
            llenoTab = false;
        }
    }
    return llenoTab;
}//ubicar unidades
bool Partida::paisLleno(int id){
    std::list<Continente>::iterator it = tablero.begin();
    bool lleno = true;
    for(it = tablero.begin();it != tablero.end();it++){
        std::list<Pais> paises = it->get_paises();
        std::list<Pais>::iterator itPaises = paises.begin();
        for(itPaises = paises.begin() ; itPaises != paises.end() ; itPaises++){
            if(itPaises->get_id() == id && itPaises->get_unidades() == 0){
                lleno = false;
            }
        }

    }
    return lleno;
}
void Partida::ocuparPais(int idJugador, int idPais){
    std::list<Continente>::iterator it = tablero.begin();
    for(it = tablero.begin();it != tablero.end();it++){
        it->ocuparPais(idJugador,idPais);
    }
}
Carta Partida::obtenerCarta(int idPais){
    std::list<Carta>::iterator it = cartas.begin();
    for(it = cartas.begin();it != cartas.end();it++){
        if(it->getId() == idPais){
            return *it;
        }
    }
}
void Partida::ubicarUnidades(bool& inicializado) {
    std::list<Continente>::iterator itContinetes;
    int auxPais = 0;
    bool lleno = false;
    bool ocupado = true;

    std::cout<<"\n****************************************"<<std::endl;
    std::cout<<"*   TERRITORIOS DEL TABLERO DE JUEGO   *"<<std::endl;
    std::cout<<"****************************************"<<std::endl<<std::endl;

    while(!lleno){

        for(int i=0; i<jugadores.size() && !lleno; i++){
            do{
                std::cout<<"\nJUGADOR:"<<jugadores[i].getAlias()<<std::endl;
                std::cout<<"Ingrese el numero del pais: \n$";
                std::cin>>auxPais;
                ocupado = paisLleno(auxPais);
                if(ocupado){
                    std::cout<<"Pais ocupado o no valido"<<std::endl;
                }
            }while(ocupado && !lleno);
            if(!lleno){
                ocuparPais(jugadores[i].getId(), auxPais);
                jugadores[i].setUnidades(jugadores[i].getUnidades()-1);
                jugadores[i].agregarCarta(obtenerCarta(auxPais));
            }
            lleno = tableroLleno();
        }
    }
    std::cin.ignore();
    inicializado = true;
    std::cout<<"\nInicializacion satisfactoria"<<std::endl;
}
void Partida::mostrarInicializacion(){//mostrar jugadores con sus cartas
    /*std::cout<<"JUGADORES"<<std::endl;
    for(int i = 0 ; i < jugadores.size() ; i++){
        std::cout<<"Jugador "<<jugadores[i].getId()<<":"<<jugadores[i].getAlias()<<std::endl;
        std::cout<<"color: "<<jugadores[i].getColor()<<" tiene "<<jugadores[i].getCartas().size()<<std::endl;
        std::list<Carta> cartasJ = jugadores[i].getCartas();
        std::list<Carta>::iterator it = cartasJ.begin();
        for(it = cartasJ.begin();it != cartasJ.end();it++){
            std::cout<<it->getId()<<":"<<it->getPais()<<std::endl;
        }
    }*/
    std::cout<<"TABLERO"<<std::endl;
    std::list<Continente>::iterator it = tablero.begin();
    for(it = tablero.begin();it != tablero.end();it++){
        std::cout<<it->get_nombre()<<" paises: "<<std::endl;
        std::list<Pais> p=it->get_paises();
        std::list<Pais>::iterator itp = p.begin();
        for(itp = p.begin();itp != p.end();itp++){
            std::cout<<itp->get_id()<<":"<<itp->get_nombre()<<" pertenece a "<<itp->get_id_jugador()<<std::endl;
        }
    }
}

bool Partida::jugadorOcupaPais(int idJ, int idP){
    std::list<Continente>::iterator it = tablero.begin();
    bool ocupa = false;
    for(it = tablero.begin();it != tablero.end();it++){
        ocupa = it->jugadorOcupaPais(idP, idJ);
        if(ocupa){
            break;
        }
    }
    return ocupa;
}
bool Partida::paisExiste(int idP){
    std::list<Continente>::iterator it = tablero.begin();
    bool existe = false;
    for(it = tablero.begin();it != tablero.end();it++){
        existe = it->paisExiste(idP);
        if(existe){
            break;
        }
    }
    return existe;
}
bool Partida::paisVecino(int paisOrigen, int paisDestino){
    std::list<Continente>::iterator it = tablero.begin();
    bool vecino = false;
    for(it = tablero.begin();it != tablero.end();it++){
        vecino = it->paisVecino(paisOrigen,paisDestino);
        if(vecino){
            break;
        }
    }
    return vecino;
}
void Partida::elegirUbicacionAtaque(int posJug, int * paisOrigen, int * paisDestino){
    bool ocupado = false, existe = false, esVecino = false, lleno = false;
    do{
        std::cout<<"Ingrese numero de pais desde donde quiere atacar: \n$";
        std::cin>>*paisOrigen;
        ocupado = jugadorOcupaPais(jugadores[posJug-1].getId(), *paisOrigen);
        existe = paisExiste(*paisOrigen);
        if(!ocupado){
            std::cout<<"No tiene unidades suyas en este pais"<<std::endl;
        }
        if(!existe){
            std::cout<<"No existe este pais"<<std::endl;
        }
    }while(!existe || !ocupado);
    std::cout<<"VA A ATACAR DESDE EL PAIS "<<*paisOrigen<<std::endl<<std::endl;

    do{
        std::cout<<"Ingrese numero de pais a atacar: \n$";
        std::cin>>*paisDestino;
        esVecino = paisVecino(*paisOrigen, *paisDestino);
        existe = paisExiste(*paisDestino);
        lleno = paisLleno(*paisDestino);
        if(!existe){
            std::cout<<"Este pais no existe"<<std::endl;
        }
        if(!esVecino){
            std::cout<<"No puede atacar este pais, no es vecino de "<<*paisOrigen<<std::endl;
        }
        if(!lleno){
            std::cout<<"No puede atacar este pais, no hay nadie, puede fortificar si desea "<<std::endl;
        }
    }while(!existe || !esVecino || !lleno);
    std::cout<<"VA A ATACAR AL PAIS "<<*paisDestino<<std::endl;
}

int Partida::buscarAtacado(int idP){
    int atacado =  -1, posAtacado = -1;
    std::list<Continente>::iterator it = tablero.begin();
    for(it = tablero.begin();it != tablero.end();it++){
        std::list<Pais> p = it->get_paises();
        std::list<Pais>::iterator itp = p.begin();
        for(itp = p.begin();itp != p.end();itp++){
            if(itp->get_id() == idP){
                atacado = itp->get_id_jugador();
            }
        }
    }
    for(int i = 0 ; i < jugadores.size() ; i++){
        if(jugadores[i].getId() == atacado){
            posAtacado = i;
        }
    }
    return posAtacado;
}

int Partida::lanzarDados(int numDados){
    std::vector<int> dados;
    int descartar = 0, resultado = 0;

    srand(time(NULL));
    for(int i = 0 ; i < numDados ; i++){
        int n = 1 + rand() % (7 - 1);
        dados.push_back(n);
    }
    for(int i = 0 ; i < dados.size() ; i++){
        std::cout<<"Dado "<<i+1<<":"<<dados[i]<<std::endl;
    }
    if(numDados == 3){
        do{
            std::cout<<"Elija dado para descartar:\n$";
            std::cin>>descartar;
        }while(descartar < 1 || descartar > 3);
        dados.erase(dados.begin()+descartar-1);
        for(int i = 0 ; i < dados.size() ; i++){
            resultado = resultado+dados[i];
        }
    }else{
        for(int i = 0 ; i < dados.size() ; i++){
            resultado = resultado+dados[i];
        }
    }
    return resultado;
}

void Partida::quitarUnidad(int idP, bool * vaciado){
    std::list<Continente>::iterator it = tablero.begin();
    for(it = tablero.begin();it != tablero.end();it++){
        std::list<Pais> p = it->get_paises();
        std::list<Pais>::iterator itp = p.begin();
        for(itp = p.begin();itp != p.end();itp++){
            if(itp->get_id() == idP){
                if(itp->get_unidades() == 0){
                    itp->set_id_jugador(0);
                    *vaciado = true;
                }else{
                    itp->set_unidades(itp->get_unidades()-1);
                }
            }
        }
    }
    if(*vaciado){
        std::cout<<"SE DEBE QUITAR CARTA"<<std::endl;
    }
}
void Partida::atacar(int posAtacante, int origen, int destino){
    int posAtacado = buscarAtacado(destino), puntosAtacante = 0, puntosAtacado = 0;
    bool vaciado = false;
    std::cout<<"\nATACADO ESTA EN POS:"<<posAtacado<<std::endl;
    std::cout<<"ATACADO ES:"<<jugadores[posAtacado].getId()<<std::endl;

    do{
        std::cout<<"\nATACANTE LANZA  DADOS:"<<std::endl;
        puntosAtacante = lanzarDados(3);
        std::cout<<"\nATACANTE OBTUVO:"<<puntosAtacante<<std::endl;

        std::cout<<"\nATACADO LANZA DADOS:"<<std::endl;
        puntosAtacado = lanzarDados(2);
        std::cout<<"\nATACADO OBTUVO:"<<puntosAtacado<<std::endl;

        if(puntosAtacado > puntosAtacante){
            std::cout<<"\nATACADO GANA"<<puntosAtacado<<std::endl;
            //ATACANTE PIERDE UNIDAD DE SU TERRITORIO
            quitarUnidad(origen, &vaciado);
        }
        if(puntosAtacado < puntosAtacante){
            std::cout<<"\nATACANTE GANA"<<puntosAtacado<<std::endl;
            //ATACADO PIERDE UNIDAD DE SU TERRITORIO
            quitarUnidad(destino, &vaciado);
        }
        if(puntosAtacado == puntosAtacante){
            std::cout<<"\nATACADO GANA POR EMPATE"<<puntosAtacado<<std::endl;
            //ATACANTE PIERDE UNIDAD DE SU TERRITORIO
            quitarUnidad(origen, &vaciado);
        }
    }while(!vaciado);

}

bool Partida::sonTresCartasIguales(const std::list<Carta>& cartas) {
    auto it = cartas.begin();
    const Carta& primeraCarta = *it;
    ++it;
    const Carta& segundaCarta = *it;
    ++it;
    const Carta& terceraCarta = *it;

    return primeraCarta.esIgual(segundaCarta) && segundaCarta.esIgual(terceraCarta);
}

void Partida::intercambiarCartasPorUnidades(int jugadorIndex, int paisesPropios, bool tieneTodaSuramerica, bool tieneTodaOceania, bool tieneTodaAfrica, bool tieneTodaNorteamerica, bool tieneTodaEuropa, bool tieneTodaAsia) {
    if (jugadores[jugadorIndex].getCartas().size() < 3) {
        std::cout << "El jugador no tiene suficientes cartas para el intercambio." << std::endl;
        return; 
    }

    std::list<Carta> cartasAIntercambiar;
    int contador = 0;
    for (auto it = jugadores[jugadorIndex].getCartas().begin(); contador < 3; ++it) {
        cartasAIntercambiar.push_back(*it);
        contador++;
    }

    if (!sonTresCartasIguales(cartasAIntercambiar)) {
        std::cout << "Las tres cartas no son iguales y no se pueden intercambiar." << std::endl;
        return;
    }

    int unidadesAgregadas = 5;

    if (contador >= 1 && contador <= 6) {
        unidadesAgregadas = (contador * 2) + 2;
    }

    if (tieneTodaSuramerica || tieneTodaOceania) {
        unidadesAgregadas -= 2;
    }
    if (tieneTodaAfrica) {
        unidadesAgregadas += 3;
    }
    if (tieneTodaNorteamerica || tieneTodaEuropa) {
        unidadesAgregadas += 5;
    }
    if (tieneTodaAsia) {
        unidadesAgregadas += 7;
    }

    unidadesAgregadas += (paisesPropios / 3) * (-1);

    jugadores[jugadorIndex].setUnidades(jugadores[jugadorIndex].getUnidades() + unidadesAgregadas);

    for (const Carta& carta : cartasAIntercambiar) {
        jugadores[jugadorIndex].eliminarCarta(carta);
    }
}
