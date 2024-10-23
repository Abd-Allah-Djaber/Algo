#include<stdio.h>
int main(){
int i,j,y[4][4];
char m[5][5] = {{'1','2','3','4','5'},
                {'7','a','c','8','d'},
                {'c','9','4','z','8'},
                {'5','6','p','n','3'},
                {'2','9','t','m','k'}};
//afficher la matrise.
printf("َُExercice 01:\n1.1 afficher la matrise.\n");
for(int i = 0 ; i < 5 ; i++ ){
    for(int j = 0; j < 5 ; j++){
        printf("%c\t",m[i][j]);
    }
    printf("\n\n");
}
//afficher la matrise constituée uniquemnent des ligne d'indice pair.
printf("afficher la matrise constituée uniquemnent des ligne d'indice pair.\n");

for(int i = 0 ; i < 5 ; i++ ){
    for(int j = 0; j < 5 ; j++){
        if(i%2 == 0)
            printf("%d,%d\t",i,j);
        else
            printf(" ");
    }
    printf("\n\n");
}
//afficher la matrise constituée uniquemnent des éléments d'indice impair de chaque ligne.
printf("afficher la matrise constituée uniquemnent des éléments d'indice impair de chaque ligne.\n");

for(int i = 0 ; i < 5 ; i++ ){
    for(int j = 0; j < 5 ; j++){
        if(i%2 == 0)
            printf("%c\t",m[i][j]);
        else
            printf(" ");
    }
    printf("\n\n");
}
//
printf("\n\n1.2. la diagonale:\n");
for(i = 0 ; i < 5 ; i++){
    printf("\t%c",m[i][i]);
}

printf("\n\nla 2e diagonale:\n");
for(i = 4 ; i >= 0 ; i--){
    printf("\t%c",m[i][4-i]);
}

printf("\n\n");

//
printf("Exercice 02:\nMatrise before:\n");
 int T[5][5],h;
    for(i = 0 ; i < 4 ; i++){
        for(j = 0 ; j < 4 ; j++){
            T[i][j] = 4*i + j + 1 ;
    }
    }

    for(int i = 0 ; i < 4 ; i++){
            printf("\n\n");
        for(int j = 0 ; j < 4 ; j++){
            printf("\t%d",T[i][j]);
    }
    }

    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < i ; j++){
            h = T[i][j];
            T[i][j] = T[j][i];
            T[j][i] = h;
    }
    }


    printf("\nafter\n");
    for(int i = 0 ; i < 4 ; i++){
            printf("\n\n");
        for(int j = 0 ; j < 4 ; j++){
            printf("\t%d",T[i][j]);
    }
    }


return 0;
}
