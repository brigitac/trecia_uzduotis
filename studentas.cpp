#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <random>
#include <fstream>
#include "studentas.h"
using std::cout; using std::cin; using std::endl; using std::string; using std::setprecision; using std::fixed; using std::vector; using std::ifstream; using std::ofstream; using std::setw; using std::left; using std::exception; using std::cerr;
bool check_good(studentas &s)
{
    auto vidurkis=std::accumulate(s.v.begin(),s.v.end(),0.0)/s.v.size();
    return vidurkis>=6;
}
bool check_bad(studentas &s)
{return !check_good(s);}
void rusiuokime(vector<studentas>& good)
{sort(good.begin(), good.end(), compare);}
void rusiuokime(std::list<studentas>& good)
{good.sort(compare);}
void rusiuokime(std::deque<studentas>& good)
{sort(good.begin(), good.end(), compare);}
bool compare(const studentas &lhs, const studentas &rhs)
{return lhs.getpavarde()<rhs.getpavarde();}
//KODEL NEGALIU CIA PERKLET???
//void read(std::istream &in)
//{
//    int egz_paz=0, nd_paz=0;
//    const int nd_sk=5;
//    in>>pavarde>>vardas;
//    for(int i=0; i<nd_sk;i++) //issisaugau nd pazymius i vektoriu
//    {
//        in>>nd_paz;
//        if (in.fail() && v.size()<nd_sk)
//        {
//            std::cerr<<pavarde()<<" "<<vardas()<<" trūksta pažymių"<<std::endl;
//            exit(1);
//        }
//        v.push_back(nd_paz);
//    }
//    in>>egz_paz;
//    galBalas_m=galBalas_mediana(v,egz_paz);
//    galBalas_v=galBalas_vidurkis(v,egz_paz);
//    }

