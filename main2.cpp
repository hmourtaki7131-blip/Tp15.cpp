
#include <iostream>
#include <stdexcept>
using namespace std;

// Classe Noeud
class Noeud {
public:
    int valeur;
    Noeud* suivant;

    Noeud(int v) {
        valeur = v;
        suivant = nullptr;
    }
};

// Classe File
class File {
private:
    Noeud* debut;
    Noeud* fin;

public:
    // Constructeur
    File() {
        debut = nullptr;
        fin = nullptr;
    }

    // Verifier si la file est vide
    bool estVide() const {
        return debut == nullptr;
    }

    // File dynamique : pas de capacite fixe
    bool estPleine() const {
        return false;
    }

    // Ajouter un element
    void enfiler(int valeur) {
        Noeud* nouveau = new Noeud(valeur);

        if (estVide()) {
            debut = nouveau;
            fin = nouveau;
        } else {
            fin->suivant = nouveau;
            fin = nouveau;
        }

        cout << valeur << " ajoute a la file." << endl;
    }

    // Retirer un element
    int defiler() {
        if (estVide()) {
            throw runtime_error("Impossible : la file est vide !");
        }

        Noeud* temp = debut;
        int valeur = temp->valeur;

        debut = debut->suivant;

        if (debut == nullptr) {
            fin = nullptr;
        }

        delete temp;
        return valeur;
    }

    // Afficher la file
    void afficher() const {
        if (estVide()) {
            cout << "La file est vide." << endl;
            return;
        }

        Noeud* courant = debut;

        cout << "File : ";

        while (courant != nullptr) {
            cout << courant->valeur << " ";
            courant = courant->suivant;
        }

        cout << endl;
    }

    // Destructeur
    ~File() {
        while (!estVide()) {
            Noeud* temp = debut;
            debut = debut->suivant;
            delete temp;
        }

        fin = nullptr;
    }

    // Eviter la copie superficielle
    File(const File&) = delete;
    File& operator=(const File&) = delete;
};

// Programme principal
int main() {
    File f;
    int choix, valeur;

    do {
        cout << "\n===== MENU FILE =====" << endl;
        cout << "1. Enfiler" << endl;
        cout << "2. Defiler" << endl;
        cout << "3. Afficher la file" << endl;
        cout << "4. Verifier si la file est vide" << endl;
        cout << "5. Quitter" << endl;

        cout << "Votre choix : ";
        cin >> choix;

        try {
            switch (choix) {
                case 1:
                    cout << "Donner une valeur : ";
                    cin >> valeur;
                    f.enfiler(valeur);
                    break;

                case 2:
                    cout << "Element retire : "
                         << f.defiler() << endl;
                    break;

                case 3:
                    f.afficher();
                    break;

                case 4:
                    if (f.estVide()) {
                        cout << "La file est vide." << endl;
                    } else {
                        cout << "La file n'est pas vide." << endl;
                    }
                    break;

                case 5:
                    cout << "Fin du programme." << endl;
                    break;

                default:
                    cout << "Choix invalide !" << endl;
            }
        }
        catch (const exception& e) {
            cout << "Erreur : " << e.what() << endl;
        }

    } while (choix != 5);

    return 0;
}
