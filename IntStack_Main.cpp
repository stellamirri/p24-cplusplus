#include <iostream>
#include <stdexcept>
#include <stack>
#include "IntStack.h"

int main()
{
    IntStack s(120); // crée une pile s dans la pile d'éxecution de taille 120.
    IntStack i(10);
    IntStack j(i); // j = copie de la stack i, pas besoin d'initialiser j
    IntStack k(20);
    i.push(12);
    k.operator=(i); // On affecte i à k : besoin d'initialisation
    i.print();
    j.print();
    k.print();
    return 0;
};
