#ifndef STUDENTAS_H
#define STUDENTAS_H
#include "galbalas.h"

class studentas
{
private:
    std::string vardas;
    std::string pavarde;
    double galBalas_m;
    double galBalas_v;
    std::vector<int> v;
    void read(std::istream &in);
public:
    studentas(std::istream& is);
    studentas(): galBalas_m(0), galBalas_v(0) {}
    double getgalBalas_m() const {return galBalas_m;}
    double getgalBalas_v() const {return galBalas_v;}
    std::string getvardas() const {return vardas;}
    std::string getpavarde() const {return pavarde;}
    double vidurkis();
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
    failas2<<"Tie geresni:"<<std::endl<<std::left<<std::setw(20)<<"Pavardė"<<std::left<<std::setw(15)<<"Vardas"<<std::left<<std::setw(20)<<"Galutinis-vidurkis"<<"Galutinis-mediana"<<std::endl;
    for(auto it=good.begin(); it!=good.end(); ++it) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<std::left<<std::setw(19)<<(*it).getpavarde()<<std::left<<std::setw(15)<<(*it).getvardas()<<std::left<<std::setw(20)<<std::setprecision(2) << std::fixed<<(*it).getgalBalas_v()<<(*it).getgalBalas_m()<<std::endl;
    }
    failas2<<std::endl<<"Vargšiukai:"<<std::endl<<std::left<<std::setw(20)<<"Pavardė"<<std::left<<std::setw(15)<<"Vardas"<<std::endl;
    for(auto it=bad.begin(); it!=bad.end(); ++it) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<std::left<<std::setw(19)<<(*it).getpavarde()<<std::left<<std::setw(15)<<(*it).getvardas()<<std::endl;
    }
}

#endif
