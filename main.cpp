#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl; using std::string;
int main()
{
    cout << "Įveskite savo vardą: ";
    string vardas;
    cin >> vardas;
    cout << "Įveskite savo pavardę: ";
    string pavarde;
    cin >> pavarde;
    cout << "Įveskite, kiek namų darbų turėjo "<<vardas<<" "<<pavarde<<" : ";
    auto nd_sk=0;
    cin >> nd_sk;
    for (auto i=1;i<nd_sk;i++)
    {
    cout << "Įveskite, kiek " <<vardas<<" "<<pavarde<< " gavo is "<<i<<" namų darbų: ";
    }
    cout << "Įveskite, kiek "<<vardas<<" "<<pavarde<<" gavo iš egzamino: ";
    auto egz_paz=0;
    cin >> egz_paz;
    return 0;
}

