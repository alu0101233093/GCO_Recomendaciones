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
    int n_items, n_person, val;

    if (argc == 4){
        std::ifstream fentrada;
        fentrada.open(argv[2], std::ios::in);
        if (!fentrada.is_open())
            std::cout << "No se pudo abrir el fichero\n";
        else{
            std::cout << "Fichero abierto correctamente\n\n";
            fentrada >> n_person;
            fentrada >> n_items;
            Valoraciones V(n_person, n_items);
            for (int i = 0; i < n_person; i++){
                for (int j = 0; j < n_items; j++){
                    fentrada >> val;
                    V.set_persona_item_valor(i,j,val);
                }
            }
        }
    } else
        Ayuda();
}