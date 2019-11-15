#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <zconf.h>
#include <printf.h>
/******************* variables globales***************************/
int resultat=0;
int nbquestions=0;
int op=0;
int reputil=0;
int total=0;
/******************************************************** proto*********************************************************/
void nbquestion();
int question();
int generationrep (int);
void saisirep ();
void resultats ();


/****************************************************definitions*********************************************/
void nbquestion() {
    printf("A combien de questions voulez-vous répondre\n");
    scanf("%d",&nbquestions);
    }

int question() {
    op=(rand() % (3)) + 1; //nombre entre 1 et 3
    int nombre1=(rand() % (100)) + 1; //nombre entre 1 et 100
    int nombre2=(rand() % (100 )) + 1; //nombre entre 1 et 100

    switch (op)
    {
        case 1:
            printf("%d+%d=?\n",nombre1,nombre2);
            resultat=nombre1+nombre2;
            break;
        case 2:
            printf("%d-%d=?\n",nombre1,nombre2);
            resultat=nombre1-nombre2;
            break;
        case 3:
            printf("%d*%d=?\n",nombre1,nombre2);
            resultat=nombre1*nombre2;
            break;

    }
    return 0;
}

int generationrep(int nbrderep) {

    int rep = 0;
    int j=0;
    for(int i=0;i<nbrderep;i++)
    {

        if(i==0)
            j=rand()%2; //definit sur quel numéro de question sera positionnée
        if(i==j)
        {
            rep=resultat; //on positionne le résultat

        }
        else { // cas resultat aléatoire
            if(op==3) //si multiplication on ajuste le résultat
                rep = (rand() % 10000) + 1;
            else
                rep=(rand()%200)+1; //autrement calcul standard
        }
        printf("%d\n",rep);
    }
    return rep;
}

void saisirep() {
    printf("Veuillez choisir une réponse\n");
    scanf("%d",&reputil);
}

void resultats() {
    if(reputil== resultat)
    {
        printf("Bonne réponse\n");
        total++;
    }
    else
    {
        printf("La Réponse est fausse la bonne réponse est %d\n",resultat);
    }

}

int main() {
    srand(time(NULL));
   nbquestion();
    for(int i=0;i<nbquestions;i++) {
        question();
    generationrep(5);
    saisirep();
        resultats();
    }


    printf("Votre total de bonne réponse est de %d sur %d\nMerci d'avoir jouer",total,nbquestions);
    return 0;
}

