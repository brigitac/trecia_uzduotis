#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include "failai.h"
#include "galbalas.h"
bool compare(const studentas &lhs, const studentas &rhs) {return lhs.pavarde<rhs.pavarde;}
void failai(string vardas, string pavarde, int egz_paz, vector<int> v, char *argv[], int nd_sk, int nd_paz)
{
    vector<studentas>good;
    vector<studentas>bad;
    ifstream failas1;
    try
    {
        failas1.open (argv[1]);
        if (failas1.is_open()) {
        } else {
            throw exception();
        }
    }
    catch(std::exception &e)
    {
        e.what();
        cout << "Duomenų failas nerastas."<<endl;
        exit(1);
    }
    ofstream failas2;
    failas2.open(argv[2]);
    if (!failas2)
    {
        cout << "Rezultatų failo atidaryti/sukurti nepavyko"<<endl;
        exit(1);
    }
    failas2<<"Tie geresni:"<<endl<<left<<setw(20)<<"Pavardė"<<left<<setw(15)<<"Vardas"<<left<<setw(20)<<"Galutinis-vidurkis"<<"Galutinis-mediana"<<endl;
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
    unsigned long o=0, u=0;
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
        double vidurkis=0;
        for (unsigned long i=0;i<v.size();i++) vidurkis += v[i]; //sudedineju nd pazymius
        vidurkis /= v.size();
        if (vidurkis>=6)
        {
        galBalas_m=galBalas_mediana(v,egz_paz);
        galBalas_v=galBalas_vidurkis(v,egz_paz);
        good.push_back(studentas());
        good[o].vardas=vardas;
        good[o].pavarde=pavarde;
        good[o].galBalas_m=galBalas_m;
        good[o].galBalas_v=galBalas_v;
        o++;
        }
        else
        {
            bad.push_back(studentas());
            bad[u].vardas=vardas;
            bad[u].pavarde=pavarde;
            u++;
        }
        vector<int>().swap(v);
    }
    sort(good.begin(), good.end(), compare);
    for(unsigned long i=0; i<o;i++) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<left<<setw(19)<<good[i].pavarde<<left<<setw(15)<<good[i].vardas<<left<<setw(20)<<setprecision(2) << fixed<<good[i].galBalas_v<<good[i].galBalas_m<<endl;
    }
    sort(bad.begin(), bad.end(), compare);
    failas2<<endl<<"Vargšiukai:"<<endl<<left<<setw(20)<<"Pavardė"<<left<<setw(15)<<"Vardas"<<endl;
    for(unsigned long i=0; i<u;i++) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<left<<setw(19)<<bad[i].pavarde<<left<<setw(15)<<bad[i].vardas<<endl;
    }
    failas1.close();
    failas2.close();
}


