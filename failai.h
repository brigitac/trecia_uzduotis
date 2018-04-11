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
bool check_good(studentas &s);
bool check_bad(studentas &s);
void rusiuokime(vector<studentas>& good);
void rusiuokime(std::list<studentas>& good);
void rusiuokime(std::deque<studentas>& good);
bool compare(const studentas &lhs, const studentas &rhs) {return lhs.pavarde<rhs.pavarde;}
void rusiuokime(vector<studentas>& good){sort(good.begin(), good.end(), compare);}
void rusiuokime(std::list<studentas>& good){good.sort(compare);}
void rusiuokime(std::deque<studentas>& good){sort(good.begin(), good.end(), compare);}

template<typename T>
void failai(char *argv[], T &good, T &bad, T &studentai, int strategija)
{
    nuskaitymas(argv, studentai);
    if (strategija==1)
    {
        strategija1(good,bad,studentai);
        irasymas(argv, bad, good);
    }
    else
    {
        strategija2(good,studentai);
        irasymas(argv, studentai, good);
    }
}

template<typename T>
void nuskaitymas(char *argv[], T &studentai)
{
    string vardas;
    string pavarde;
    vector<int>v;
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
    string pirma_eil;
    getline(failas1,pirma_eil);
    while(!failas1.eof()) //skaitau faila iki pabaigos ir issisaugau visa info apie studenta
    {
        studentas stud;
        stud.read(failas1);
        studentai.push_back(stud);
    }
    failas1.close();
}

template<typename T>
void irasymas(char *argv[], T &bad, T &good)
{
    ofstream failas2;
    failas2.open(argv[2]);
    if (!failas2)
    {
        cerr << "Rezultatų failo atidaryti/sukurti nepavyko"<<endl;
        exit(1);
    }
    failas2<<"Tie geresni:"<<endl<<left<<setw(20)<<"Pavardė"<<left<<setw(15)<<"Vardas"<<left<<setw(20)<<"Galutinis-vidurkis"<<"Galutinis-mediana"<<endl;
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
    failas2.close();
}

template<typename T>
void strategija1(T &good, T &bad, T &studentai)
{
     std::remove_copy_if(studentai.begin(),studentai.end(),std::back_inserter(good),check_bad);
     std::remove_copy_if(studentai.begin(),studentai.end(),std::back_inserter(bad),check_good);
}
template<typename T>
void strategija2(T &good, T &studentai)
{
    std::remove_copy_if(studentai.begin(),studentai.end(),std::back_inserter(good),check_bad);
    studentai.erase(remove_if(studentai.begin(),studentai.end(),check_good), studentai.end());
}

bool check_good(studentas &s)
{
    auto vidurkis=std::accumulate(s.v.begin(),s.v.end(),0.0)/s.v.size();
    return vidurkis>=6;
}
bool check_bad(studentas &s)
{
    return !check_good(s);
}

#endif
