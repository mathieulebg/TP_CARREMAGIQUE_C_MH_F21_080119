#include <stdio.h>
#include <stdlib.h>
#define TAILLE 7 /* constante et taille du table*/


//BUT: afficher un carr� magique
//ENTREE: les valeurs du carr� magique.
//SORTIE: un carr� magique qui va vers le nord-est ou nord-ouest si case d�j� prise.

typedef struct Pos
{
    int x;
    int y;
    /* On d�finit ici les valeurs, x largeur, y hautur */
}Pos;

void Debut(Pos *ptPosition,int tabCarre[][TAILLE]); //Void d�finit la proc�dure qui initialise le carr�
void Forward(Pos *ptPosition,int tabCarre[][TAILLE],int nCase); //Cette proc�dure indique ou se placeront les points
int Increase(int value); //On incr�mente les positions
int Decrease(int value); //voir plus haut

int main()
{
    int montab [TAILLE][TAILLE]; //on d�clare ici le tableau en indiquant sa taille
    int nEmplacement = TAILLE * TAILLE; //ici, on r�cup�re les informations de ce qui se trouve dans le tableau, les cellules
    int nCase;
    Pos Position;

    Pos *ptPosition = &Position;

    Debut(ptPosition,montab);

    for(nCase=2;nCase<=nEmplacement;nCase++)
    {
        Forward(ptPosition,montab,nCase);
    }

    for(Position.y=TAILLE-1;Position.y>=0;Position.y--)
    {
        for(Position.x=0;Position.x<=TAILLE-1;Position.x++)
        {
            printf("%d \t",montab[Position.x][Position.y]);
        }

        printf("\n");
    }

    return 0;
}

void Debut(Pos *ptPosition,int montab [][TAILLE]){

    for(ptPosition->x=0;ptPosition->x<=TAILLE-1;ptPosition->x++)
    {
        for(ptPosition->y=0;ptPosition->y<=TAILLE-1;ptPosition->y++)
        {
            montab[ptPosition->x][ptPosition->y]=0;
        }
    }

    ptPosition->x = TAILLE / 2;
    ptPosition->y = TAILLE / 2 + 1;
    montab[ptPosition->x][ptPosition->y]=1;}

void Forward(Pos *ptPosition,int montab[][TAILLE],int nCase) /*ici on fait avancer le placement, du mois le pre-placement on sait ou le situer*/
{
    int check=1;
    ptPosition->x = Increase(ptPosition->x);
    ptPosition->y = Increase(ptPosition->y);

    while(check) //Tant que check vaut 1 executer les instructions suivantes
    {
        if(montab[ptPosition->x][ptPosition->y] == 0)
        {
            montab[ptPosition->x][ptPosition->y] = nCase;
            check=0; //le check=0; revient ici a faire la m�me chose qu'un return 0; mais nous sortons seulement de la boucle.
        }

        else
        {
            ptPosition->x = Decrease(ptPosition->x);
            ptPosition->y = Increase(ptPosition->y);
        }
    }
}

int Increase(int value) //Increase correspond a l'incrementation on incremente les positionss
{
    if(value == TAILLE-1)
        return 0;
    else
        return ++value; //le ++ value revient a faire value+1 comme vu en cours avec les boucles pour, i++ = I+1; (�a j'ai compris)
}

int Decrease(int value) //Decrease correspind � la d�cr�mentation des positions
{
    if(value == 0)
        return TAILLE-1;
    else
        return --value;
}
