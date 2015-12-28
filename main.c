/*
 * Created by Nathan KIENLEN
 * 28.12.2015
 */

#include <stdlib.h>
#include "stdio.h"
#include "time.h"


void generationVecteurAleatoire(int* vectActuel, int nombreElt);
void triSelection(int* vectActuel, int nombreElt);
unsigned int indicePlusPetit(int* liste, unsigned int nombreElt);

int main()
{
    clock_t start, end;
    double time_used;
    start = clock();

    int nombreElements = 30;

    int * vecteur = malloc(sizeof(int) * nombreElements);
    generationVecteurAleatoire(vecteur, nombreElements),

    printf("ipp : %u   ppe : %i \r\n", indicePlusPetit(vecteur, nombreElements), vecteur[indicePlusPetit(vecteur, nombreElements)]);

    end = clock();
    time_used = ( (double) (end - start) );
    printf("Temps d execution : %f s\r\n", time_used / CLOCKS_PER_SEC);

    free(vecteur);
    return 0;
}


void generationVecteurAleatoire(int* vectActuel, int nombreElt)
{
    //vectActuel = malloc(sizeof(int) * nombreElt);

    //on vide le vecteur
    unsigned int index = 0;
    for (index; index < nombreElt; index++)
        vectActuel[index] = 0;

    srand (time (NULL)); // pour avoir un "random" different d un execution a l autre ...
    unsigned int element;
    for (index=0; index<nombreElt; index++)
    {
        int element =  rand() % 10000;
        vectActuel[index] = element; //On limite l amplitude des valeurs
        printf("%i \r\n", element);
    }
}

// ################ TRI SELECTION ################
unsigned int indicePlusPetit(int* liste, unsigned int nombreElt)
//Retourne la premiere occurrence du plus petit element de la liste passee en parametre.
{
    if (nombreElt == 0 || nombreElt == 1)
        return 0;

    int ppe = liste[0]; // plus petit element (actuel)
    unsigned int ipp = 0; // indice du ppe

    unsigned int indice = 1;
    for (indice; indice<nombreElt; indice++)
    {
        if (liste[indice] < ppe)
        {
            ipp = indice;
            ppe = liste[indice];
        }
    }

    return ipp;
}

void triSelection(int* vectActuel, int nombreElt)
{
    unsigned int indice1 = 0;
    unsigned int indice2 = 0;
    unsigned int ipp = 0;

    for (indice1; indice1<nombreElt; indice1++) //Permet de creer virtuellement des sous tableaux
    {

    }
}

//  ################################