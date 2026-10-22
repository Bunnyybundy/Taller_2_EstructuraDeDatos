

#ifndef TALLER_1_ESTRUCTURADEDATOS_PERSONA_H
#define TALLER_1_ESTRUCTURADEDATOS_PERSONA_H
using namespace std;
#include <string>

class Persona
{
protected:
    string id;
    string nombre;
    int edad;

public:
    Persona();
    Persona(const string& id, const string& nombre, int edad);
    virtual ~Persona();

    string getId() const;
    string getNombre() const;
    int getEdad() const;

    void setNombre(const string& nombre);
    void setEdad(int edad);
    virtual void mostrarInfo() const;
};


#endif //TALLER_1_ESTRUCTURADEDATOS_PERSONA_H
