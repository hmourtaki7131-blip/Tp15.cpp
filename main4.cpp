
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

// Classe Pile generique
template <typename T>
class Pile {
private:
    vector<T> elements;

public:
    // Empiler un element
    void empiler(T element) {
        elements.push_back(element);
    }

    // Depiler un element
    T depiler() {
        if (estVide()) {
            throw runtime_error("Erreur : la pile est vide !");
        }

        T element = elements.back();
        elements.pop_back();

        return element;
    }

    // Retourner le sommet
    T sommet() const {
        if (estVide()) {
            throw runtime_error("Erreur : la pile est vide !");
        }

        return elements.back();
    }

    // Verifier si la pile est vide
    bool estVide() const {
        return elements.empty();
    }

    // Inverser la pile
    void inverser() {
        int debut = 0;
        int fin = elements.size() - 1;

        while (debut < fin) {
            T temp = elements[debut];
            elements[debut] = elements[fin];
            elements[fin] = temp;

            debut++;
            fin--;
        }
    }

    // Afficher la pile
    void afficher() const {
        if (estVide()) {
            cout << "La pile est vide." << endl;
            return;
        }

        cout << "Pile : ";

        for (int i = 0; i < elements.size(); i++) {
            cout << elements[i] << " ";
        }

        cout << endl;
    }
};

// Programme principal
int main() {

    // Test avec int
    cout << "===== PILE INT =====" << endl;

    Pile<int> p1;

    p1.empiler(10);
    p1.empiler(20);
    p1.empiler(30);

    p1.afficher();

    cout << "Sommet : " << p1.sommet() << endl;
    cout << "Element depile : " << p1.depiler() << endl;

    p1.afficher();

    p1.inverser();

    cout << "Apres inversion :" << endl;
    p1.afficher();


    // Test avec string
    cout << "\n===== PILE STRING =====" << endl;

    Pile<string> p2;

    p2.empiler("Ahmed");
    p2.empiler("Sara");
    p2.empiler("Youssef");

    p2.afficher();

    cout << "Element depile : " << p2.depiler() << endl;

    p2.afficher();


    // Test avec double
    cout << "\n===== PILE DOUBLE =====" << endl;

    Pile<double> p3;

    p3.empiler(10.5);
    p3.empiler(20.75);
    p3.empiler(30.25);

    p3.afficher();

    cout << "Sommet : " << p3.sommet() << endl;


    // Test de l'exception
    cout << "\n===== TEST EXCEPTION =====" << endl;

    Pile<int> p4;

    try {
        p4.depiler();
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
