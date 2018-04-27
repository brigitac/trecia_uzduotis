#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <random>
#include <fstream>
#include <algorithm>
#include "studentas.h"

bool operator!=(const studentas& a, const studentas& b)
{return !(a==b);}

bool check_good(studentas &s)
{return s.vidurkis()>=6;}

bool check_bad(studentas &s)
{return !check_good(s);}

void rusiuokime(std::vector<studentas>& good)
{sort(good.begin(), good.end());}

void rusiuokime(std::list<studentas>& good)
{good.sort();}

void rusiuokime(std::deque<studentas>& good)
{sort(good.begin(), good.end());}

studentas::studentas(std::istream& is)
{
    read(is);
}

void studentas::read(std::istream &in)
{
    int egz_paz=0, nd_paz=0;
    const int nd_sk=5;
    in>>pavarde>>vardas;
    for(int i=0; i<nd_sk;i++) //issisaugau nd pazymius i vektoriu
    {
        in>>nd_paz;
        if (in.fail() && v.size()<nd_sk)
        {
            std::cerr<<pavarde<<" "<<vardas<<" trūksta pažymių"<<std::endl;
            exit(1);
        }
        v.push_back(nd_paz);
    }
    in>>egz_paz;
    galBalas_m=galBalas_mediana(v,egz_paz);
    galBalas_v=galBalas_vidurkis(v,egz_paz);
}

double studentas::vidurkis()
{return std::accumulate(v.begin(),v.end(),0.0)/v.size();}


std::ostream& operator<<(std::ostream&out, const studentas&s)
{
    out<<std::left<<std::setw(19)<<s.pavarde<<std::left<<std::setw(15)<<s.vardas<<std::left<<std::setw(20)<<std::setprecision(2) << std::fixed<<s.galBalas_v<<s.galBalas_m<<std::endl;
    return out;
}
