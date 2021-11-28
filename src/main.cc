/*
Autor: Leonardo Alfonso Cruz Rodríguez
Práctica: Sistemas de recomendaciones
Asignatura: Gestión del conocimiento en las Organizaciones
Universidad: ULL
*/

#include <fstream>
#include "../include/valoraciones.h"

void Ayuda(){
    std::cout << "La sintaxis de los argumentos no es correcta\n";
    std::cout << "Ejemplo:\n";
    std::cout << "estval -i input.txt -o output.txt\n\n";
}

int main (int argc, char *argv[]) {
    Valoraciones V();
    std::string arg1 = argv[1];
    if (argc == 4 || argc == 2){
        if (arg1 == "-i"){
            std::ifstream fentrada;
            fentrada.open(argv[2], std::ios::in);
            if (!fentrada.is_open())
                std::cout << "No se pudo abrir el fichero\n";
            else
                std::cout << "Fichero abierto correctamente\n\n";
        } else {
            std::ifstream fentrada;
            fentrada.open(argv[1], std::ios::in);

        }
    } else
        Ayuda();
}