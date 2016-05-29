/*
 * Created by Nathan KIENLEN
 * 28.12.2015
 * Teste sous GCC 4.8.4 et sous Debian
 */

#define LIMIT_NUMBER 1000
//plus grand nombre contenu dans le tableau
#define NOMBRE_ELEMENT 10
//nombre d elements a trier

#include <stdlib.h>
#include <stdio.h>
#include "time.h"

//          DECLARATIONS
void generationVecteurAleatoire(int* vectActuel);


void triAleatoire(int* vectActuel);
int estTrie(int* vectActuel);

void triSelection(int* vectActuel);
unsigned int indicePlusPetit(int* liste, const unsigned int indiceDebut);

void triInsertion(int* liste);
void echangerElements(int* liste, const unsigned int indice1, const unsigned int indice2);

void triBulles(int* liste);

void triRapide(int* liste, const unsigned int debut, const unsigned int fin);
int randomInterval(const int debut, const int fin);

void triComptage(int* liste);

//          DEFINITIONS
int main()
{
    clock_t start, end;
    double time_used;

    int * vecteur = calloc(NOMBRE_ELEMENT, sizeof(int) );
    generationVecteurAleatoire(vecteur);

    printf("Vecteur de depart : \n");
    int indice;
    for (indice=0; indice<NOMBRE_ELEMENT; indice++)
        printf("%i\r\n", vecteur[indice]);
    printf("\n\nApres tri : \n");

    // ### TRI
    start = clock(); //Permet de chronometrer l algorithme de tri

    //triSelection(vecteur);
    //triInsertion(vecteur);
    //triBulles(vecteur);
    //triRapide(vecteur, 0);
    //triComptage(vecteur);
    //triAleatoire(vecteur);

    end = clock();
    // ### TRI FAIT


    /* VERIFICATION VISUELLE  */
    indice;
    for (indice=0; indice<NOMBRE_ELEMENT; indice++)
        printf("%i\r\n", vecteur[indice]);

    time_used = ( (double) (end - start) );
    printf("Temps d execution : %f s\r\n", time_used / CLOCKS_PER_SEC);

    free(vecteur);
    return 0;
}


void generationVecteurAleatoire(int* vectActuel)
{
    //vectActuel = malloc(sizeof(int) * NOMBRE_ELEMENT);

    //on vide le vecteur
    unsigned int index = 0;
    for (index; index < NOMBRE_ELEMENT; index++)
        vectActuel[index] = 0;

    srand ( (unsigned int) time (NULL) ); // pour avoir un "random" different d un execution a l autre ...
    for (index=0; index<NOMBRE_ELEMENT; index++)
    {
        vectActuel[index] = rand() % LIMIT_NUMBER; //On limite l amplitude des valeurs
    }
}


// ################ TRI ALEATOIRE ################
/*
 * Complexite temporelle : N/A
 * Complexite memoire :    N/A
 */

int estTrie(int* vectActuel)
{
    unsigned int i;
    for (i=0; i<NOMBRE_ELEMENT-1; i++)
    {
        if (vectActuel[i] > vectActuel[i+1])
            return 0;
    }
    return 1;
}

void triAleatoire(int* vectActuel)
{
    unsigned int alea1;
    unsigned int alea2;
    unsigned long long compteurIterations = 0;

    srand ( (unsigned int) time (NULL) );
    while ( ! estTrie(vectActuel))
    {
        alea1 = (unsigned int) rand() % NOMBRE_ELEMENT;
        alea2 = (unsigned int) rand() % NOMBRE_ELEMENT;
        echangerElements(vectActuel, alea1, alea2);
        compteurIterations++;
    }
    printf("%llu iterations\n", compteurIterations);
}

//  ################################

// ################ TRI PAR SELECTION ################
/*
 * Complexite temporelle : O(n^2)
 * Complexite memoire :    O(1)
 */

unsigned int indicePlusPetit(int* liste, const unsigned int indiceDebut)
//Retourne la premiere occurrence du plus petit element de la liste passee en parametre.
{
    if (NOMBRE_ELEMENT == 0 || NOMBRE_ELEMENT == 1)
        return 0;

    if (indiceDebut > NOMBRE_ELEMENT)
        return -1; //erreur -> on fait planter le programme

    int ppe = liste[indiceDebut]; // plus petit element (actuel)
    unsigned int ipp = indiceDebut; // indice du ppe

    unsigned int indice = indiceDebut+1;
    for (indice; indice<NOMBRE_ELEMENT; indice++)
    {
        if (liste[indice] < ppe)
        {
            ipp = indice;
            ppe = liste[indice];
        }
    }

    return ipp;
}


void triSelection(int* vectActuel)
{
    unsigned int indice = 0;
    unsigned int ipp = 0;
    int tampon; //sert pour echanger deux valeurs

    for ( indice ; indice < NOMBRE_ELEMENT; indice++) //Permet de creer virtuellement des sous tableaux
    {
        ipp = indicePlusPetit(vectActuel, indice);
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

void triInsertion(int* liste)
{
    unsigned int indiceTableau = 2;
    unsigned int indiceSousTableau;

    for ( indiceTableau; indiceTableau < NOMBRE_ELEMENT; indiceTableau++ )
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

void triBulles(int* liste)

{
    unsigned int i = 0;
    unsigned int j = 0;

    for (i=NOMBRE_ELEMENT-1; i>1; i--)
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

/*      PLUS UNIFORME, MAIS TRES LENT
int randomInterval(const int debut, const int fin, const unsigned int nombreValeurs)
// On boucle pour avoir la distribution la plus uniforme possible
{
    int retour = 0; //return code
    int randInt;
    unsigned int compteur = 0;
    do {
        randInt = rand();
        if (randInt <= fin && randInt >= debut)
        {
            compteur++;
            retour += randInt;
        }
    }
    while (compteur < nombreValeurs);

    return (int) retour / compteur;
} */

int randomInterval(const int debut, const int fin)
{
    double scaled = (double)rand()/RAND_MAX;

    return ((int) ((fin - debut +1)*scaled + debut));
};

unsigned int partition(int* liste, const unsigned int debut, const unsigned int fin)
//On choisit un pivot aleatoire, et on permute les elements du tableau de maniere a ce que
// les elements plus grands que le pivot soient en fin de liste
{
    //echangerElements(liste, debut, (unsigned int) randomInterval(debut, fin) );

    int pivot = liste[fin];
    unsigned int i = debut;
    unsigned int index;
    for (index=debut; index<fin; index++)
    {
        if (liste[index] < pivot)
        {
            echangerElements(liste, i++, index );
        }
    }
    echangerElements(liste, i, fin);
    return i;
}


void triRapide(int* liste, const unsigned int debut, const unsigned int fin)
{
    unsigned int position = 0;
    if (debut < fin)
    {
        position = partition(liste, debut, fin);
        if (position != 0)
            triRapide(liste, debut, position-1);
        triRapide(liste, position+1, fin);
    }
}

//  ################################


// ################ TRI COMPTAGE ################
/*
 * Complexite temporelle (moyenne) : O(n)
 * Complexite memoire :    O(n)
 */
void triComptage(int* liste)
{
    unsigned int * tableauComptage = (unsigned int *) calloc( LIMIT_NUMBER , sizeof( unsigned int ));

    unsigned int i;
    for ( i=0; i<NOMBRE_ELEMENT; i++ )
    {
        tableauComptage[liste[i]]++;
    }
    unsigned int compteurListe = 0;
    for ( i=0; i<LIMIT_NUMBER; i++ )
    {
        while( tableauComptage[i] != 0)
        {
            liste[compteurListe++] = i;
            (tableauComptage[i])--;
        }
    }

    free (tableauComptage);
}

//  ################################
