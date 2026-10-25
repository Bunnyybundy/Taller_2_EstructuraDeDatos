cmake_minimum_required(VERSION 3.20)
project(Taller_2_EstructuraDeDatos)

set(CMAKE_CXX_STANDARD 17)

add_executable(Taller_2_EstructuraDeDatos
        main.cpp
        Persona.cpp
        Paciente.cpp
        ColaPacientes.cpp
        Hospital.cpp
        ArbolDecision.cpp
        ArbolDecision.h
        NodoAVL.cpp
        NodoAVL.h
        ArbolAVL.cpp
        ArbolAVL.h
        Utilidades.h
        Utilidades.cpp
)
