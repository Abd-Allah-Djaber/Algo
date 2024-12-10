
#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int val;
    struct element *suivant;
} element;

// Fonction pour créer une liste vide
element* creerListe() {
    element *nouv = NULL;
    return nouv; // La liste vide est représentée par un pointeur NULL
}

// Fonction pour charger la liste à partir d'un tableau
element* chargerListe(int Tab[], int n, element* liste) {
    element* nouveau;
    int i;
    for (i = 0; i < n; i++) {
        // Création d'un nouvel élément
        nouveau = (element*)malloc(sizeof(element));
        nouveau->val = Tab[i];
        nouveau->suivant = liste;
        liste = nouveau;  // Le nouvel élément devient la tête de la liste
    }

    return liste;
}

// Fonction pour afficher une liste
void afficherListe(element* liste) {
    element* courant = liste;
    while (courant != NULL) {
        printf("%d -> ", courant->val);
        courant = courant->suivant;
    }
    printf("NULL\n");
}

// Fonction pour supprimer un élément à la fin de la liste
element* supprimerEnFin(element* liste) {
    if (liste == NULL) return NULL; // Liste vide, rien à supprimer

    if (liste->suivant == NULL) {
        free(liste); // Si la liste contient un seul élément
        return NULL;
    }

    element* courant = liste;
    while (courant->suivant != NULL && courant->suivant->suivant != NULL) {
        courant = courant->suivant;
    }

    free(courant->suivant); // Suppression du dernier élément
    courant->suivant = NULL; // Le nouvel élément de fin est NULL
    return liste;
}

// Fonction pour ajouter un élément au début de la liste
element* ajouterEnDebut(element* liste, int val) {
    element* nouveau = (element*)malloc(sizeof(element));
    nouveau->val = val;
    nouveau->suivant = liste;
    return nouveau; // Le nouvel élément devient la tête de la liste
}

// Fonction pour vider la liste
void viderListe(element* liste) {
    element* courant = liste;
    element* temp;
    while (courant != NULL) {
        temp = courant;
        courant = courant->suivant;
        free(temp); // Libération de la mémoire
    }
    printf("La liste est vide.\n");
}

// Fonction main
int main() {
    int Tab[10] = {1, 3, 5, 7, 8, 10, 9, 11, 13, 20};
    element* liste = creerListe();
    element* L = chargerListe(Tab, 10, liste);
    printf("Liste après chargement :\n");
    afficherListe(L);
    element* L1 = supprimerEnFin(L);
    printf("\nListe après suppression de l'élément en fin :\n");
    afficherListe(L1);
    element* L2 = ajouterEnDebut(L1, 40);
    printf("\nListe après ajout de 40 au début :\n");
    afficherListe(L2);
    viderListe(L2);
    getche();
    return 0;
}
