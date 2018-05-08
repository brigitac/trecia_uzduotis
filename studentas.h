#ifndef STUDENTAS_H
#define STUDENTAS_H
#include <algorithm>
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
    inline double getgalBalas_m() const {return galBalas_m;}
    inline double getgalBalas_v() const {return galBalas_v;}
    inline std::string getvardas() const {return vardas;}
    inline std::string getpavarde() const {return pavarde;}
    double vidurkis();
    bool operator < (const studentas &s) const { return pavarde < s.pavarde;}
    bool operator==(const studentas& a) const {return a.vardas==vardas && a.pavarde==pavarde;}
    friend std::ostream& operator << (std::ostream&, const studentas&);
};
bool operator!=(const studentas& a, const studentas& b);
bool check_good(studentas &s);
bool check_bad(studentas &s);
void rusiuokime(std::vector<studentas>& good);
void rusiuokime(std::list<studentas>& good);
void rusiuokime(std::deque<studentas>& good);
template<typename T>
void irasykime(std::ostream &failas2, T &studentai)
{
    rusiuokime(studentai);
    typename T::iterator bound;
    bound = std::stable_partition(studentai.begin(), studentai.end(), check_good);
    failas2<<"Tie geresni:"<<std::endl<<std::left<<std::setw(20)<<"Pavardė"<<std::left<<std::setw(15)<<"Vardas"<<std::left<<std::setw(20)<<"Galutinis-vidurkis"<<"Galutinis-mediana"<<std::endl;
    for(auto it=studentai.begin(); it!=bound; ++it) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<(*it);
    }
    failas2<<std::endl<<"Vargšiukai:"<<std::endl<<std::left<<std::setw(20)<<"Pavardė"<<std::left<<std::setw(15)<<"Vardas"<<std::left<<std::setw(20)<<"Galutinis-vidurkis"<<"Galutinis-mediana"<<std::endl;
    for(auto it=bound; it!=studentai.end(); ++it) //irasineju rezultatus i kita faila apie visus mokinius
    {
          failas2<<(*it);
    }
}

#endif
