
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

bool Paciente::getRequiereCirugia() const
{
    return requiereCirugia;
}
int Paciente::getDiasHospitalizacion() const
{
    return diasHospitalizacion;
}
bool Paciente::getSintomasNeurologicos() const
{
    return sintomasNeurologicos;
}
string Paciente::getPresionArterial() const
{
    return presionArterial;
}
int Paciente::getDolor() const
{
    return dolor;
}
string Paciente::getTipoDolor() const
{
    return tipoDolor;
}
bool Paciente::getTrauma() const
{
    return trauma;
}
double Paciente::getTemperatura() const
{
    return temperatura;
}


void Paciente::setAtendido(bool valor) { atendido = valor; }

void Paciente::mostrarInfo() const
{
    cout<<"ID: " << id
    << " | nombre:  " << nombre
    << " | Edad: " << edad
    << " | Servicio: " << servicio
    << " | Temperatura:  " << temperatura
    << " | Presion arterial: " << presionArterial
    << " | Dolor: " << dolor
    << " | Tipo de Dolor:  " << tipoDolor
    << " | Trauma: " << (trauma ? "Si" : "No")
    << " | Sintomas neurologicos: " << (sintomasNeurologicos ? "Si" : "No")
    << " | Requiere cirugia:  " << (requiereCirugia ? "Si" : "No")
    << " | Dias hospitalizacion: " << diasHospitalizacion
    << endl ;
}
