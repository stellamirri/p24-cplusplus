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
    IntStack(int s) :               // définit la fonction intstack dans le cas où l'arguement est un int
                      n(0), size(s) // liste d'initialisation n= 0 et size = s qui est en argument
    {                               // constructeur
        tab = new int[size];
    } // toute la place allouée est détruite quand on sort du constructeur sauf si y'a new ->
    // c'est alors nous qui gérons la place allouée et elle est détruite que quand on lui dit.

    IntStack(const IntStack &r) : // déf la fonction intstack dans le cas où l'arguement est une stack = constructeur de copie
                                  // le constructeur de copie est utilisé lors de l'initialisation d'un objet.
                                  n(r.n), size(r.size) // définit la copie de l'intstack r. ici n, le nombre d'éléments de la nouvelle pile est
    // égale à n, le nombre d'éléments de la pile de r, pile qu'on cherche à copier (n est déf dans le constructeur).
    // L'opération est donc n = r.n (même écriture que r.print() par ex si y'avait une fonction print dans le constructeur.)
    {
        tab = new int[size]; // on crée un nouveau tableau dans notre mémoire dynamique
        // de taille celle du rableau r à copier.
        for (int i = 0; i < n; i++) // on copie élément par élément
        {
            tab[i] = r.tab[i];
        } // tab c'est la copie qu'on veut créer et r.tab c'est le tableau qu'on veut copier.
    }

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
    }

    ~IntStack()
    {                 // destructeur
        delete[] tab; // enlève les infos de la mémoire dynamique
    }

    bool is_empty()
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
    }

    bool is_full()
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
    }

    void push(int e)
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
    }

    int get_top()
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
    }

    int pop()
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
    }
    void print()
    {
        // cette fonction affiche la pile, par exemple
        // [1 2 3 [ pour dire que 3 entiers sont dans la pile
        // le dernier empilé est 3
        std::cout << "[";
        for (int i = 0; i < n; i++)
        {
            std::cout << tab[i] << " " ;
        }
        std::cout << "] ";
    }
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
}
