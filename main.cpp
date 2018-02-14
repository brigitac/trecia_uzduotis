#include <iostream>
#include <string>
#include <iomanip>
#define dydis 250
using std::cout; using std::cin; using std::endl; using std::string; using std::setprecision; using std::fixed;
double galBalas_vidurkis(int mas[],int nd_sk, int egz_paz);
int main()
{
    cout << "Įveskite savo vardą: ";
    string vardas;
    cin >> vardas;
    cout << "Įveskite savo pavardę: ";
    string pavarde;
    cin >> pavarde;
    cout << "Įveskite, kiek namų darbų turėjo "<<vardas<<" "<<pavarde<<": ";
    auto nd_sk=0;
    cin >> nd_sk;
    int masyvas[dydis];
    for (auto i=1;i<=nd_sk;i++)
    {
    auto j=i-1;
    cout << "Įveskite, kiek " <<vardas<<" "<<pavarde<< " gavo is "<<i<<" namų darbų: ";
    cin >> masyvas[j];
    }
    cout << "Įveskite, kiek "<<vardas<<" "<<pavarde<<" gavo iš egzamino: ";
    auto egz_paz=0;
    cin >> egz_paz;
    double galBalas=galBalas_vidurkis(masyvas,nd_sk,egz_paz);
    cout<<"Studento, vardu "<<vardas<<" ir pavarde "<<pavarde<<", su namų darbų pažymiais: ";
    for (auto i=0;i<nd_sk;i++)
    {
        cout << masyvas[i] <<" ";
    }
    cout<<"ir galutiniu egzamino pažymiu "<<egz_paz<<", galutinis balas yra: "<<setprecision(2) << fixed<<galBalas<<endl;
    return 0;
}
double galBalas_vidurkis(int mas[],int nd_sk, int egz_paz)
{
    double vidurkis=0;
    for (auto i=0;i<=nd_sk;i++)
    {
        vidurkis += mas[i];
    }
    vidurkis /= nd_sk;
    double galBalas=(0.6*egz_paz)+(0.4*vidurkis);
    return galBalas;
}

