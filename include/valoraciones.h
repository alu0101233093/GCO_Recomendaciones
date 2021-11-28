#include <vector>
#include <iostream>
#include <stdio.h>

typedef std::vector<std::vector<int>> Matriz;

class Valoraciones {
    private:
        Matriz CI_; // calificaciones - ítems
    public:
        Valoraciones();
        ~Valoraciones();
        void set_person(std::vector<int>);
};