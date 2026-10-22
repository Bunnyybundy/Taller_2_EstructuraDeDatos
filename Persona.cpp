#include "Persona.h"
#include <iostream>
using namespace std;

Persona::Persona() : id(""), nombre(""), edad(0) {}

Persona::Persona(const string& id, const string& nombre, int edad)
    : id(id), nombre(nombre), edad(edad) {}

Persona::~Persona() {}

string Persona::getId() const { return id; }
string Persona::getNombre() const { return nombre; }
int Persona::getEdad() const { return edad; }

void Persona::setNombre(const string& n) { nombre = n; }
void Persona::setEdad(int e) { edad = e; }

void Persona::mostrarInfo() const
{
    cout<<"ID: " << id << " | Nombre: " << nombre << " | Edad " <<edad << endl;
}
