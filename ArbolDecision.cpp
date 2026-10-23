

#include "ArbolDecision.h"

ArbolDecision::ArbolDecision() {}

string ArbolDecision::determinarServicio(const Paciente& paciente)
{
    if (paciente.getRequiereCirugia())
    {
        return "Cirugia";
    }
    if (paciente.getTrauma() )
    {
        return "Traumatologia";
    }
    if (paciente.getSintomasNeurologicos() )
    {
        return "Neurologia";
    }
    if (paciente.getDiasHospitalizacion() > 0)
    {
        return "Hospitalizacion";
    }
    return "Medicina General";
}