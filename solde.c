#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct SourceOrType {
	char Solde[10];
	char Source_or_Type[20];
	struct SourceOrType *next;
} SourceOrType;

typedef struct {
	char Date[10];
	struct Date *next;
}Date;

Date* AjouterFin(Date* liste, char text[50]){
Date* nouveau = malloc(sizeof(Date));
strcpy(liste->Date, text);
nouveau ->next = NULL;/* On ajoute en fin, donc aucun ´el´ement neva suivre */
if(liste == NULL) {
return nouveau; /* Si la liste est vide il suffit de renvoyer l’´el´ement cr´ee
*/
} else {
Date* tempo=liste; /* Sinon, on parcourt la liste `a l’aide d’un poin-teur temporaire et on indique que le dernier ´el´ement de la liste est reli´eau nouvel ´el´ement */
while(tempo->next != NULL)
{
tempo = tempo->next;
}
tempo->next = nouveau;
return liste; } }
int main(){/*
	char text[50];
	scanf("%s",text);
	if(text[0] != '+' || text[0] != '-')
		Date * Liste = (Date*)malloc(sizeof(Date));*/
	getchar();
	return 0;
}

// زوايا الجدول
void topLeft() { printf("┌"); }
void topRight() { printf("┐"); }
void bottomLeft() { printf("└"); }
void bottomRight() { printf("┘"); }

// خطوط أفقية
void horizontal() { printf("─"); }

// خطوط عمودية
void vertical() { printf("│"); }

// تقاطعات الجدول
void leftIntersection() { printf("├"); }
void rightIntersection() { printf("┤"); }
void topIntersection() { printf("┬"); }
void bottomIntersection() { printf("┴"); }
void middleIntersection() { printf("┼"); }

// زوايا ثقيلة
void topLeftHeavy() { printf("┏"); }
void topRightHeavy() { printf("┓"); }
void bottomLeftHeavy() { printf("┗"); }
void bottomRightHeavy() { printf("┛"); }
// خطوط ثقيلة
void horizontalHeavy() { printf("━"); }

// خطوط ثقيلة
void verticalHeavy() { printf("┃"); }
// تقاطعات ثقيلة
void topIntersectionHeavy() { printf("┳"); }
void bottomIntersectionHeavy() { printf("┻"); }
void leftIntersectionHeavy() { printf("┣"); }
void rightIntersectionHeavy() { printf("┫"); }
void middleIntersectionHeavy() { printf("╋"); }

/*
┌─────────┬───────────┬────────────┐
│ +10dz   │ sister    │            │
│ +100dz  │ mather    │            │
│ +1000dz │ father    │            │
│ ─300dz  │ taxi      │            │
│ ─50dz   │ food      │ 1447/11/9  │
│ ─60dz   │ rechargé  │            │
│ ─30dz   │ food      │            │
│ ─310dz  │ food      │            │
├─────────┼───────────┼────────────┤
│ ─370dz  │ print     │            │
│ +6000dz │ cart gold │            │
│ ─1090dz │ print     │            │
│ ─1490dz │ print     │            │
│ ─1200dz │ cable     │            │
│ ─750dz  │ cable     │ 1447/11/10 │
│ ─900dz  │ tools     │            │
│ +1200dz │ cable     │            │
│ ─300dz  │ hammer    │            │
│ ─600dz  │ food      │            │
├─────────┼───────────┼────────────┤
│ ─440dz  │ food      │            │
│ ─340dz  │ food      │            │
│ +10dz   │           │ 1447/11/11 │
│ ─90dz   │ taxi      │            │
│ +200dz  │ father    │            │
└─────────┴───────────┴────────────┘
*/
