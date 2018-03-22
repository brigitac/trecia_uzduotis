#ifndef FAILAI_H
#define FAILAI_H
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <random>
#include <fstream>
#include "failai.h"
#include "galbalas.h"
#include "struktura.h"
using std::cout; using std::cin; using std::endl; using std::string; using std::setprecision; using std::fixed; using std::vector; using std::ifstream; using std::ofstream; using std::setw; using std::left; using std::exception; using std::cerr;
bool compare(const studentas &lhs, const studentas &rhs);
void rusiuokime(vector<studentas>& good);
void rusiuokime(std::list<studentas>& good);
void rusiuokime(std::deque<studentas>& good);
bool compare(const studentas &lhs, const studentas &rhs) {return lhs.pavarde<rhs.pavarde;}
void rusiuokime(vector<studentas>& good){sort(good.begin(), good.end(), compare);}
void rusiuokime(std::list<studentas>& good){good.sort(compare);}
void rusiuokime(std::deque<studentas>& good){sort(good.begin(), good.end(), compare);}

template<typename T>
void failai1(char *argv[], T &good, T &bad, T &studentai)
{
    string vardas;
    string pavarde;
    vector<int>v;
    int egz_paz=0, nd_paz=0, nd_sk=0;
    ifstream failas1;
    try
    {
        failas1.open (argv[1]);
        if (failas1.is_open()) {}
        else
        {
            throw exception();
        }
    }
    catch(std::exception &e)
    {
        e.what();
        cerr << "Duomenų failas nerastas."<<endl;
        exit(1);
    }
    ofstream failas2;
    failas2.open(argv[2]);
    if (!failas2)
    {
        cerr << "Rezultatų failo atidaryti/sukurti nepavyko"<<endl;
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
    double galBalas_m=0;
    double galBalas_v=0;
    while(!failas1.eof()) //skaitau faila iki pabaigos ir issisaugau visa info apie studenta, skaiciuoju blogu ir geru studentu kieki
    {
        int flag=0;
        failas1>>pavarde>>vardas;
        if (failas1.fail()) break;
        for(int i=0; i<nd_sk;i++) //issisaugau nd pazymius i vektoriu
        {
            failas1>>nd_paz;
            if (failas1.fail() && v.size()==0)
            {
                cerr<<pavarde<<" "<<vardas<<" neturi nei vieno namų darbų pažymio"<<endl;
                exit(1);
            }
            else if (failas1.fail() && v.size()==1)
            {
                cerr<<pavarde<<" "<<vardas<<" neturi nei vieno namų darbų pažymio"<<endl;
                exit(1);
            }
            else if (failas1.fail() && v.size()<5)
            {
                failas1.clear();
                auto it=v.begin();
                int last=static_cast<int>(v.size());
                last=last-1;
                advance (it,last);
                egz_paz=*it;
                v.end()=v.erase(it);
                flag=1;
                break;
            }
            v.push_back(nd_paz);
        }
        if (flag!=1)
        {
            failas1>>egz_paz;
            if (failas1.fail())
            {
                failas1.clear();
                auto it=v.begin();
                int last=static_cast<int>(v.size());
                last=last-1;
                advance (it,last);
                egz_paz=*it;
                v.end()=v.erase(it);
            }
        }
        galBalas_m=galBalas_mediana(v,egz_paz);
        galBalas_v=galBalas_vidurkis(v,egz_paz);
        studentas stud;
        stud.vardas=vardas;
        stud.pavarde=pavarde;
        stud.galBalas_m=galBalas_m;
        stud.galBalas_v=galBalas_v;
        stud.v=v;
        studentai.push_back(stud);
        v.clear();
    }
    strategija1(good,bad,studentai);
    rusiuokime(good);
    for(auto it=good.begin(); it!=good.end(); ++it) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<left<<setw(19)<<(*it).pavarde<<left<<setw(15)<<(*it).vardas<<left<<setw(20)<<setprecision(2) << fixed<<(*it).galBalas_v<<(*it).galBalas_m<<endl;
    }
    rusiuokime(bad);
    failas2<<endl<<"Vargšiukai:"<<endl<<left<<setw(20)<<"Pavardė"<<left<<setw(15)<<"Vardas"<<endl;
    for(auto it=bad.begin(); it!=bad.end(); ++it) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<left<<setw(19)<<(*it).pavarde<<left<<setw(15)<<(*it).vardas<<endl;
    }
    failas1.close();
    failas2.close();
}
template<typename T>
void failai2(char *argv[], T &good, T &studentai)
{
    string vardas;
    string pavarde;
    vector<int>v;
    int egz_paz=0, nd_paz=0, nd_sk=0;
    ifstream failas1;
    try
    {
        failas1.open (argv[1]);
        if (failas1.is_open()) {}
        else
        {
            throw exception();
        }
    }
    catch(std::exception &e)
    {
        e.what();
        cerr << "Duomenų failas nerastas."<<endl;
        exit(1);
    }
    ofstream failas2;
    failas2.open(argv[2]);
    if (!failas2)
    {
        cerr << "Rezultatų failo atidaryti/sukurti nepavyko"<<endl;
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
    double galBalas_m=0;
    double galBalas_v=0;
    while(!failas1.eof()) //skaitau faila iki pabaigos ir issisaugau visa info apie studenta, skaiciuoju blogu ir geru studentu kieki
    {
        int flag=0;
        failas1>>pavarde>>vardas;
        if (failas1.fail()) break;
        for(int i=0; i<nd_sk;i++) //issisaugau nd pazymius i vektoriu
        {
            failas1>>nd_paz;
            if (failas1.fail() && v.size()==0)
            {
                cerr<<pavarde<<" "<<vardas<<" neturi nei vieno namų darbų pažymio"<<endl;
                exit(1);
            }
            else if (failas1.fail() && v.size()==1)
            {
                cerr<<pavarde<<" "<<vardas<<" neturi nei vieno namų darbų pažymio"<<endl;
                exit(1);
            }
            else if (failas1.fail() && v.size()<5)
            {
                failas1.clear();
                auto it=v.begin();
                int last=static_cast<int>(v.size());
                last=last-1;
                advance (it,last);
                egz_paz=*it;
                v.end()=v.erase(it);
                flag=1;
                break;
            }
            v.push_back(nd_paz);
        }
        if (flag!=1)
        {
            failas1>>egz_paz;
            if (failas1.fail())
            {
                failas1.clear();
                auto it=v.begin();
                int last=static_cast<int>(v.size());
                last=last-1;
                advance (it,last);
                egz_paz=*it;
                v.end()=v.erase(it);
            }
        }
        galBalas_m=galBalas_mediana(v,egz_paz);
        galBalas_v=galBalas_vidurkis(v,egz_paz);
        studentas stud;
        stud.vardas=vardas;
        stud.pavarde=pavarde;
        stud.galBalas_m=galBalas_m;
        stud.galBalas_v=galBalas_v;
        stud.v=v;
        studentai.push_back(stud);
        v.clear();
    }
    strategija2(good,studentai);
    rusiuokime(good);
    for(auto it=good.begin(); it!=good.end(); ++it) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<left<<setw(19)<<(*it).pavarde<<left<<setw(15)<<(*it).vardas<<left<<setw(20)<<setprecision(2) << fixed<<(*it).galBalas_v<<(*it).galBalas_m<<endl;
    }
    rusiuokime(studentai);
    failas2<<endl<<"Vargšiukai:"<<endl<<left<<setw(20)<<"Pavardė"<<left<<setw(15)<<"Vardas"<<endl;
    for(auto it=studentai.begin(); it!=studentai.end(); ++it) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<left<<setw(19)<<(*it).pavarde<<left<<setw(15)<<(*it).vardas<<endl;
    }
    failas1.close();
    failas2.close();
}
template<typename T>
void strategija2(T &good, T &studentai)
{
    auto it = studentai.begin();
    while(it!=studentai.end())
    {
        auto vidurkis=std::accumulate((*it).v.begin(),(*it).v.end(),0.0)/(*it).v.size();
        if (vidurkis>=6)
        {
            good.push_back(*it);
            it=studentai.erase(it);
        }
        else
        {
            it++;
        }
    }
}
template<typename T>
void strategija1(T &good, T&bad, T &studentai)
{
    auto it = studentai.begin();
    while(it!=studentai.end())
    {
        auto vidurkis=std::accumulate((*it).v.begin(),(*it).v.end(),0.0)/(*it).v.size();
        if (vidurkis>=6)
        {
            good.push_back(*it);
            cout<<(*it).vardas<<endl;
        }
        else
        {
            bad.push_back(*it);
        }
        it++;
    }
}
#endif
