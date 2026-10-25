
#include "ArbolDecision.h"
#include "iostream"
using namespace std;

void ArbolDecision::mostrarNodo(Nodo* nodo) const {

    if (nodo->esHoja) {
        cout << nodo->servicio << endl;
    }else {
        cout << "Pregunta: " << textoPregunta(nodo->pregunta) << endl;
    }
}

void ArbolDecision::preorden(Nodo* nodo) const
{
    if (nodo != nullptr)
    {
        return;
    }
    mostrarNodo(nodo);
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
    mostrarNodo(nodo);
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
    mostrarNodo(nodo);
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

string ArbolDecision::textoPregunta(int pregunta) const {
    switch (pregunta) {
        case 1:
            return "Edad < 14?";
        case 2:
            return "RequiereCirugia == 1?";
        case 3:
            return "Trauma == 1?";
        case 4:
            return "SintomasNeurologicos == 1?";
        case 5:
            return "TipoDolor == pecho?";
        case 6:
            return "Temperatura >= 38.5 o Dolor >= 8?";
        case 7:
            return "DiasHospitalizacion >= 2?";
        default:
            return "Pregunta desconocida";
    }
}

string ArbolDecision::textoRespuesta(int pregunta, bool respuesta) const {
    switch (respuesta) {
        case 1:
            return respuesta ? "Edad < 14" : "Edad >= 14";
        case 2:
            return respuesta ? "RequiereCirugia == 1" : "RequiereCirugia == 0";
        case 3:
            return respuesta ? "Trauma == 1" : "Trauma == 0";
        case 4:
            return respuesta ? "SintomasNeurologicos == 1" : "SintomasNeurologicos == 0";
        case 5:
            return respuesta ? "TipoDolor == pecho" : "TipoDolor != pecho";
        case 6:
            return respuesta ? "Temperatura >= 38.5 o Dolor >= 8"
                             : "Temperatura < 38.5 y Dolor < 8";
        case 7:
            return respuesta ? "DiasHospitalizacion >= 2" : "DiasHospitalizacion < 2";
        default:
            return "?";
    }
}

bool ArbolDecision::datosValidos(const Paciente& paciente, string& motivo) {
    if (paciente.getEdad() < 0 || paciente.getEdad() > 120) {
        motivo = "edad fuera de rango (0-120)";
        return false;
    }
    if (paciente.getTemperatura() < 30.0 || paciente.getTemperatura() > 45.0) {
        motivo = "temperatura fuera de rango (30-45)";
        return false;
    }
    if (paciente.getPresionArterial() < 50 || paciente.getPresionArterial() > 250) {
        motivo = "presion arterial fuera de rango (50-250)";
        return false;
    }
    if (paciente.getDolor() < 0 || paciente.getDolor() > 10) {
        motivo = "dolor fuera de rango (0-10)";
        return false;
    }
    string tipo = paciente.getTipoDolor();
    if (tipo != "pecho" && tipo != "cabeza" && tipo != "abdomen" &&
        tipo != "extremidad" && tipo != "otro") {
        motivo = "tipo de dolor no reconocido";
        return false;
    }
    if (paciente.getDiasHospitalizacion() < 0 || paciente.getDiasHospitalizacion() > 365) {
        motivo = "dias de hospitalizacion fuera de rango (0-365)";
        return false;
    }
    return true;
}

bool ArbolDecision::responder(int pregunta, const Paciente& paciente) const {
    switch (pregunta) {
        case 1:
            return paciente.getEdad() < 14;

        case 2:
            return paciente.getRequiereCirugia();

        case 3:
            return paciente.getTrauma();

        case 4:
            return paciente.getSintomasNeurologicos();

        case 5:
            return paciente.getTipoDolor() == "pecho";

        case 6:
            return paciente.getTemperatura() >= 38.5 ||
                   paciente.getDolor() >= 8;

        case 7:
            return paciente.getDiasHospitalizacion() >= 2;

        default:
            return false;
    }
}

string ArbolDecision::determinarServicio(
    const Paciente& paciente, string& ruta) const
{
    ruta = "";

    string motivo;
    if (!datosValidos(paciente, motivo)) {
        ruta = "Datos invalidos: " + motivo;
        return "Datos invalidos";
    }

    Nodo* actual = raiz;

    while (actual != nullptr && !actual->esHoja) {
        if (actual->pregunta < 1 || actual->pregunta > 7) {
            ruta = "Pregunta desconocida";
            return "Datos invalidos";
        }

        bool respuesta = responder(actual->pregunta, paciente);

        if (!ruta.empty()) {
            ruta += " -> ";
        }
        ruta += textoRespuesta(actual->pregunta, respuesta);

        if (respuesta) {
            actual = actual->si;
        }else {
            actual = actual->no;
        }
    }

    if (actual == nullptr) {
        ruta = "Arbol inconsistente";
        return "Datos invalidos";
    }

    return actual->servicio;
}

string ArbolDecision::determinarServicio(
    const Paciente& paciente) const {
    string ruta;
    return determinarServicio(paciente, ruta);
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
