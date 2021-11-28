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
    p_ = 0;
    n_ = 0;
    CI_.resize(p_);
    for (int i = 0; i < p_; i++)
        CI_[i].resize(n_);
}

Valoraciones::~Valoraciones() {
    std::cout << "vv";
}

void 
Valoraciones::set_persona_item_valor(int person, int item, int val) {
    std::cout << "kk";
}

void 
Valoraciones::set_n(int i) {
    n_ = i;
}
