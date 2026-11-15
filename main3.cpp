
#include <iostream>
#include <string>
using namespace std;

// Classe Noeud
class Noeud {
public:
    int cle;
    string valeur;
    Noeud* suivant;

    Noeud(int c, string v) {
        cle = c;
        valeur = v;
        suivant = nullptr;
    }
};

// Classe TableHachage
class TableHachage {
private:
    static const int TAILLE = 5;
    Noeud* table[TAILLE];

    // Fonction de hachage
    int hachage(int cle) const {
        return cle % TAILLE;
    }

public:
    // Constructeur
    TableHachage() {
        for (int i = 0; i < TAILLE; i++) {
            table[i] = nullptr;
        }
    }

    // Inserer une paire cle-valeur
    void inserer(int cle, string valeur) {
        int indice = hachage(cle);
        Noeud* courant = table[indice];

        // Verifier si la cle existe deja
        while (courant != nullptr) {
            if (courant->cle == cle) {
                courant->valeur = valeur;
                cout << "Valeur mise a jour." << endl;
                return;
            }

            courant = courant->suivant;
        }

        // Ajouter un nouveau noeud
        Noeud* nouveau = new Noeud(cle, valeur);
        nouveau->suivant = table[indice];
        table[indice] = nouveau;

        cout << "Element insere." << endl;
    }

    // Rechercher une cle
    string rechercher(int cle) const {
        int indice = hachage(cle);
        Noeud* courant = table[indice];

        while (courant != nullptr) {
            if (courant->cle == cle) {
                return courant->valeur;
            }

            courant = courant->suivant;
        }

        return "Cle introuvable";
    }

    // Supprimer une cle
    void supprimer(int cle) {
        int indice = hachage(cle);
        Noeud* courant = table[indice];
        Noeud* precedent = nullptr;

        while (courant != nullptr) {
            if (courant->cle == cle) {
                if (precedent == nullptr) {
                    table[indice] = courant->suivant;
                } else {
                    precedent->suivant = courant->suivant;
                }

                delete courant;
                cout << "Element supprime." << endl;
                return;
            }

            precedent = courant;
            courant = courant->suivant;
        }

        cout << "Cle introuvable." << endl;
    }

    // Afficher la table
    void afficher() const {
        cout << "\n===== TABLE DE HACHAGE =====" << endl;

        for (int i = 0; i < TAILLE; i++) {
            cout << "Case " << i << " : ";

            Noeud* courant = table[i];

            while (courant != nullptr) {
                cout << "[" << courant->cle
                     << " : " << courant->valeur << "] -> ";

                courant = courant->suivant;
            }

            cout << "NULL" << endl;
        }
    }

    // Destructeur
    ~TableHachage() {
        for (int i = 0; i < TAILLE; i++) {
            Noeud* courant = table[i];

            while (courant != nullptr) {
                Noeud* temp = courant;
                courant = courant->suivant;
                delete temp;
            }
        }
    }

    // Eviter la copie superficielle
    TableHachage(const TableHachage&) = delete;
    TableHachage& operator=(const TableHachage&) = delete;
};

// Programme principal
int main() {
    TableHachage t;

    // Insertion
    t.inserer(10, "Ahmed");
    t.inserer(12, "Sara");
    t.inserer(15, "Youssef");
    t.inserer(7, "Amine");
    t.inserer(20, "Salma");

    // Affichage
    t.afficher();

    // Recherche
    cout << "\nRecherche de la cle 12 : "
         << t.rechercher(12) << endl;

    cout << "Recherche de la cle 25 : "
         << t.rechercher(25) << endl;

    // Suppression
    cout << "\nSuppression de la cle 15 :" << endl;
    t.supprimer(15);

    // Affichage apres suppression
    t.afficher();

    return 0;
}
