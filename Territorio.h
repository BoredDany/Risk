#ifndef __TERRITORIO__H__
#define __TERRITORIO__H__

#include "Jugador.h"

class Territorio{
 public:
     Territorio();
     void setIdentificador(int id);
     void setNombre(string nombre []);
     void setUnidades(int unidades);
     void setIDJugador(int id_jugador);
     void setUnidadesJugador(int unidadesJugador);

     int getIdentificador();
     std::string getNombre();
     int getUnidades();
     int getIDJugador();
     int getUnidadesJugador();

     void territorioVacio();
 protected:
     int identificador;
     std::string nombre;
     int unidades;
     int idJugador;
     int unidadesJugador;
};
#endif // __TERRITORIO__H__
