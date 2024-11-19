#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour charger une chaîne de caractères
char *ChargerChaine(int N) {
    char *chaine = (char *)malloc((N + 1) * sizeof(char)); // Réserver de l'espace mémoire
    if (chaine == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        exit(1);
    }
    printf("Entrez une chaîne de %d caractères : ", N);
    scanf("%s", chaine); // Lecture de la chaîne
    return chaine;
}

// Fonction pour calculer la longueur d'une chaîne
int Longueur(char *ch) {
    int longueur = 0;
    while (ch[longueur] != '\0') {
        longueur++;
    }
    return longueur;
}

// Procédure pour charger une chaîne dans un tableau
void ChargerTab(char *p, char Tab[]) {
    strcpy(Tab, p); // Copier la chaîne dans le tableau
}

// Procédure pour inverser un tableau
void InverserTab(char Tab[], char T[], int m) {
    for (int i = 0; i < m; i++) {
        T[i] = Tab[m - 1 - i]; // Inverser les éléments
    }
    T[m] = '\0'; // Ajouter le caractère nul
}

// Procédure pour afficher un tableau comme une chaîne
void AfficherTab(char Tab[], int m) {
    for (int i = 0; i < m; i++) {
        printf("%c", Tab[i]);
    }
    printf("\n");
}

// Programme principal
int main() {
    int N;
    printf("Entrez la taille de la chaîne : ");
    scanf("%d", &N);

    // Charger la chaîne
    char *chaine = ChargerChaine(N);
    printf("Chaîne lue : %s\n", chaine);

    // Calculer la longueur
    int longueur = Longueur(chaine);
    printf("Longueur de la chaîne : %d\n", longueur);

    // Charger la chaîne dans un tableau
    char Tab[N + 1];
    ChargerTab(chaine, Tab);

    // Inverser le tableau
    char T[N + 1];
    InverserTab(Tab, T, longueur);
    printf("Chaîne inversée : ");
    AfficherTab(T, longueur);

    // Libérer la mémoire allouée
    free(chaine);

    return 0;
}