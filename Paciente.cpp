
#include "Paciente.h"
#include <iostream>

using namespace std;

Paciente::Paciente() : Persona(), servicio(""), atendido(false) {}

Paciente::Paciente(const string& id, const string& nombre, int edad, const string& servicio)
    : Persona(id, nombre, edad), servicio(servicio), atendido(false) {}

Paciente::~Paciente() {}

string Paciente::getServicio() const { return servicio; }
void Paciente::setServicio(const string& s) { servicio = s;}

bool Paciente::getAtendido() const { return atendido; }
void Paciente::setAtendido(bool valor) { atendido = valor; }

void Paciente::mostrarInfo() const
{
    cout<<"ID: " << id << " | nombre:  " << nombre << " | Edad: " << edad << " | Servicio: " << servicio << endl ;
}
