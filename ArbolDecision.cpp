
#include "ArbolDecision.h"
#include "iostream"

void ArbolDecision::preorden(Nodo* nodo) const
{
    if (nodo != nullptr)
    {
        return;
    }
    if (nodo->esHoja)
    {
        cout << nodo->servicio << endl;
    }
    else
    {
        cout << "Pregunta" << nodo->pregunta << endl;
    }
    preorden(nodo->si);
    preorden(nodo->no);

}
void ArbolDecision::mostrarPreorden()const
{
    cout << "\nRecorrido preorden:\n" << endl;
    preorden(raiz);
}
void ArbolDecision::inorden(Nodo* nodo) const
{
    if (nodo != nullptr)
    {
        return;
    }
    inorden(nodo->si);

    if (nodo->esHoja)
    {
        cout << nodo->servicio << endl;
    }
    else
    {
        cout << "Pregunta" << nodo->pregunta << endl;
    }
    inorden(nodo->no);
}

void ArbolDecision::postorden(Nodo* nodo) const
{
    if (nodo != nullptr)
    {
        return;
    }
    postorden(nodo->si);
    postorden(nodo->no);

    if (nodo->esHoja)
    {
        cout << nodo->servicio << endl;
    }
    else
    {
        cout << "Pregunta" << nodo->pregunta << endl;
    }
}

void ArbolDecision::mostrarPostorden() const
{
    cout << "\nRecorrido postorden:\n" << endl;
    postorden(raiz);
}

void ArbolDecision::mostrarInorden()const
{
    cout << "\nRecorrido Inorden:\n" << endl;
    inorden(raiz);
}


ArbolDecision::Nodo::Nodo(int pregunta)
{
    this->pregunta = pregunta;
    servicio = "";
    esHoja = false;
    si = nullptr;
    no = nullptr;
}

ArbolDecision::Nodo::Nodo(const string& servicio)
{
    pregunta = 0;
    this->servicio = servicio;
    esHoja = true;
    si = nullptr;
    no = nullptr;
}

ArbolDecision::ArbolDecision()
{
    raiz = construirArbol();
}

ArbolDecision::Nodo* ArbolDecision::construirArbol()
{
    Nodo* edad = new Nodo(1);

    Nodo* cirugia = new Nodo(2);

    Nodo* trauma = new Nodo(3);

    Nodo* neurologia = new Nodo(4);

    Nodo* dolorPecho = new Nodo(5);

    Nodo* urgencias = new Nodo(6);

    Nodo* hospitalizacion = new Nodo(7);

    Nodo* pediatria = new Nodo("Pediatria");
    Nodo* servicioCirugia = new Nodo("Cirugia");
    Nodo* traumatologia = new Nodo("Traumatologia");
    Nodo* servicioNeurologia = new Nodo("Neurologia");
    Nodo* cardiologia = new Nodo("Cardiologia");
    Nodo* servicioUrgencias = new Nodo("Urgencias");
    Nodo* servicioHospitalizacion = new Nodo("Hospitalizacion");
    Nodo* medicinaGeneral = new Nodo("Medicina General");

    edad->si = pediatria;
    edad->no = trauma;

    trauma->si = cirugia;
    trauma->no = neurologia;

    cirugia->si = servicioCirugia;
    cirugia->no = traumatologia;

    neurologia->si = servicioNeurologia;
    neurologia->no = dolorPecho;

    dolorPecho->si = cardiologia;
    dolorPecho->no = urgencias;

    urgencias->si = servicioUrgencias;
    urgencias->no = hospitalizacion;

    hospitalizacion->si = servicioHospitalizacion;
    hospitalizacion->no = medicinaGeneral;

    return edad;
}

string ArbolDecision::determinarServicio(
    const Paciente& paciente) const
{
    Nodo* actual = raiz;

    while (actual != nullptr && !actual->esHoja)
    {
        bool respuesta = false;

        switch (actual->pregunta)
        {
            case 1:
                respuesta = paciente.getEdad() < 14;
                break;

            case 2:
                respuesta = paciente.getRequiereCirugia();
                break;

            case 3:
                respuesta = paciente.getTrauma();
                break;

            case 4:
                respuesta = paciente.getSintomasNeurologicos();
                break;

            case 5:
                respuesta = paciente.getTipoDolor() == "pecho";
                break;

            case 6:
                respuesta =
                    paciente.getTemperatura() >= 38.5 ||
                    paciente.getDolor() >= 8;
                break;

            case 7:
                respuesta = paciente.getDiasHospitalizacion() >= 2;
                break;

            default:
                return "Datos invalidos";
        }

        if (respuesta)
        {
            actual = actual->si;
        }
        else
        {
            actual = actual->no;
        }
    }

    if (actual == nullptr)
    {
        return "Datos invalidos";
    }

    return actual->servicio;
}

void ArbolDecision::liberarArbol(Nodo* nodo)
{
    if (nodo == nullptr)
    {
        return;
    }

    liberarArbol(nodo->si);
    liberarArbol(nodo->no);

    delete nodo;
}

ArbolDecision::~ArbolDecision()
{
    liberarArbol(raiz);
}
