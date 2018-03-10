#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include "ivedimas.h"
#include "galbalas.h"
void duomenu_ivedimas()
{
    string vardas;
    string pavarde;
    vector<int>v;
    int egz_paz=0;
    double galBalas=0;
    cout << "Įveskite savo vardą: ";
    cin >> vardas;
    if (cin.fail()) wrong();
    cout << "Įveskite savo pavardę: ";
    cin >> pavarde;
    if (cin.fail()) wrong();
    cout << "Jei norite namų darbų ir egzamino pažymius suvesti, įveskite 1, jei norite sugeneruoti atsitiktinius skaičius - bet kokį kitą skaičių: ";
    int vg=0;
    cin>>vg;
    if (cin.fail()) wrong();
    if (vg==1) ivedami_sk(v, &egz_paz);
    else generuojami_sk(v,&egz_paz);
    cout<<"Jei norite skaičiuoti galutinį balą pagal namų darbų vidurkį, įveskite 1, jei pagal mediana - bet kokį kitą skaičių: ";
    int vm=0;
    cin>>vm;
    if (cin.fail()) wrong();
    cout<<"Studento, vardu "<<vardas<<" ir pavarde "<<pavarde<<", su namų darbų pažymiais: ";
    for (const auto& elem:v) cout<<elem<<" "; //isvedineju nd pazymius
    if(vm==1) galBalas=galBalas_vidurkis(v,egz_paz);
    else galBalas=galBalas_mediana(v,egz_paz);
    cout<<"ir galutiniu egzamino pažymiu "<<egz_paz<<", galutinis balas yra: "<<setprecision(2) << fixed<<galBalas<<endl;
}
void ivedami_sk(vector<int>& v, int *egz_paz)
{
    cout << "Įveskite namų darbų pažymius, norėdami užbaigti įveskite '0': ";
    int nd_paz =0;
    cin>>nd_paz;
    if (cin.fail() || nd_paz<0 || nd_paz>10) wrong();
    while (nd_paz!=0) //nuskaitineju nd pazymius ir issisaugau i vektoriu
    {
        v.push_back(nd_paz);
        cin>>nd_paz;
        if (cin.fail() || nd_paz<0 || nd_paz>10) wrong();
    }
    cout << "Įveskite egzamino pažymį: ";
    cin >> (*egz_paz);
    if (cin.fail() || (*egz_paz)<1 || (*egz_paz)>10) wrong();
}
void generuojami_sk(vector<int>& v, int *egz_paz)
{
    cout<<"Įveskite, kiek namų darbų pažymių norite, kad būtų sugeneruota: ";
    int nd_sk=0;
    cin>>nd_sk;
    if (cin.fail() || nd_sk<0) wrong();
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1,10);
    for(int i=0; i<nd_sk;++i) v.push_back(dist(mt)); //generuoju nd pazymius ir issisaugau i vektoriu
    *egz_paz=dist(mt);
}
