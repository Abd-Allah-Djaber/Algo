#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void voidch(char *p , int n)
{
    while(p < p + n)
    {
        *p = '\0';
        p++;
    }
}
int main(){

    int n;
    printf("veuillez saisir la taille maximale de la chaine:\n");
    scanf("%d",&n);
/*    
    char *p;
    p = calloc(n,sizeof(char));
*/
char chain[10];
char* ch = chain;
scanf("%s",ch);
puts(ch);
free(ch);
return 0;
}
