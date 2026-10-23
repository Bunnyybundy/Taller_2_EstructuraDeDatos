

#ifndef TALLER_1_ESTRUCTURADEDATOS_NODOPACIENTE_H
#define TALLER_1_ESTRUCTURADEDATOS_NODOPACIENTE_H

#include "Paciente.h"

struct NodoPaciente
{
    Paciente* paciente;
    NodoPaciente* siguiente;

    NodoPaciente(Paciente* p) : paciente(p), siguiente(nullptr) {}
};


#endif //TALLER_1_ESTRUCTURADEDATOS_NODOPACIENTE_H
