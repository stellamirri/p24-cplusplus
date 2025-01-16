#include <iostream>
#include <stdexcept>
#include <stack>
#include "IntStack_copy.h"

IntStack::IntStack(int s) : n(0), size(s)
{ // constructeur
    tab = new int[size];
};

IntStack::IntStack(const IntStack &r) : n(r.n), size(r.size)
{
    tab = new int[size];
    for (int i = 0; i < n; i++)
    {
        tab[i] = r.tab[i];
    }
}
IntStack::~IntStack()
{ // destructeur
    delete[] tab;
};

bool IntStack::is_full()
{
    // cette fonction teste si la pile est pleine
    if (n == size)
    {
        return true;
    }
    else
    {
        return false;
    }
};

void IntStack::push(int e)
{
    // cette fonction ajoute l'entier e dans la pile
    //  push(int e)stores e at the top of the stack if the stack is not full
    if (is_full())
    {
        exit(0);
    }
    else
    {
        tab[n] = e;
        n = n + 1;
    }
};

bool IntStack::is_empty()
{
    // cette fonction teste si la pile est vide
    if (n == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    // correction : n == 0;
};

int IntStack::get_top()
{
    // cette fonction retourne le dernier entier empilé
    // get_pop() returns the element on top of the stack if the stack is not empty
    if (is_empty())
    {
        exit(0);
    }
    else
    {
        int a;
        a = tab[n - 1];
        return a;
    }
};

int IntStack::pop()
{
    // cette fonction retourne le dernier entier empilé
    // et supprime cet entier de la pile if the stack is not empty
    if (is_empty())
    {
        exit(0);
    }
    else
    {
        int a;
        a = tab[n - 1];
        n = n - 1;
        return a;
    }
};

void IntStack::print()
{
    // cette fonction affiche la pile, par exemple
    // [1 2 3 [ pour dire que 3 entiers sont dans la pile
    // le dernier empilé est 3
    std::cout << "[";
    for (int i = 0; i < n; i++)
    {
        std::cout << tab[i] << " ";
    }
    std::cout << "] ";
};

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
