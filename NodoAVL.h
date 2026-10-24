

#ifndef TALLER_2_ESTRUCTURADEDATOS_NODOAVL_H
#define TALLER_2_ESTRUCTURADEDATOS_NODOAVL_H

#include "Paciente.h"

class NodoAVL
{
    public:
     Paciente paciente;
     NodoAVL* izquierda;
     NodoAVL* derecha;
     int altura;

     NodoAVL(const Paciente& paciente);
};


#endif //TALLER_2_ESTRUCTURADEDATOS_NODOAVL_H
