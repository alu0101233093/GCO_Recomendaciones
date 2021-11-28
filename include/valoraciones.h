#include <vector>
#include <iostream>
#include <stdio.h>
#include <math.h>

typedef std::vector<std::vector<int>> Matriz;

class Valoraciones {
    private:
        Matriz CI_; // calificaciones - ítems
        Matriz SP_; // similitud - personas
        std::vector<float> Mval_; // Media valoraciones
        int n_; // número de items
        int p_; // número de personas
    public:
        Valoraciones();
        Valoraciones(int, int);
        ~Valoraciones();
        void set_persona_item_valor(int, int, int);
        void imprimir_matriz();
        std::pair<float,int> Pearson(int,int);
        std::pair<float,int> Coseno(int,int);
};