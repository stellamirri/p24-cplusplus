#include <iostream>


class Rational {
    private :                   // créé des variables privées pour que l'utilisateur n'y ai pas accès
        int num;   
        int denom;
    friend Rational operator+(Rational, Rational);  // fonction qui aura accès aux variables privées
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    // constructeur 
    public : 
    Rational(int p = 0, int q = 1) : //syntaxe initialisation, on met p = 0 et q = 1 par défaut si l'utilisateur met pas d'argument. Met 0 et 1 dans les cases crées pour num et dénom.
        num(p), denom(q)   // num = p, denom = q
        {if (q == 0) {throw std::invalid_argument("Le dénominateur ne peut pas être nul.");
        } 
        } //condition, mais même s'il y en n'a pas on met les accolades vides {}.
        
           
        void print()
        {
            std::cout<<num << '/' <<denom<<std::endl;
        }
    float eval() {
        return static_cast<float>(num)/denom; 

    }
    
};


// fonction globale qui fait la somme de deux rationnels, on redéfinit l'opérateur somme pour 2 rationnels comme ça après quand on fera r1 + r2 il donnera la valeur renvoyée par cette fonction.
// problème, num et dénom sont des variables privées. D'où le friend dans la classe.
Rational operator+ (Rational r1, Rational r2) {
    int nv_num = r1.num*r2.denom + r2.num*r1.denom;
    int nv_denom = r1.denom*r2.denom;
    return Rational (nv_num, nv_denom);
}

// fonction globale qui redéfinit l'opérateur << pour qu'il marche avec des éléments de la classe Rational (il marche par défaut qu'avec des types génériques comme les str, les int ou les float, ...)
std::ostream& operator<< (std::ostream& os, const Rational& r) {
    os << r.num << '/' << r.denom;
    return os;
}


int main() {
    Rational r1;
    // 0/1
    Rational r2(1);
    // 1/1
    Rational r3(4, 6);
    // 4/6
    Rational r4(1, 2);
    // 1/2
    Rational r5 = r3 + r4;
    // 4/6 + 1/2 
    r1.print();
    r2.print();
    r3.print();
    r4.print(); 
    std::cout << r3 << "+" << r4 << "=" << r5 << std::endl;
    
    return 0;
}


