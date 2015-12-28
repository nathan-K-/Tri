#include <iostream>
#include <vector>
#include <random>
#include <boost/timer.hpp>
using namespace std;

void vecteurAleatoire(vector<int> vectActuel, long int nombreElt);

int main()
{
    boost::timer tps;
    cout << "Hello, World!" << endl;

    int nombreElements = 100000000;
    vector<int> vecteur;
    vecteurAleatoire(vecteur, nombreElements),


    cout << "Temps d'execution : " << tps.elapsed() << " s" << endl;
    return 0;
}

void vecteurAleatoire(vector<int> vectActuel, long int nombreElt)
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

