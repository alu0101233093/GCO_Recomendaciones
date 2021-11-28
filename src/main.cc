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

    // Lectura y carga de datos
    if (argc == 5){
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
            std::cout << "Relacion: " << V.Pearson(2,0).first << " considerando " << V.Pearson(2,0).second << " items." << std::endl;
            std::cout << "Relacion: " << V.Coseno(2,0).first << " considerando " << V.Coseno(2,0).second << " items." << std::endl;
        }
    } else
        Ayuda();
    // Menu
    /*int opcion = 0;

    do {
        std::cout << "----------------------Menu----------------------\n";
        std::cout << "1. Generar entorno a partir de fichero\n";
        std::cout << "2. Generar entorno con obstaculos aleatorios\n";
        std::cout << "3. Generar entorno de forma manual\n";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                text_fich();
                break;
            case 2:
                text(false);
                break;
            case 3:
                text(true);
                break;
            default:
                std::cout << "Por favor introduzca un numero de los indicados en el menu \n";
                break;
        }
    } while (opcion > 3 || opcion < 1);*/
}