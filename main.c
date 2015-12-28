/*
 * Created by Nathan KIENLEN
 * 28.12.2015
 */

#include <stdlib.h>
#include "stdio.h"
#include "time.h"

//          DECLARATIONS
void generationVecteurAleatoire(int* vectActuel, const int nombreElt);

void triSelection(int* vectActuel, const int nombreElt);
unsigned int indicePlusPetit(int* liste, const unsigned int nombreElt, const unsigned int indiceDebut);

void triInsertion(int* liste, const unsigned int nombreElt);
void echangerElements(int* liste, const unsigned int indice1, const unsigned int indice2);


//          REALISATIONS
int main()
{
    clock_t start, end;
    double time_used;


    int nombreElements = 10000;

    int * vecteur = malloc(sizeof(int) * nombreElements);
    generationVecteurAleatoire(vecteur, nombreElements);

    /*
    unsigned int indice = 0;
    for (indice=0; indice<nombreElements; indice++)
        printf("%i\r\n", vecteur[indice]);

    printf(" \r\n \r\n");
     */

    // ### TRI
    start = clock();

    //triSelection(vecteur, nombreElements);
    //triInsertion(vecteur, nombreElements);

    end = clock();
    // ### TRI FAIT

    /*
    for (indice=0; indice<nombreElements; indice++)
        printf("%i\r\n", vecteur[indice]);
    */
    end = clock();
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

    srand (time (NULL)); // pour avoir un "random" different d un execution a l autre ...
    unsigned int element;
    for (index=0; index<nombreElt; index++)
    {
        vectActuel[index] = rand() % 10000; //On limite l amplitude des valeurs
    }
}



// ################ TRI PAR SELECTION ################
unsigned int indicePlusPetit(int* liste, const unsigned int nombreElt, const unsigned int indiceDebut)
//Retourne la premiere occurrence du plus petit element de la liste passee en parametre.
{
    if (nombreElt == 0 || nombreElt == 1)
        return 0;

    if (indiceDebut > nombreElt)
        return -1; //erreur

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


void triSelection(int* vectActuel, const int nombreElt)
{
    unsigned int indice1 = 0;
    unsigned int indice2 = 0;
    unsigned int ipp = 0;
    int tampon; //sert pour echanger deux valeurs

    for (indice1; indice1<nombreElt; indice1++) //Permet de creer virtuellement des sous tableaux
    {
        ipp = indicePlusPetit(vectActuel, nombreElt, indice1);
        tampon = vectActuel[ipp];
        vectActuel[ipp] = vectActuel[indice1];
        vectActuel[indice1] = tampon;
    }
}

//  ################################



// ################ TRI PAR INSERTION ################
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


//  ################################