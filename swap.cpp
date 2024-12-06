# include <iostream>

//swap avec des pointeurs :
void swap1(int * pa, int * pb) {
    int t = (*pa);
    *pa = *pb;
    *pb = t;
}

//swap avec des références : 
void swap2(int& a, int& b) {      //on rajoute des références en paramètres
//de la fonction comme ça les valeurs d'origine sont effectivement 
//changées et c'est pas juste des copies qui sont créées.
    int t = a;
    a = b;
    b = t;
}

int main() {
    int a = 82;
    int b = -72;
    swap2(a, b);
    std:: cout << a << ' ' << b << std::endl;
    return 0;
}

//int main1() {
//    int a = 82;
//    int b = -72;
//    int * pa = &a;
//    int * pb = &b;
//    swap1(pa,pb);
//    std:: cout << a << ' ' << b << std::endl;
//    return 0;
//}




