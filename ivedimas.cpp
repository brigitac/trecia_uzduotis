#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include "ivedimas.h"
#include "galbalas.h"
void duomenu_ivedimas(string vardas, string pavarde, int egz_paz, vector<int> v, double galBalas,int nd_sk, int nd_paz)
{
    cout << "Įveskite savo vardą: ";
    cin >> vardas;
    cout << "Įveskite savo pavardę: ";
    cin >> pavarde;
    cout << "Jei norite namų darbų ir egzamino pažymius suvesti, įveskite 1, jei norite sugeneruoti atsitiktinius skaičius - bet kokį kitą skaičių: ";
    int vg=0;
    cin>>vg;
    if (cin.fail())
    {
        cin.clear();
        cout<<"KĄ TU ČIA VEDI?!"<<endl;
        exit(1);
    }
    if (vg==1) ivedami_sk(v, &egz_paz, nd_paz);
    else generuojami_sk(v,&egz_paz,nd_sk);
    cout<<"Jei norite skaičiuoti galutinį balą pagal namų darbų vidurkį, įveskite 1, jei pagal mediana - bet kokį kitą skaičių: ";
    int vm=0;
    cin>>vm;
    if (cin.fail() || nd_sk<0)
    {
        cin.clear();
        cout<<"KĄ TU ČIA VEDI?!"<<endl;
        exit(1);
    }
    cout<<"Studento, vardu "<<vardas<<" ir pavarde "<<pavarde<<", su namų darbų pažymiais: ";
    for (unsigned long i=0;i<v.size();i++) cout << v[i] <<" "; //isvedineju nd pazymius
    if(vm==1) galBalas=galBalas_vidurkis(v,egz_paz);
    else galBalas=galBalas_mediana(v,egz_paz);
    cout<<"ir galutiniu egzamino pažymiu "<<egz_paz<<", galutinis balas yra: "<<setprecision(2) << fixed<<galBalas<<endl;
}
void ivedami_sk(vector<int>& v, int *egz_paz, int nd_paz)
{
    cout << "Įveskite namų darbų pažymius, norėdami užbaigti įveskite '0': ";
    cin>>nd_paz;
    if (cin.fail() || nd_paz<0 || nd_paz>10)
       {
           cin.clear();
           cout<<"KĄ TU ČIA VEDI?!"<<endl;
           exit(1);
       }
    while (nd_paz!=0) //nuskaitineju nd pazymius ir issisaugau i vektoriu
    {
        v.push_back(nd_paz);
        cin>>nd_paz;
        if (cin.fail() || nd_paz<0 || nd_paz>10)
        {
            cin.clear();
            cout<<"KĄ TU ČIA VEDI?!"<<endl;
            exit(1);
        }
    }
    cout << "Įveskite egzamino pažymį: ";
    cin >> (*egz_paz);
    if (cin.fail() || (*egz_paz)<1 || (*egz_paz)>10)
    {
        cin.clear();
        cout<<"KĄ TU ČIA VEDI?!"<<endl;
        exit(1);
    }
}
void generuojami_sk(vector<int>& v, int *egz_paz, int nd_sk)
{
    cout<<"Įveskite, kiek namų darbų pažymių norite, kad būtų sugeneruota: ";
    cin>>nd_sk;
    if (cin.fail() || nd_sk<0)
    {
        cin.clear();
        cout<<"KĄ TU ČIA VEDI?!"<<endl;
        exit(1);
    }
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1,10);
    for(int i=0; i<nd_sk;++i) v.push_back(dist(mt)); //generuoju nd pazymius ir issisaugau i vektoriu
    *egz_paz=dist(mt);
}
