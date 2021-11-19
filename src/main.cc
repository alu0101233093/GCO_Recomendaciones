#include <fstream>
#include <iostream>
#include "../include/valoraciones.h"

void Ayuda(){
    std::cout << "La sintaxis de los argumentos no es correcta\n";
    std::cout << "Ejemplo:\n";
    std::cout << "estval -i input.txt -o output.txt\n\n";
}

Valoraciones Argumentos(int argc, char** argv){
    Valoraciones V;
    if (argc == 4){
        if (argv[1] == "-i"){
            std::ifstream fentrada(argv[2]);
            if (!fentrada.is_open())
                std::cout << "No se pudo abrir el fichero\n";
            
        } else {
            std::ifstream fentrada(argv[1]);
        }

    } else
        Ayuda();
}

int main (int argc, char *argv[]) {
    Argumentos(argc, argv);
}