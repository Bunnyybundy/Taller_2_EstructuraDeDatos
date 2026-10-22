#ifndef TALLER_1_ESTRUCTURADEDATOS_MAIN_H
#define TALLER_1_ESTRUCTURADEDATOS_MAIN_H
#include "ColaPacientes.h"
#include "Hospital.h"
#include "PilaHistorial.h"

void cargarPacientes(const std::string& nombreArchivo, ColaPacientes& cola);

void atenderPacientes(ColaPacientes& cola, Hospital& hospital, PilaHistorial& historial);

#endif //TALLER_1_ESTRUCTURADEDATOS_MAIN_H
