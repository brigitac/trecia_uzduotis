#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include "failas.h"
#include "galbalas.h"
bool compare(const studentas &lhs, const studentas &rhs) {return lhs.pavarde<rhs.pavarde;}
void failai(string vardas, string pavarde, int egz_paz, vector<int> v, char *argv[], int nd_sk, int nd_paz)
{
    vector<studentas>sv;
    ifstream failas1;
    failas1.open (argv[1]);
    if (!failas1)
    {
        cout << "Duomenu failas nerastas";
        exit(1);
    }
    ofstream failas2;
    failas2.open(argv[2]);
    if (!failas2)
    {
        cout << "Rezultatu failas nerastas";
        exit(1);
    }
    failas2<<left<<setw(20)<<"Pavardė"<<left<<setw(15)<<"Vardas"<<left<<setw(20)<<"Galutinis-vidurkis"<<"Galutinis-mediana"<<endl;
    char simbol;
    do //skaiciuosiu, kiek yra zodziu pirmoj eilutej
    {
        failas1.get(simbol);
        if (simbol==' ')
        {
            nd_sk++;  //skaiciuoju, kiek yra zodziu
            do //praleidziu tarpus
            {
                failas1.get(simbol);
            }while(simbol==' ');
        }
    }while (simbol!='\n');
    nd_sk-=3; //suzinau, kiek buvo namu darbu, is visu pirmoj eilutej zodziu atemus 3, nes 3 zodziziai yra vardui, pavardei ir egzamino pazymiui
    //issisaugau reikiamus duomenis
    unsigned long o=0;
    double galBalas_m=0;
    double galBalas_v=0;
    while(!failas1.eof()) //skaitau faila iki pabaigos
    {
        failas1>>pavarde>>vardas;
        for(int i=0; i<nd_sk;i++) //issisaugau nd pazymius i vektoriu
        {
            failas1>>nd_paz;
            v.push_back(nd_paz);
        }
        failas1>>egz_paz;
        galBalas_m=galBalas_mediana(v,egz_paz);
        galBalas_v=galBalas_vidurkis(v,egz_paz);
        sv.push_back(studentas());
        sv[o].vardas=vardas;
        sv[o].pavarde=pavarde;
        sv[o].galBalas_m=galBalas_m;
        sv[o].galBalas_v=galBalas_v;
        vector<int>().swap(v);
        o++;
    }
    sort(sv.begin(), sv.end(), compare);
    for(unsigned long i=0; i<o;i++) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<left<<setw(19)<<sv[i].pavarde<<left<<setw(15)<<sv[i].vardas<<left<<setw(20)<<setprecision(2) << fixed<<sv[i].galBalas_v<<sv[i].galBalas_m<<endl;
    }
    failas1.close();
    failas2.close();
}


