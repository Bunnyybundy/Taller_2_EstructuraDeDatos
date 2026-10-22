cmake_minimum_required(VERSION 3.26)
project(Taller_1_EstructuraDeDatos)

set(CMAKE_CXX_STANDARD 17)

add_executable(Taller_1_EstructuraDeDatos
        main.cpp
        Persona.cpp
        Paciente.cpp
        ColaPacientes.cpp
        PilaHistorial.cpp
        Hospital.cpp
)
