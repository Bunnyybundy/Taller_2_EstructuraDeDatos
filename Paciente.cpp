
#include "Paciente.h"
#include <iostream>

using namespace std;

Paciente::Paciente() : Persona(), servicio(""), atendido(false), temperatura(0.0), presionArterial(0),
      dolor(0), tipoDolor("otro"), trauma(false), sintomasNeurologicos(false),
      requiereCirugia(false), diasHospitalizacion(0) {}

Paciente::Paciente(const string& id, const string& nombre, int edad, const string& servicio)
: Persona(id, nombre, edad), servicio(servicio), atendido(false), temperatura(0.0), presionArterial(0),
  dolor(0), tipoDolor("otro"), trauma(false), sintomasNeurologicos(false),
  requiereCirugia(false), diasHospitalizacion(0) {}

Paciente::~Paciente() {}

string Paciente::getServicio() const { return servicio; }
void Paciente::setServicio(const string& s) { servicio = s;}

bool Paciente::getAtendido() const { return atendido; }
void Paciente::setAtendido(bool valor) { atendido = valor; }

double Paciente::getTemperatura() const { return temperatura; }
void Paciente::setTemperatura(double valor) { temperatura = valor; }

int Paciente::getPresionArterial() const { return presionArterial; }
void Paciente::setPresionArterial(int valor) { presionArterial = valor; }

int Paciente::getDolor() const { return dolor; }
void Paciente::setDolor(int valor) { dolor = valor; }

string Paciente::getTipoDolor() const { return tipoDolor; }
void Paciente::setTipoDolor(const string& valor) { tipoDolor = valor; }

bool Paciente::getTrauma() const { return trauma; }
void Paciente::setTrauma(bool valor) { trauma = valor; }

bool Paciente::getSintomasNeurologicos() const { return sintomasNeurologicos; }
void Paciente::setSintomasNeurologicos(bool valor) { sintomasNeurologicos = valor; }

bool Paciente::getRequiereCirugia() const { return requiereCirugia; }
void Paciente::setRequiereCirugia(bool valor) { requiereCirugia = valor; }

int Paciente::getDiasHospitalizacion() const { return diasHospitalizacion; }
void Paciente::setDiasHospitalizacion(int valor) { diasHospitalizacion = valor; }

void Paciente::mostrarInfo() const
{
    cout<<"ID: " << id
    << " | nombre:  " << nombre
    << " | Edad: " << edad
    << " | Servicio: " << (servicio.empty() ? "Sin asignar" : servicio)
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

void Paciente::mostrarFicha() const {

    cout << "-------" << endl;
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Departamento: " << servicio << endl;
    cout.setf(ios::fixed);
    cout.precision(1);
    cout << "T: " << temperatura << " | ";
    cout.unsetf(ios::fixed);
    cout.precision(6);
    cout << "D: " << dolor
         << " | TD: " << tipoDolor
         << " | T: " << (trauma ? "Si" : "No")
         << " | SN: " << (sintomasNeurologicos ? "Si" : "No")
         << " | RC: " << (requiereCirugia ? "Si" : "No")
         << " | DH: ";
    if (diasHospitalizacion == 0) cout << "Ninguno";
    else cout << diasHospitalizacion << " dias";
    cout << endl;
    cout << "-------" << endl;
}
