

#ifndef TALLER_1_ESTRUCTURADEDATOS_PACIENTE_H
#define TALLER_1_ESTRUCTURADEDATOS_PACIENTE_H

#include "Persona.h"
#include <string>
using namespace std;

class Paciente : public Persona
{
private:
    string servicio;
    bool atendido;

    //Datos clinicos del paciente
    double temperatura;
    string presionArterial;
    int dolor;
    string tipoDolor;
    bool trauma;
    bool sintomasNeurologicos;
    bool requiereCirugia;
    int diasHospitalizacion;

public:
    Paciente();
    Paciente(const string& id, const string& nombre, int edad, const string& servicio);
    ~Paciente();

    string getServicio() const;
    void setServicio(const string& servicio);

    bool getAtendido() const;
    void setAtendido(bool valor);

    double getTemperatura() const;
    void setTemperatura(double valor);

    string getPresionArterial() const;
    void setPresionArterial(string valor);

    int getDolor() const;
    void setDolor(int valor);

    string getTipoDolor() const;
    void setTipoDolor(string valor);

    bool getTrauma() const;
    void setTrauma(bool valor);

    bool getSintomasNeurologicos() const;
    void setSintomasNeurologicos(bool valor);

    bool getRequiereCirugia() const;
    void setRequiereCirugia(bool valor);

    int getDiasHospitalizacion() const;
    void setDiasHospitalizacion(int valor);

    void mostrarInfo() const override;
};


#endif //TALLER_1_ESTRUCTURADEDATOS_PACIENTE_H
