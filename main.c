/*
 * Created by Nathan KIENLEN
 * 28.12.2015
 */

#include <stdlib.h>
#include "stdio.h"

//          DECLARATIONS
void generationVecteurAleatoire(int* vectActuel, const int nombreElt);

void triSelection(int* vectActuel, const unsigned int nombreElt);
unsigned int indicePlusPetit(int* liste, const unsigned int nombreElt, const unsigned int indiceDebut);

void triInsertion(int* liste, const unsigned int nombreElt);
void echangerElements(int* liste, const unsigned int indice1, const unsigned int indice2);

void triBulles(int* liste, const unsigned int nombreElt);



//          DEFINITIONS
int main()
{
    clock_t start, end;
    double time_used;

    int nombreElements = 10;

    int * vecteur = malloc(sizeof(int) * nombreElements);
    generationVecteurAleatoire(vecteur, nombreElements);

    // ### TRI
    start = clock(); //Permet de chronometrer l algorithme de tri

    //triSelection(vecteur, nombreElements);
    //triInsertion(vecteur, nombreElements);
    //triBulles(vecteur, nombreElements);

    end = clock();
    // ### TRI FAIT


    /* VERIFICATION VISUELLE
    int indice;
    for (indice=0; indice<nombreElements; indice++)
        printf("%i\r\n", vecteur[indice]);
    */

    time_used = ( (double) (end - start) );
    printf("Temps d execution : %f s\r\n", time_used / CLOCKS_PER_SEC);

    free(vecteur);
    return 0;
}


void generationVecteurAleatoire(int* vectActuel, const int nombreElt)
{
    //vectActuel = malloc(sizeof(int) * nombreElt);

    //on vide le vecteur
    unsigned int index = 0;
    for (index; index < nombreElt; index++)
        vectActuel[index] = 0;

    srand ( (unsigned int) time (NULL) ); // pour avoir un "random" different d un execution a l autre ...
    for (index=0; index<nombreElt; index++)
    {
        vectActuel[index] = rand() % 10000; //On limite l amplitude des valeurs
    }
}



// ################ TRI PAR SELECTION ################
/*
 * Complexite temporelle : O(n^2)
 * Complexite memoire :    O(1)
 */

unsigned int indicePlusPetit(int* liste, const unsigned int nombreElt, const unsigned int indiceDebut)
//Retourne la premiere occurrence du plus petit element de la liste passee en parametre.
{
    if (nombreElt == 0 || nombreElt == 1)
        return 0;

    if (indiceDebut > nombreElt)
        return -1; //erreur -> on fait planter le programme

    int ppe = liste[indiceDebut]; // plus petit element (actuel)
    unsigned int ipp = indiceDebut; // indice du ppe

    unsigned int indice = indiceDebut+1;
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


void triSelection(int* vectActuel, const unsigned int nombreElt)
{
    unsigned int indice = 0;
    unsigned int ipp = 0;
    int tampon; //sert pour echanger deux valeurs

    for ( indice ; indice < nombreElt; indice++) //Permet de creer virtuellement des sous tableaux
    {
        ipp = indicePlusPetit(vectActuel, nombreElt, indice);
        tampon = vectActuel[ipp];
        vectActuel[ipp] = vectActuel[indice];
        vectActuel[indice] = tampon;
    }
}

//  ################################



// ################ TRI PAR INSERTION ################
/*
 * Complexite temporelle : O(n^2)
 * Complexite memoire :    O(1)
 */

void echangerElements(int* liste, const unsigned int indice1, const unsigned int indice2)
{
    int tampon = liste[indice1];
    liste[indice1] = liste[indice2];
    liste[indice2] = tampon;
}

void triInsertion(int* liste, const unsigned int nombreElt)
{
    unsigned int indiceTableau = 2;
    unsigned int indiceSousTableau;

    for ( indiceTableau; indiceTableau < nombreElt; indiceTableau++ )
    {
        for ( indiceSousTableau = indiceTableau; indiceSousTableau >= 1; indiceSousTableau-- )
        {
            if ( liste[indiceSousTableau] < liste[indiceSousTableau - 1] )
            {
                echangerElements(liste, indiceSousTableau, indiceSousTableau-1);
            }
        }
    }
}

//  ################################



// ################ TRI A BULLES ################
/*
 * Complexite temporelle : O(n^2)
 * Complexite memoire :    O(1)
 */

void triBulles(int* liste, const unsigned int nombreElt)

{
    unsigned int i = 0;
    unsigned int j = 0;

    for (i=nombreElt-1; i>1; i--)
    {
        for( j=0; j < i; j++)
        {
            if (liste[j] > liste[j+1])
            {
                echangerElements(liste, j, j+1);
            }
        }
    }
}
//  ################################

// ################ TRI RAPIDE ################
/*
 * Complexite temporelle (moyenne) : O(n*log(n))
 * Complexite memoire :    O(n)
 */


//  ################################