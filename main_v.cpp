#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using std::cout; using std::cin; using std::endl; using std::string; using std::setprecision; using std::fixed; using std::vector;
double galBalas_mediana(vector<int> v,int nd_sk, int egz_paz);
double galBalas_vidurkis(vector<int> v,int nd_sk, int egz_paz);
int main()
{
    cout << "Įveskite savo vardą: ";
    string vardas;
    cin >> vardas;
    cout << "Įveskite savo pavardę: ";
    string pavarde;
    cin >> pavarde;
    cout << "Įveskite, kokius pažymius "<<vardas<<" "<<pavarde<<" gavo iš namų darbų, norėdami užbaigti įveskite '0': ";
    vector<int>v;
    auto nd_paz=0, nd_sk=0;
    cin>>nd_paz;
    while (nd_paz!=0)
    {
        nd_sk++;
        v.push_back(nd_paz);
        cin>>nd_paz;
    }
    cout << "Įveskite, kiek "<<vardas<<" "<<pavarde<<" gavo iš egzamino: ";
    auto egz_paz=0;
    cin >> egz_paz;
    cout<<"Jei norite skaičiuoti galutinį balą pagal namų darbų vidurkį, įveskite 1, jeigu pagal mediana - bet kokį kitą simbolį: ";
    auto vm=0;
    double galBalas=0;
    cin>>vm;
    cout<<"Studento, vardu "<<vardas<<" ir pavarde "<<pavarde<<", su namų darbų pažymiais: ";
    for (auto i=0;i<nd_sk;i++)
    {
        cout << v[i] <<" ";
    }
    if(vm==1)
    {
        galBalas=galBalas_vidurkis(v,nd_sk,egz_paz);
    }
    else
    {
        galBalas=galBalas_mediana(v,nd_sk,egz_paz);
    }
    cout<<"ir galutiniu egzamino pažymiu "<<egz_paz<<", galutinis balas yra: "<<setprecision(2) << fixed<<galBalas<<endl;
    return 0;
}
double galBalas_vidurkis(vector<int> v,int nd_sk, int egz_paz)
{
    double vidurkis=0;
    for (auto i=0;i<=nd_sk;i++)
    {
        vidurkis += v[i];
    }
    vidurkis /= nd_sk;
    double galBalas=(0.6*egz_paz)+(0.4*vidurkis);
    return galBalas;
}
double galBalas_mediana(vector<int> v, int nd_sk, int egz_paz)
{
    //sutvarkau masyva
    sort(v.begin(), v.end());
    //ieskau medianos
    double mediana=0;
    int vidurys=(nd_sk/2);
    if (nd_sk%2==0)
    {
        mediana = (v[vidurys-1]+v[vidurys])/2.0;
    }
    else
    {
        mediana = v[vidurys];
    }
    //apskaiciuoju galutini bala
    double galBalas=(0.6*egz_paz)+(0.4*mediana);
    return galBalas;
}
