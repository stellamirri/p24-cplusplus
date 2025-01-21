#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <stack>
#include <queue>

// Classe qui définit la matrice d'adjacence associée au graphe. Renvoie une matrice d'adjacence dont les coefficients sont les poids des arrêtes.
class Graph_mat
{
private:
    int n;                                     // nombre de sommets
    std::vector<std::vector<int>> matrice_adj; // déf d'une matrice
public:
    Graph_mat(int nb_sommets) : n(nb_sommets), matrice_adj(n, std::vector<int>(n, 0)) {};
    // la matrice d'adjacence est un vecteur contenant n vecteurs de dimension n.
    // on initialise notre objet matrice à n éléments pour le premier vecteur et on dit que ses éléments qui
    // sont eux mêmes des vecteurs sont eux aussi de dimension n et on les initialise à 0
    void addEdge(int start, int end, int weight)
    {
        matrice_adj[start][end] = weight;
    };

    void printGraph()
    {
        int i;
        int j;
        std::cout << "représentation en matrice d'adjacence :";
        std::cout<<std::endl;
        for (i = 0; i < n; i++)
        {
            std::cout << "[";
            for (j = 0; j < n; j++)
            {
                std::cout << matrice_adj[i][j] << " ";
            }
            std::cout << "]";
            std::cout << std::endl;
        }
    };

    void dfsbis_rec(int k, std::vector<bool> &visit_bool, std::vector<int> &sens_de_visite, std::vector<std::pair<int, int>> &parcours_de_visite)
    {
        int l;
        visit_bool[k] = true;
        sens_de_visite.push_back(k);
        for (l = 0; l < n; l++)
        {
            if (matrice_adj[k][l] != 0 and visit_bool[l] == false)
            {
                parcours_de_visite.push_back(std::make_pair(k, l));
                dfsbis_rec(l, visit_bool, sens_de_visite, parcours_de_visite);
            }
        }
    };

    void dfs_rec()
    {
        int k;
        std::vector<bool> visit_bool(n, false);
        std::vector<int> sens_de_visite;
        std::vector<std::pair<int, int>> parcours_de_visite; // enregistre les arêtes explorées dans l'ordre et sous forme de paires
        for (k = 0; k < n; k++)                              // on parcourt les sommets
        {
            if (visit_bool[k] == false)
            {
                dfsbis_rec(k, visit_bool, sens_de_visite, parcours_de_visite);
            }
        }
        std::cout << "Implémentation en matrice d'adjacence, parcours en profondeur récursif : Dans l'ordre, les sommets visités ont été : ";
        for (int v : sens_de_visite)
        {
            std::cout << v << " ";
        }
        std::cout << "et la trajectoire suivie : ";
        for (std::pair<int, int> v : parcours_de_visite)
        {
            std::cout << "(" << v.first << "," << v.second << ")" << " ";
        }
        std::cout << std::endl;
    };
    void dfs_rec(int s)
    {
        std::vector<bool> visit_bool(n, false);
        std::vector<int> sens_de_visite;
        std::vector<std::pair<int, int>> parcours_de_visite; // enregistre les arêtes explorées dans l'ordre et sous forme de paires

        dfsbis_rec(s, visit_bool, sens_de_visite, parcours_de_visite);

        std::cout << "Implémentation en matrice d'adjacence, parcours en profondeur récursif : Dans l'ordre en partant du sommet " << s << ", les sommets visités ont été : ";
        for (int v : sens_de_visite)
        {
            std::cout << v << " ";
        }
        std::cout << "et la trajectoire suivie : ";
        for (std::pair<int, int> v : parcours_de_visite)
        {
            std::cout << "(" << v.first << "," << v.second << ")" << " ";
        }
        std::cout << std::endl;
    };

    void dfs_it(int a)
    {
        std::stack<int> stack;
        std::vector<bool> visit_bool(n, false);
        std::vector<int> sens_de_visite;
        int l;
        int k;
        stack.push(a);
        while (!stack.empty())
        {
            k = stack.top();
            stack.pop();
            if (!visit_bool[k])
            {
                visit_bool[k] = true;
                sens_de_visite.push_back(k);
            }
            for (l = 0; l < n; l++)
            {
                if (matrice_adj[k][l] != 0 and visit_bool[l] == false)
                {
                    stack.push(l);
                }
            }
        }
        std::cout << "Implémentation en matrice d'adjacence, parcours en profondeur itératif : Dans l'ordre en partant du sommet " << a << ", les sommets visités ont été : ";
        for (int v : sens_de_visite)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    void bfs(int a)
    {
        std::queue<int> fifo;
        std::vector<bool> visit_bool(n, false);
        std::vector<int> sens_de_visite;
        int l;
        int k;
        fifo.push(a);
        while (!fifo.empty())
        {
            k = fifo.front();
            fifo.pop();
            if (!visit_bool[k])
            {
                visit_bool[k] = true;
                sens_de_visite.push_back(k);
            }
            for (l = 0; l < n; l++)
            {
                if (matrice_adj[k][l] != 0 and visit_bool[l] == false)
                {
                    fifo.push(l);
                }
            }
        }
        std::cout << "Implémentation en matrice d'adjacence, parcours en largeur : Dans l'ordre en partant du sommet " << a << ", les sommets visités ont été : ";
        for (int v : sens_de_visite)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
};

// Classe de la liste d'adjecence. Renvoie 1 liste L qui en contient n. Chaque terme L[i] est une liste contenant les sommets adjacents et leurs poids respectifs
class Graph_liste
{
private:
    int n;                                                   // nombre de sommets
    std::vector<std::vector<std::pair<int, int>>> liste_adj; // déf d'une liste d'adjacence
public:
    Graph_liste(int nb_sommets) : n(nb_sommets), liste_adj(n) {};
    // on initialise la liste d'adjacence à une liste contenant n listes vides.
    void addEdge(int predecesseur, int successeur, int weight)
    {
        liste_adj[predecesseur].push_back(std::make_pair(successeur, weight));
        // on ajoute à la liste associée à un sommet le tuple (sommet associé, poids de l'arrête)
    };

    void printGraph()
    {
        int i;
        std::pair<int, int> j;
        std::cout << "représentation en liste d'adjacence :";
        std::cout<<std::endl;
        for (i = 0; i < n; i++)
        {
            std::cout << "[";
            for (auto j : liste_adj[i])
            {
                std::cout << "(" << j.first << "," << j.second << ")";
            }
            std::cout << "]";
        };
        std::cout << std::endl;
    };

    void dfsbis_rec(int k, std::vector<bool> &visit_bool, std::vector<int> &sens_de_visite, std::vector<std::pair<int, int>> &parcours_de_visite)
    {
        int s;
        int w;
        visit_bool[k] = true;
        sens_de_visite.push_back(k);
        for (auto l : liste_adj[k])
        {
            s = l.first;
            w = l.second;
            if (visit_bool[s] == false)
            {
                parcours_de_visite.push_back(std::make_pair(k, s));
                dfsbis_rec(s, visit_bool, sens_de_visite, parcours_de_visite);
            }
        }
    };

    void dfs_rec()
    {
        int k;
        std::vector<bool> visit_bool(n, false);
        std::vector<int> sens_de_visite;
        std::vector<std::pair<int, int>> parcours_de_visite; // enregistre les arêtes explorées dans l'ordre et sous forme de paires
        for (k = 0; k < n; k++)                              // on parcourt les sommets
        {
            if (visit_bool[k] == false)
            {
                dfsbis_rec(k, visit_bool, sens_de_visite, parcours_de_visite);
            }
        }
        std::cout << "Implémentation en liste d'adjacence, parcours en profondeur récursif : Dans l'ordre, les sommets visités ont été : ";
        for (int v : sens_de_visite)
        {
            std::cout << v << " ";
        }
        std::cout << "et la trajectoire suivie : ";
        for (std::pair<int, int> v : parcours_de_visite)
        {
            std::cout << "(" << v.first << "," << v.second << ")" << " ";
        }
        std::cout << std::endl;
    };

    void dfs_rec(int s)
    {
        std::vector<bool> visit_bool(n, false);
        std::vector<int> sens_de_visite;
        std::vector<std::pair<int, int>> parcours_de_visite; // enregistre les arêtes explorées dans l'ordre et sous forme de paires

        dfsbis_rec(s, visit_bool, sens_de_visite, parcours_de_visite);

        std::cout << "Implémentation en liste d'adjacence, parcours en profondeur récursif : Dans l'ordre en partant du sommet " << s << ", les sommets visités ont été : ";
        for (int v : sens_de_visite)
        {
            std::cout << v << " ";
        }
        std::cout << "et la trajectoire suivie : ";
        for (std::pair<int, int> v : parcours_de_visite)
        {
            std::cout << "(" << v.first << "," << v.second << ")" << " ";
        }
        std::cout << std::endl;
    };

    void dfs_it(int a)
    {
        std::stack<int> stack;
        std::vector<bool> visit_bool(n, false);
        std::vector<int> sens_de_visite;
        int s;
        int w;
        int k;
        stack.push(a);
        while (!stack.empty())
        {
            k = stack.top();
            stack.pop();
            if (!visit_bool[k])
            {
                visit_bool[k] = true;
                sens_de_visite.push_back(k);
            }
            for (auto l : liste_adj[k])
            {
                s = l.first;
                w = l.second;
                if (!visit_bool[s])
                {
                    stack.push(s);
                }
            }
        }
        std::cout << "Implémentation en liste d'adjacence, parcours en profondeur itératif : Dans l'ordre en partant du sommet " << a << ", les sommets visités ont été : ";
        for (int v : sens_de_visite)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    void bfs(int a)
    {
        std::queue<int> fifo;
        std::vector<bool> visit_bool(n, false);
        std::vector<int> sens_de_visite;
        int s;
        int w;
        int k;
        fifo.push(a);
        while (!fifo.empty())
        {
            k = fifo.front();
            fifo.pop();
            if (!visit_bool[k])
            {
                visit_bool[k] = true;
                sens_de_visite.push_back(k);
            }
            for (auto l : liste_adj[k])
            {
                s = l.first;
                w = l.second;
                if (!visit_bool[s])
                {
                    fifo.push(s);
                }
            }
        }
        std::cout << "Implémentation en liste d'adjacence, parcours en largeur : Dans l'ordre en partant du sommet " << a << ", les sommets visités ont été : ";
        for (int v : sens_de_visite)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
};

// exemple d'un main
int main()
{
    Graph_mat g(4);
    Graph_liste f(4);
    g.addEdge(1, 2, 100);
    g.addEdge(1, 3, 150);
    g.addEdge(2, 0, 80);
    g.addEdge(3, 0, 70);
    g.addEdge(0, 1, 200);
    g.printGraph();
    f.addEdge(1, 2, 100);
    f.addEdge(1, 3, 150);
    f.addEdge(2, 0, 80);
    f.addEdge(3, 0, 70);
    f.addEdge(0, 1, 200);
    f.printGraph();

    g.dfs_rec(); // parcours du graphe en profondeur d'abord
                 // depth first search

    f.dfs_rec();

    g.dfs_rec(1);
    f.dfs_rec(1);
    g.dfs_it(1);
    f.dfs_it(1);

    // je n'obtiens pas le même sens de visite pour les parcours en profondeur itératif et récursif, je pense que c'est lié à comment mes sommets s'empilent dans ma pile (fonction itérative) mais je ne vois pazs trop comment changer cela.

    g.bfs(1);
    f.bfs(1); // parcours du graphe en largeur d'abord
              // breath first search

    return 0;
}