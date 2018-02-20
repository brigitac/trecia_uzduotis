#include <iostream>
#include <string>
#include <iomanip>
using std::cout; using std::cin; using std::endl; using std::string; using std::setprecision; using std::fixed;
double galBalas_mediana(int mas[],int nd_sk, int egz_paz);
double galBalas_vidurkis(int mas[],int nd_sk, int egz_paz);
int* masyvo_tvarkymas(int mas[],int nd_paz,int nd_sk,int *dydis);
int main()
{
    cout << "Įveskite savo vardą: ";
    string vardas;
    cin >> vardas;
    cout << "Įveskite savo pavardę: ";
    string pavarde;
    cin >> pavarde;
    cout << "Įveskite, kokius pažymius "<<vardas<<" "<<pavarde<<" gavo iš namų darbų, norėdami užbaigti įveskite '0': ";
    int dydis=1;
    int *mas=new int[dydis];
    int nd_paz=0, nd_sk=0;
    cin>>nd_paz;
    while (nd_paz!=0)     //nuskaitomi ivesti pazymiai
    {
        nd_sk++;        //skaiciuojamas pazymiu skaicius
        mas=masyvo_tvarkymas(mas,nd_paz,nd_sk,&dydis);
        cin>>nd_paz;
    }
    cout << "Įveskite, kiek "<<vardas<<" "<<pavarde<<" gavo iš egzamino: ";
    int egz_paz=0;
    cin >> egz_paz;
    cout<<"Jei norite skaičiuoti galutinį balą pagal namų darbų vidurkį, įveskite 1, jeigu pagal mediana - bet kokį kitą simbolį: ";
    int vm=0;
    double galBalas=0;
    cin>>vm;
    cout<<"Studento, vardu "<<vardas<<" ir pavarde "<<pavarde<<", su namų darbų pažymiais: ";
    //isvedami pazymiai
    for (int i=0;i<nd_sk;i++) cout << mas[i] <<" ";
    if(vm==1) galBalas=galBalas_vidurkis(mas,nd_sk,egz_paz);
    else galBalas=galBalas_mediana(mas,nd_sk,egz_paz);
    cout<<"ir galutiniu egzamino pažymiu "<<egz_paz<<", galutinis balas yra: "<<setprecision(2) << fixed<<galBalas<<endl;
    return 0;
}
double galBalas_vidurkis(int mas[],int nd_sk, int egz_paz)
{
    double vidurkis=0;
    for (int i=0;i<nd_sk;i++) vidurkis += mas[i];     //sudedami visi nd_pazymiai
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
        while (j > 0 && mas[j] < mas[j-1])
        {
            a = mas[j];
            mas[j] = mas[j-1];
            mas[j-1] = a;
            j--;
        }
    }
    //ieskau medianos
    double mediana=0;
    int vidurys=(nd_sk/2);
    if (nd_sk%2==0) mediana = (mas[vidurys-1]+mas[vidurys])/2.0;
    else mediana = mas[vidurys];
    //apskaiciuoju galutini bala
    double galBalas=(0.6*egz_paz)+(0.4*mediana);
    return galBalas;
}
int* masyvo_tvarkymas(int *mas,int nd_paz,int nd_sk, int *dydis)
{
    if ((*dydis)>=nd_sk)
    {
        mas[nd_sk-1] = nd_paz;
        return mas;
    }
    else
    {
        int *mas2=new int[(*dydis)+1];
        for(int i=0;i<(*dydis);i++) mas2[i]=mas[i]; //nukopinu viena masyva i kita
        mas2[(*dydis)]=nd_paz;
        delete[] mas;
        (*dydis)++;
        return mas2;
    }
}
