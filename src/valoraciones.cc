/*
Autor: Leonardo Alfonso Cruz Rodríguez
Práctica: Sistemas de recomendaciones
Asignatura: Gestión del conocimiento en las Organizaciones
Universidad: ULL
*/

#include "../include/valoraciones.h"

Valoraciones::Valoraciones() {
    p_ = 0;
    n_ = 0;
    CI_.resize(p_);
    for (int i = 0; i < p_; i++)
        CI_[i].resize(n_);
}

Valoraciones::Valoraciones(int p, int n) {
    p_ = p;
    n_ = n;
    CI_.resize(p_);
    for (int i = 0; i < p_; i++)
        CI_[i].resize(n_);
}

Valoraciones::~Valoraciones() {
}

void 
Valoraciones::set_persona_item_valor(int person, int item, int val) {
    CI_[person][item] = val;
}

void
Valoraciones::imprimir_matriz() {
    std::cout << "\n\n";
    for(int i = 0; i < p_; i++){
        for (int j = 0; j < n_; j++){
            std::cout << CI_[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}
