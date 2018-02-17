#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
using std::cout; using std::cin; using std::endl; using std::string; using std::setprecision; using std::fixed; using std::vector;
double galBalas_mediana(vector<int> v, int egz_paz);
double galBalas_vidurkis(vector<int> v, int egz_paz);
void generuojami_sk(vector<int>& v, int *egz_paz);
void ivedami_sk(vector<int>& v, int *egz_paz);
int main()
{
    cout << "Įveskite savo vardą: ";
    string vardas;
    cin >> vardas;
    cout << "Įveskite savo pavardę: ";
    string pavarde;
    cin >> pavarde;
    cout << "Jei norite namų darbų ir egzamino pažymius suvesti, įveskite 1, jei norite sugeneruoti atsitiktinius skaičius - bet kokį kitą simbolį: ";
    vector<int>v;
    auto vg=0;
    int egz_paz=0;
    cin>>vg;
    if (vg==1) ivedami_sk(v, &egz_paz);
    else generuojami_sk(v,&egz_paz);
    cout<<"Jei norite skaičiuoti galutinį balą pagal namų darbų vidurkį, įveskite 1, jei pagal mediana - bet kokį kitą simbolį: ";
    auto vm=0;
    double galBalas=0;
    cin>>vm;
    cout<<"Studento, vardu "<<vardas<<" ir pavarde "<<pavarde<<", su namų darbų pažymiais: ";
    for (auto i=0;i<v.size();i++) cout << v[i] <<" ";
    if(vm==1) galBalas=galBalas_vidurkis(v,egz_paz);
    else galBalas=galBalas_mediana(v,egz_paz);
    cout<<"ir galutiniu egzamino pažymiu "<<egz_paz<<", galutinis balas yra: "<<setprecision(2) << fixed<<galBalas<<endl;
    return 0;
}
double galBalas_vidurkis(vector<int> v, int egz_paz)
{
    double vidurkis=0;
    for (auto i=0;i<v.size();i++) vidurkis += v[i];
    vidurkis /= v.size();
    double galBalas=(0.6*egz_paz)+(0.4*vidurkis);
    return galBalas;
}
double galBalas_mediana(vector<int> v, int egz_paz)
{
    //sutvarkau masyva
    sort(v.begin(), v.end());
    //ieskau medianos
    double mediana=0;
    auto vidurys=(v.size()/2);
    if (v.size()%2==0) mediana = (v[vidurys-1]+v[vidurys])/2.0;
    else mediana = v[vidurys];
    //apskaiciuoju galutini bala
    double galBalas=(0.6*egz_paz)+(0.4*mediana);
    return galBalas;
}
void ivedami_sk(vector<int>& v, int *egz_paz)
{
    cout << "Įveskite namų darbų pažymius, norėdami užbaigti įveskite '0': ";
    auto nd_paz=0, nd_sk=0;
    cin>>nd_paz;
    while (nd_paz!=0)
    {
        nd_sk++;
        v.push_back(nd_paz);
        cin>>nd_paz;
    }
    cout << "Įveskite egzamino pažymį: ";
    cin >> (*egz_paz);
}
void generuojami_sk(vector<int>& v, int *egz_paz)
{
    cout<<"Įveskite, kiek skaičių norite, kad būtų sugeneruota: ";
    auto nd_sk=0;
    cin>>nd_sk;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1,10);
    for(int i=0; i<nd_sk;++i) v.push_back(dist(mt));
    *egz_paz=dist(mt);
}
