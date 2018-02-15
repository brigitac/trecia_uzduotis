#include <iostream>
#include <string>
#include <iomanip>
using std::cout; using std::cin; using std::endl; using std::string; using std::setprecision; using std::fixed;
double galBalas_vidurkis(int mas[],int nd_sk, int egz_paz);
double galBalas_mediana(int mas[],int nd_sk, int egz_paz);
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
    int *mas=new int[nd_sk];
    for (auto i=1;i<=nd_sk;i++)
    {
    auto j=i-1;
    cout << "Įveskite, kiek " <<vardas<<" "<<pavarde<< " gavo iš "<<i<<" namų darbų: ";
    cin >> mas[j];
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
        cout << mas[i] <<" ";
    }
    if(vm==1)
    {
        galBalas=galBalas_vidurkis(mas,nd_sk,egz_paz);
    }
    else
    {
        galBalas=galBalas_mediana(mas,nd_sk,egz_paz);
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

double galBalas_mediana(int mas[], int nd_sk, int egz_paz)
{
    //sutvarkau masyva
    int j=0, a=0;
    for (int i = 0; i < nd_sk; i++)
    {
        j = i;
        while (j > 0 && mas[j] < mas[j-1]){
            a = mas[j];
            mas[j] = mas[j-1];
            mas[j-1] = a;
            j--;
        }
    }
    //ieskau medianos
    double mediana=0;
    int vidurys=(nd_sk/2);
    if (nd_sk%2==0)
    {
        mediana = (mas[vidurys-1]+mas[vidurys])/2.0;
    }
    else
    {
        mediana = mas[vidurys];
    }
    //apskaiciuoju galutini bala
    double galBalas=(0.6*egz_paz)+(0.4*mediana);
    return galBalas;
}
