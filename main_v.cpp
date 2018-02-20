#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
using std::cout; using std::cin; using std::endl; using std::string; using std::setprecision; using std::fixed; using std::vector; using std::ifstream; using std::ofstream; using std::setw; using std::left;
double galBalas_mediana(vector<int> v, int egz_paz);
double galBalas_vidurkis(vector<int> v, int egz_paz);
void generuojami_sk(vector<int>& v, int *egz_paz, int nd_sk);
void ivedami_sk(vector<int>& v, int *egz_paz, int nd_paz);
void duomenu_ivedimas(string vardas, string pavarde, int egz_paz, vector<int> v, double galBalas, int nd_sk, int nd_paz);
void failai(string vardas, string pavarde, int egz_paz, vector<int> v, char *argv[], int nd_sk, int nd_paz);
struct studentas
{
    string vardas;
    string pavarde;
    double galBalas_m;
    double galBalas_v;
};
bool compare(const studentas &lhs, const studentas &rhs);
int main (int, char *argv[])
{
    string vardas;
    string pavarde;
    vector<int>v;
    int egz_paz=0, nd_paz=0, nd_sk=0;
    double galBalas=0;
    cout<<"Jei norite duomenis suvesti, įveskite 1, jei norite nuskaityti iš failo - bet kokį kitą simbolį: ";
    int f=0;
    cin>>f;
    if (f==1) duomenu_ivedimas(vardas,pavarde,egz_paz,v,galBalas,nd_sk,nd_paz);
    else failai(vardas,pavarde,egz_paz,v,argv,nd_sk,nd_paz);
    return 0;
}
bool compare(const studentas &lhs, const studentas &rhs) {return lhs.pavarde<rhs.pavarde;}
void failai(string vardas, string pavarde, int egz_paz, vector<int> v, char *argv[], int nd_sk, int nd_paz)
{
    vector<studentas>sv;
    ifstream failas1;
    failas1.open (argv[1]);
    if (!failas1)
    {
        cout << "Duomenu failas nerastas";
        exit(1);
    }
    ofstream failas2;
    failas2.open(argv[2]);
    if (!failas2)
    {
        cout << "Rezultatu failas nerastas";
        exit(1);
    }
    failas2<<left<<setw(20)<<"Pavardė"<<left<<setw(15)<<"Vardas"<<left<<setw(20)<<"Galutinis-vidurkis"<<"Galutinis-mediana"<<endl;
    char simbol;
    do //skaiciuosiu, kiek yra zodziu pirmoj eilutej
    {
        failas1.get(simbol);
        if (simbol==' ')
        {
            nd_sk++;  //skaiciuoju, kiek yra zodziu
            do //praleidziu tarpus
            {
                failas1.get(simbol);
            }while(simbol==' ');
        }
    }while (simbol!='\n');
    nd_sk-=3; //suzinau, kiek buvo namu darbu, is visu pirmoj eilutej zodziu atemus 3, nes 3 zodziziai yra vardui, pavardei ir egzamino pazymiui
    //issisaugau reikiamus duomenis
    unsigned long o=0;
    double galBalas_m=0;
    double galBalas_v=0;
    while(!failas1.eof()) //skaitau faila iki pabaigos
    {
        failas1>>pavarde>>vardas;
        for(int i=0; i<nd_sk;i++) //issisaugau nd pazymius i vektoriu
        {
            failas1>>nd_paz;
            v.push_back(nd_paz);
        }
        failas1>>egz_paz;
        galBalas_m=galBalas_mediana(v,egz_paz);
        galBalas_v=galBalas_vidurkis(v,egz_paz);
        sv.push_back(studentas());
        sv[o].vardas=vardas;
        sv[o].pavarde=pavarde;
        sv[o].galBalas_m=galBalas_m;
        sv[o].galBalas_v=galBalas_v;
        vector<int>().swap(v);
        o++;
    }
    sort(sv.begin(), sv.end(), compare);
    for(unsigned long i=0; i<o;i++) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<left<<setw(20)<<sv[i].pavarde<<left<<setw(15)<<sv[i].vardas<<left<<setw(20)<<setprecision(2) << fixed<<sv[i].galBalas_v<<sv[i].galBalas_m<<endl;
    }
    failas1.close();
    failas2.close();
}
void duomenu_ivedimas(string vardas, string pavarde, int egz_paz, vector<int> v, double galBalas,int nd_sk, int nd_paz)
{
    cout << "Įveskite savo vardą: ";
    cin >> vardas;
    cout << "Įveskite savo pavardę: ";
    cin >> pavarde;
    cout << "Jei norite namų darbų ir egzamino pažymius suvesti, įveskite 1, jei norite sugeneruoti atsitiktinius skaičius - bet kokį kitą simbolį: ";
    int vg=0;
    cin>>vg;
    if (vg==1) ivedami_sk(v, &egz_paz, nd_paz);
    else generuojami_sk(v,&egz_paz,nd_sk);
    cout<<"Jei norite skaičiuoti galutinį balą pagal namų darbų vidurkį, įveskite 1, jei pagal mediana - bet kokį kitą simbolį: ";
    int vm=0;
    cin>>vm;
    cout<<"Studento, vardu "<<vardas<<" ir pavarde "<<pavarde<<", su namų darbų pažymiais: ";
    for (unsigned long i=0;i<v.size();i++) cout << v[i] <<" "; //isvedineju nd pazymius
    if(vm==1) galBalas=galBalas_vidurkis(v,egz_paz);
    else galBalas=galBalas_mediana(v,egz_paz);
    cout<<"ir galutiniu egzamino pažymiu "<<egz_paz<<", galutinis balas yra: "<<setprecision(2) << fixed<<galBalas<<endl;
}
double galBalas_vidurkis(vector<int> v, int egz_paz)
{
    double vidurkis=0;
    for (unsigned long i=0;i<v.size();i++) vidurkis += v[i]; //sudedineju nd pazymius
    vidurkis /= v.size();
    double galBalas=(0.6*egz_paz)+(0.4*vidurkis);
    return galBalas;
}
double galBalas_mediana(vector<int> v, int egz_paz)
{
    sort(v.begin(), v.end());
    double mediana=0;
    size_t vidurys=(v.size()/2);
    if (v.size()%2==0) mediana = (v[vidurys-1]+v[vidurys])/2.0;
    else mediana = v[vidurys];
    double galBalas=(0.6*egz_paz)+(0.4*mediana);
    return galBalas;
}
void ivedami_sk(vector<int>& v, int *egz_paz, int nd_paz)
{
    cout << "Įveskite namų darbų pažymius, norėdami užbaigti įveskite '0': ";
    cin>>nd_paz;
    while (nd_paz!=0) //nuskaitineju nd pazymius ir issisaugau i vektoriu
    {
        v.push_back(nd_paz);
        cin>>nd_paz;
    }
    cout << "Įveskite egzamino pažymį: ";
    cin >> (*egz_paz);
}
void generuojami_sk(vector<int>& v, int *egz_paz, int nd_sk)
{
    cout<<"Įveskite, kiek skaičių norite, kad būtų sugeneruota: ";
    cin>>nd_sk;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1,10);
    for(int i=0; i<nd_sk;++i) v.push_back(dist(mt)); //generuoju nd pazymius ir issisaugau i vektoriu
    *egz_paz=dist(mt);
}

