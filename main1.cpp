
#include <iostream>
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

// Classe ListeChainee
class ListeChainee {
private:
    Noeud* tete;

public:
    // Constructeur
    ListeChainee() {
        tete = nullptr;
    }

    // Ajouter au debut
    void ajouterDebut(int valeur) {
        Noeud* nouveau = new Noeud(valeur);
        nouveau->suivant = tete;
        tete = nouveau;
    }

    // Ajouter a la fin
    void ajouterFin(int valeur) {
        Noeud* nouveau = new Noeud(valeur);

        if (tete == nullptr) {
            tete = nouveau;
            return;
        }

        Noeud* courant = tete;

        while (courant->suivant != nullptr) {
            courant = courant->suivant;
        }

        courant->suivant = nouveau;
    }

    // Supprimer une valeur
    void supprimer(int valeur) {
        if (tete == nullptr) {
            return;
        }

        if (tete->valeur == valeur) {
            Noeud* temp = tete;
            tete = tete->suivant;
            delete temp;
            return;
        }

        Noeud* courant = tete;

        while (courant->suivant != nullptr &&
               courant->suivant->valeur != valeur) {
            courant = courant->suivant;
        }

        if (courant->suivant != nullptr) {
            Noeud* temp = courant->suivant;
            courant->suivant = temp->suivant;
            delete temp;
        }
    }

    // Afficher la liste
    void afficher() const {
        Noeud* courant = tete;

        while (courant != nullptr) {
            cout << courant->valeur << " -> ";
            courant = courant->suivant;
        }

        cout << "NULL" << endl;
    }

    // Retourner la taille
    int taille() const {
        int compteur = 0;
        Noeud* courant = tete;

        while (courant != nullptr) {
            compteur++;
            courant = courant->suivant;
        }

        return compteur;
    }

    // Iterateur personnalise
    class Iterator {
    private:
        Noeud* courant;

    public:
        Iterator(Noeud* n) {
            courant = n;
        }

        int& operator*() {
            return courant->valeur;
        }

        Iterator& operator++() {
            courant = courant->suivant;
            return *this;
        }

        bool operator!=(const Iterator& autre) const {
            return courant != autre.courant;
        }
    };

    Iterator begin() {
        return Iterator(tete);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    // Destructeur
    ~ListeChainee() {
        Noeud* courant = tete;

        while (courant != nullptr) {
            Noeud* temp = courant;
            courant = courant->suivant;
            delete temp;
        }
    }

    // Eviter la copie superficielle
    ListeChainee(const ListeChainee&) = delete;
    ListeChainee& operator=(const ListeChainee&) = delete;
};

// Programme principal
int main() {
    ListeChainee liste;

    liste.ajouterDebut(20);
    liste.ajouterDebut(10);
    liste.ajouterFin(30);
    liste.ajouterFin(40);

    cout << "Liste initiale : ";
    liste.afficher();

    cout << "Taille : " << liste.taille() << endl;

    liste.supprimer(20);

    cout << "\nApres suppression de 20 : ";
    liste.afficher();

    cout << "Nouvelle taille : " << liste.taille() << endl;

    cout << "\nParcours avec Iterator : ";
    for (int valeur : liste) {
        cout << valeur << " ";
    }

    cout << endl;

    return 0;
}
