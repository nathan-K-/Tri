/*
 * Created by Nathan KIENLEN
 * 28.12.2015
 */

#include <iostream>
#include <vector>
#include <random>
#include <boost/timer.hpp>
using namespace std;

void generationVecteurAleatoire(vector<int> vectActuel, long int nombreElt);

int main()
{
    boost::timer tps; //On chronometre l'application

    int nombreElements = 1000;

    vector<int> vecteur;
    generationVecteurAleatoire(vecteur, nombreElements),

    cout << "Temps d'execution : " << tps.elapsed() << " s" << endl;
    return 0;
}


void generationVecteurAleatoire(vector<int> vectActuel, long int nombreElt)
{
    unsigned int element;
    long int index(0);
    for (index; index<nombreElt; index++)
    {
        element = ( random() % 10000 );
        //cout << index << endl;
        vectActuel.push_back(element);  //pour limiter la taille max des nombres
    }
}

