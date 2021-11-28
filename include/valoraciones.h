#include <vector>
#include <iostream>
#include <stdio.h>

typedef std::vector<std::vector<int>> Matriz;

class Valoraciones {
    private:
        Matriz CI_; // calificaciones - ítems
        int n_; // número de items
        int p_; // número de personas
    public:
        Valoraciones();
        Valoraciones(int, int);
        ~Valoraciones();
        void set_persona_item_valor(int, int, int);
        void set_n(int);
};