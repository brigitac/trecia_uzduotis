#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include "galbalas.h"
#include "ivedimas.h"
#include "failai.h"
using std::cout; using std::cin; using std::string;using std::vector;
int main (int, char *argv[])
{
    string vardas;
    string pavarde;
    vector<int>v;
    int egz_paz=0, nd_paz=0, nd_sk=0;
    double galBalas=0;
    cout<<"Jei norite duomenis suvesti, įveskite 1, jei norite nuskaityti iš failo - bet kokį kitą simbolį: ";
    int f=0;
    cin>>f;
    if (f==1) duomenu_ivedimas(vardas,pavarde,egz_paz,v,galBalas,nd_sk,nd_paz);
    else failai(vardas,pavarde,egz_paz,v,argv,nd_sk,nd_paz);
    return 0;
}
