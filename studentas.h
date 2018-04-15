#ifndef STUDENTAS_H
#define STUDENTAS_H
#include "galbalas.h"
using std::cout; using std::cin; using std::endl; using std::string; using std::setprecision; using std::fixed; using std::vector; using std::ifstream; using std::ofstream; using std::setw; using std::left; using std::exception; using std::cerr;
class studentas
{
private:
    std::string vardas;
    std::string pavarde;
    double galBalas_m;
    double galBalas_v;
public:
    std::vector<int> v; // kazkaip perkelt i private!
    double getgalBalas_m() const {return galBalas_m;}
    double getgalBalas_v() const {return galBalas_v;}
    std::string getvardas() const {return vardas;}
    std::string getpavarde() const {return pavarde;}
    void read(std::istream &in)
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
};
bool check_good(studentas &s);
bool check_bad(studentas &s);
void rusiuokime(std::vector<studentas>& good);
void rusiuokime(std::list<studentas>& good);
void rusiuokime(std::deque<studentas>& good);
bool compare(const studentas &lhs, const studentas &rhs);
template<typename T>
void strategija2(T &good, T &studentai)
{
    std::remove_copy_if(studentai.begin(),studentai.end(),std::back_inserter(good),check_bad);
    studentai.erase(remove_if(studentai.begin(),studentai.end(),check_good), studentai.end());
}
template<typename T>
void irasykime(std::ostream &failas2, T &bad, T &good)
{
    rusiuokime(good);
    rusiuokime(bad);
    failas2<<"Tie geresni:"<<endl<<left<<setw(20)<<"Pavardė"<<left<<setw(15)<<"Vardas"<<left<<setw(20)<<"Galutinis-vidurkis"<<"Galutinis-mediana"<<endl;
    for(auto it=good.begin(); it!=good.end(); ++it) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<left<<setw(19)<<(*it).getpavarde()<<left<<setw(15)<<(*it).getvardas()<<left<<setw(20)<<setprecision(2) << fixed<<(*it).getgalBalas_v()<<(*it).getgalBalas_m()<<endl;
    }
    failas2<<endl<<"Vargšiukai:"<<endl<<left<<setw(20)<<"Pavardė"<<left<<setw(15)<<"Vardas"<<endl;
    for(auto it=bad.begin(); it!=bad.end(); ++it) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<left<<setw(19)<<(*it).getpavarde()<<left<<setw(15)<<(*it).getvardas()<<endl;
    }
}
#endif
