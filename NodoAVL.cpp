

#include "NodoAVL.h"

NodoAVL::NodoAVL(const Paciente& paciente)
{
    this->paciente = paciente;
    izquierda = nullptr;
    derecha = nullptr;
    altura = 1;
}
