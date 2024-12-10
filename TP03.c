#include <stdio.h>
#include <stdlib.h>

// Définition de l'élément de la liste simplement chainée
typedef struct element {
    int val;
    struct element *suivant;
} element;

// Fonction pour créer une liste vide
element* creerListe() {
    return NULL;  // Retourne NULL pour indiquer une liste vide
}

// Fonction pour charger une liste à partir d'un tableau
element* chargerListe(int Tab[], int taille, element* liste) {
    int i;
    for (i = 0; i < taille; i++) {
        element* nouv = (element*) malloc(sizeof(element));
        nouv->val = Tab[i];
        nouv->suivant = liste;  // Insère l'élément au début de la liste
        liste = nouv;  // Mise à jour de la tête de la liste
    }
    return liste;
}

// Fonction pour afficher une liste
void afficherListe(element* liste) {
    while (liste != NULL) {
        printf("%d -> ", liste->val);
        liste = liste->suivant;
    }
    printf("NULL\n");
}

// Fonction pour supprimer l'élément en fin de la liste
element* supprimerEnFin(element* liste) {
    if (liste == NULL || liste->suivant == NULL) {
        free(liste);
        return NULL;  // Liste vide ou un seul élément
    }

    element* temp = liste;
    while (temp->suivant && temp->suivant->suivant != NULL) {
        temp = temp->suivant;
    }

    // Temp pointe sur l'avant-dernier élément
    free(temp->suivant);
    temp->suivant = NULL;  // Supprime le dernier élément

    return liste;
}

// Fonction pour ajouter un élément au début de la liste
element* ajouterEnDebut(element* liste, int valeur) {
    element* nouv = (element*) malloc(sizeof(element));
    nouv->val = valeur;
    nouv->suivant = liste;
    return nouv;  // Retourne la nouvelle tête de la liste
}

// Fonction pour vider la liste
void viderListe(element* liste) {
    element* temp;
    while (liste != NULL) {
        temp = liste;
        liste = liste->suivant;
        free(temp);  // Libère la mémoire de chaque élément
    }
    printf("La liste est vide\n");
}

// Fonction main avec l'exemple d'utilisation
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

    return 0;
}
