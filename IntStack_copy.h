#include <iostream>
#include <stdexcept>
#include <stack>


// on définit un type de donnée (une classe) pour gérer une pile d'entier de taille 12 (SIZE)
class IntStack
{
    int n;    // nombre d'éléments dans ma pile
    int size; // taille de ma pile
    int *tab;

public:
    IntStack(int s);
    IntStack(const IntStack &r);
    IntStack &operator=(const IntStack &r)
    // est appelé lorsque deux objets existants sont affectés l’un à l’autre. Pas de création d'un nouvel objet
    {
        if (this != &r)
        { // on vérif qu'on veut pas assigner un objet à lui-même -> calculs inutiles
            size = r.size;
            n = r.n;
            delete[] tab; // on supp toutes les données de l'objet à qui on assigne r
            tab = new int[size];
            for (int i = 0; i < n; ++i)
            {
                tab[i] = r.tab[i];
            }
        }
        return *this;
    };
    ~IntStack();
    bool is_empty();
    bool is_full();
    void push(int e);
    int get_top();
    int pop();
    void print();
};


