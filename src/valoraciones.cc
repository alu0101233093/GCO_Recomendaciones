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

    // redimensionando matrices
    Mval_.resize(p_);
    CI_.resize(p_);
    for (int i = 0; i < p_; i++)
        CI_[i].resize(n_);
    SP_.resize(p_);
    for (int i = 0; i < p_; i++)
        SP_[i].resize(p_);

    // valor por defecto = -1
    for(int i = 0; i < p_; i++){
        for (int j = 0; j < n_; j++){
            CI_[i][j] = -1;
        }
    }
    for(int i = 0; i < p_; i++){
        for (int j = 0; j < n_; j++){
            SP_[i][j] = 0;
        }
    }
}

Valoraciones::Valoraciones(int p, int n) {
    p_ = p;
    n_ = n;

    // redimensionando matrices
    Mval_.resize(p_);
    CI_.resize(p_);
    for (int i = 0; i < p_; i++)
        CI_[i].resize(n_);
    SP_.resize(p_);
    for (int i = 0; i < p_; i++)
        SP_[i].resize(p_);

    // valor por defecto = 0
    for(int i = 0; i < p_; i++){
        for (int j = 0; j < n_; j++){
            CI_[i][j] = -1;
        }
    }
    for(int i = 0; i < p_; i++){
        for (int j = 0; j < n_; j++){
            SP_[i][j] = 0;
        }
    }
}

Valoraciones::~Valoraciones() {
}

void 
Valoraciones::set_persona_item_valor(int person, int item, int val) {
    CI_[person][item] = val;

    int suma = 0,count = 0;
    for(int i = 0; i < n_; i++){
        if(CI_[person][i] != -1){
            suma += CI_[person][i];
            count++;
        }
    }
    if(count != 0)
    Mval_[person] = suma/count;
}

void
Valoraciones::imprimir_matriz() {
    std::cout << "\n\n";
    for(int i = 0; i < p_; i++){
        for (int j = 0; j < n_; j++){
            if(CI_[i][j] != -1)
                std::cout << CI_[i][j] << " ";
            else
                std::cout << "- ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}

std::pair<float,int>
Valoraciones::Pearson(int u, int v) {
    float num = 0, den1 = 0, den2 = 0;
    std::pair<float,int> val_num; // valor y número de items considerados
    int num_items = n_;

    // numerador
    for(int i = 0; i < n_; i++){
        if (CI_[u][i] != -1 && CI_[v][i] != -1)
            num += (CI_[u][i] - Mval_[u])*(CI_[v][i] - Mval_[v]);
        else
            num_items--;
    }

    // denominador izquierda
    for(int i = 0; i < n_; i++){
        if(CI_[u][i] != -1)
            den1 += pow((CI_[u][i] - Mval_[u]), 2);
    }
    den1 = sqrt(den1);

    // denominador derecha
    for(int i = 0; i < n_; i++){
        if(CI_[v][i] != -1)
            den2 += pow((CI_[v][i] - Mval_[v]), 2);
    }
    den2 = sqrt(den2);

    val_num.first = (num/(den1*den2));
    val_num.second = num_items;
    return val_num;
}

std::pair<float,int>
Valoraciones::Coseno(int u, int v) {
    float num = 0, den1 = 0, den2 = 0;
    std::pair<float,int> val_num; // valor y número de items considerados
    int num_items = n_;

    // numerador
    for(int i = 0; i < n_; i++){
        if (CI_[u][i] != -1 && CI_[v][i] != -1)
            num += (CI_[u][i]*CI_[v][i]);
        else
            num_items--;
    }

    // denominador izquierda
    for(int i = 0; i < n_; i++){
        if(CI_[u][i] != -1)
            den1 += pow(CI_[u][i], 2);
    }
    den1 = sqrt(den1);

    // denominador derecha
    for(int i = 0; i < n_; i++){
        if(CI_[v][i] != -1)
            den2 += pow(CI_[v][i], 2);
    }
    den2 = sqrt(den2);

    val_num.first = (num/(den1*den2));
    val_num.second = num_items;
    return val_num;
}