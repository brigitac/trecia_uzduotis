#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <random>
#include <fstream>
#include "studentas.h"

bool check_good(studentas &s)
{return s.vidurkis()>=6;}

bool check_bad(studentas &s)
{return !check_good(s);}

void rusiuokime(std::vector<studentas>& good)
{sort(good.begin(), good.end(), compare);}

void rusiuokime(std::list<studentas>& good)
{good.sort(compare);}

void rusiuokime(std::deque<studentas>& good)
{sort(good.begin(), good.end(), compare);}

bool compare(const studentas &lhs, const studentas &rhs)
{return lhs.getpavarde()<rhs.getpavarde();}

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
