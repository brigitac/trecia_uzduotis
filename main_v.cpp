#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include "galbalas.h"
#include "ivedimas.h"
#include "failai.h"
#include "sukurimas.h"
using std::cout; using std::cin; using std::string;using std::vector;
int main (int, char *argv[])
{
    string vardas;
    string pavarde;
    vector<int>v;
    int egz_paz=0, nd_paz=0, nd_sk=0;
    double galBalas=0;
    cout<<"Jei norite duomenis suvesti, įveskite 1, jei norite nuskaityti iš failo - 2, jei norite sukurti atsitiktinį studentų failą - bet kokį kitą skaičių: ";
    int f=0;
    cin>>f;
    if (cin.fail())
    {
        cin.clear();
        cout<<"KĄ TU ČIA VEDI?!"<<endl;
        exit(1);
    }
    if (f==1) duomenu_ivedimas(vardas,pavarde,egz_paz,v,galBalas,nd_sk,nd_paz);
    else if (f==2) failai(vardas,pavarde,egz_paz,v,argv,nd_sk,nd_paz);
    else
    {
        cout<<"Iveskite,kiek įrašų norite, kad būtų sugeneruota: ";
        int kiekis=0;
        cin>>kiekis;
        if (cin.fail())
        {
            cin.clear();
            cout<<"KĄ TU ČIA VEDI?!"<<endl;
            exit(1);
        }
        sukurimas(kiekis,argv,nd_sk);
    }
    return 0;
}
