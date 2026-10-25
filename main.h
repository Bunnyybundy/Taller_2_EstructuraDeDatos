#ifndef TALLER_1_ESTRUCTURADEDATOS_MAIN_H
#define TALLER_1_ESTRUCTURADEDATOS_MAIN_H

#include <string>
#include "ColaPacientes.h"
#include "Hospital.h"
#include "ArbolDecision.h"
using namespace std;

bool cargarPacientes(const std::string& nombreArchivo, ColaPacientes& cola);

void atenderPacientes(ColaPacientes& cola, Hospital& hospital, const ArbolDecision& arbol);

#endif //TALLER_1_ESTRUCTURADEDATOS_MAIN_H
