#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include <chrono>
#include "galbalas.h"
#include "ivedimas.h"
#include "failai.h"
#include "sukurimas.h"
#include "struktura.h"
using std::cout; using std::cin; using std::string;using std::vector;
void wrong();
int main (int, char *argv[])
{
    auto start = std::chrono::high_resolution_clock::now();
    string vardas;
    string pavarde;
    vector<int>v;
    int egz_paz=0, nd_paz=0, nd_sk=0;
    double galBalas=0;
    cout<<"Jei norite duomenis suvesti, įveskite 1, jei norite nuskaityti iš failo - 2, jei norite sukurti atsitiktinį studentų failą - bet kokį kitą skaičių: ";
    int f=0;
    cin>>f;
    if (cin.fail()) wrong();
    if (f==1) duomenu_ivedimas(vardas,pavarde,egz_paz,v,galBalas,nd_sk,nd_paz);
    else if (f==2) failai(vardas,pavarde,egz_paz,v,argv,nd_sk,nd_paz);
    else
    {
        cout<<"Iveskite,kiek įrašų norite, kad būtų sugeneruota: ";
        int kiekis=0;
        cin>>kiekis;
        if (cin.fail()) wrong();
        sukurimas(kiekis,argv,nd_sk);
        failai(vardas,pavarde,egz_paz,v,argv,nd_sk,nd_paz);
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    cout << "Programos vykdymo laikas: " << elapsed.count() << " s\n";
    return 0;
}
void wrong()
{
    cin.clear();
    cout<<"KĄ TU ČIA VEDI?!"<<endl;
    exit(1);
}
