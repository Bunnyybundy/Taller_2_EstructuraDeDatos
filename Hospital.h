
#ifndef TALLER_1_ESTRUCTURADEDATOS_HOSPITAL_H
#define TALLER_1_ESTRUCTURADEDATOS_HOSPITAL_H
#include <iostream>
#include "ArbolAVL.h"
using namespace std;

class Hospital {
private:
    static const int cantidadServicios = 8;

    string nombres[cantidadServicios];
    ArbolAVL* arboles[cantidadServicios];

    int indiceServicio(const string& nombre) const;
    void consultarDepartamento(int indice);

public:
    Hospital();
    ~Hospital();
    Hospital(const Hospital&) = delete;
    Hospital& operator=(const Hospital&) = delete;

    bool existeId(const string& id) const;

    bool insertarPaciente(const Paciente& paciente, const string& servicio);

    void verDepartamentos();
    void buscarPaciente(const string& clave) const;
};

#endif //TALLER_1_ESTRUCTURADEDATOS_HOSPITAL_H
