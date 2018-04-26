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
#include "studentas.h"
using std::cout; using std::cin; using std::endl; using std::string; using std::setprecision; using std::fixed; using std::vector; using std::ifstream; using std::ofstream; using std::setw; using std::left; using std::exception; using std::cerr;
template<typename T>
void failai(char *argv[], T &good, T &studentai)
{
    nuskaitymas(argv, studentai);
    strategija2(good,studentai);
    irasymas(argv, studentai, good);
}
template<typename T>
void nuskaitymas(char *argv[], T &studentai)
{
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
        
        studentas stud(failas1);
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
    irasykime(failas2, bad, good);
    failas2.close();
}


#endif
