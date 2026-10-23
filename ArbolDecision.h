

#ifndef TALLER_2_ESTRUCTURADEDATOS_ARBOLDECISION_H
#define TALLER_2_ESTRUCTURADEDATOS_ARBOLDECISION_H

#include "Paciente.h"
#include <string>
using namespace std;

class ArbolDecision
{
    public:
    ArbolDecision();

    string determinarServicio(const Paciente& paciente);
};


#endif //TALLER_2_ESTRUCTURADEDATOS_ARBOLDECISION_H
