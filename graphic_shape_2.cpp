// Pour le cours du 14 janvier 2025 faire fonctionner ce code suivant:
// (j'ai enlevé l'attribut color mais vous pouvez le remettre si vous voulez)

// inclusion des bibliothèques standard ici
#include <vector>
#include <iostream>

// définition de vos classes ici

class Shape
{
    int abscisse;
    int ordonnee;

public:
    Shape(int x, int y) : abscisse(x), ordonnee(y) {}

    virtual void move(int x_new, int y_new)
    {
        abscisse = x_new;
        ordonnee = y_new;
    };

    virtual double area()
    {
        return 0;
    };

    virtual bool is_at_position(int x, int y)
    {
        return abscisse == x && ordonnee == y;
    }
};

class Circle : public Shape
{
    double radius; // argument supplémentaire spécifique à Circle

public:
    Circle(int x, int y, double r) : Shape(x, y), radius(r) {}

    double area() override
    {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape
{
    int height;
    int width;

public:
    Rectangle(int x, int y, int w, int h) : Shape(x, y), width(w), height(h) {}

    double area() override
    {
        return height * width;
    }
};

class Square : public Shape
{
    int side;

public:
    Square(int x, int y, int s) : Shape(x, y), side(s) {}

    double area() override
    {
        return side * side;
    }
};

// optionnel:
// faire une fonction prend en argument x, y et un vecteur de formes et retourne la forme au point (x, y)

Shape *find_at_position(int x, int y, std::vector<Shape *> shapes)
{
    // dans cette fonction vous avez besoin de tester si une forme est au point (x, y)
    // pour faire cela sans mettre cette fonction friend, ajouter en plus de move et area
    // une méthode bool is_at_position(int x, int y)
    for (Shape *s : shapes) // on parcourt les vecteurs de shapes
    {
        if (s->is_at_position(x, y)) // on renvoie s à la méthode contenu dans la classe de base shapes d'où le ->
        {
            return s;
        }
    }
    return nullptr;
};

int main()
{
    Circle c{10, 20, 4.5};       // x, y, radius
    Rectangle r{20, 30, 30, 60}; // x, y, width, height
    Shape *pc = &c;
    Shape *pr = &r;
    std::vector<Shape *> shapes;
    shapes.push_back(&c);
    shapes.push_back(&r);

    // deuxième version (avec find_at_position et is_at_position)
    Shape *shape1 = find_at_position(10, 20, shapes);
    if (shape1)
    {
        std::cout << "Aire de la forme trouvée : " << shape1->area() << std::endl;
        shape1->move(1, 2);
    }
    else
    {
        std::cout << "Aucune forme trouvée aux coordonnées données." << std::endl;
    }
    //  appeler la méthode move et area sur shape1
    Shape *shape2 = find_at_position(100, 200, shapes);
    if (shape2)
    {
        std::cout << "Aire de la forme trouvée : " << shape2->area() << std::endl;
        shape2->move(1, 2);
    }
    else
    {
        std::cout << "Aucune forme trouvée aux coordonnées données." << std::endl;
    }
    //  pouvez vous appeler la méthode move et area sur shape2 ?
    // non car aucune forme n'a été trouvée aux coordonnées données.

    // première version (sans find_at_position et is_at_position)
    shapes[0]->move(4, 6);
    shapes[1]->move(2, 8);
    std::cout << shapes[0]->area() << std::endl; // affiche dans les 63.6173
    std::cout << shapes[1]->area() << std::endl; // 1800

    return 0;
}