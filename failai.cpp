#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <random>
#include <fstream>
#include "failai.h"
#include "galbalas.h"
#include "struktura.h"
bool compare(const studentas &lhs, const studentas &rhs) {return lhs.pavarde<rhs.pavarde;}
void failai(string vardas, string pavarde, int egz_paz, vector<int> v, char *argv[], int nd_sk, int nd_paz)
{
    auto start = std::chrono::high_resolution_clock::now();
    vector<studentas>good;
    vector<studentas>bad;
    ifstream failas1;
    try
    {
        failas1.open (argv[1]);
        if (failas1.is_open()) {
        } else {
            throw exception();
        }
    }
    catch(std::exception &e)
    {
        e.what();
        cout << "Duomenų failas nerastas."<<endl;
        exit(1);
    }
    ofstream failas2;
    failas2.open(argv[2]);
    if (!failas2)
    {
        cout << "Rezultatų failo atidaryti/sukurti nepavyko"<<endl;
        exit(1);
    }
    failas2<<"Tie geresni:"<<endl<<left<<setw(20)<<"Pavardė"<<left<<setw(15)<<"Vardas"<<left<<setw(20)<<"Galutinis-vidurkis"<<"Galutinis-mediana"<<endl;
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
    double galBalas_m=0;
    double galBalas_v=0;
    while(!failas1.eof()) //skaitau faila iki pabaigos ir issisaugau visa info apie studenta, skaiciuoju blogu ir geru studentu kieki
    {
        failas1>>pavarde>>vardas;
        for(int i=0; i<nd_sk;i++) //issisaugau nd pazymius i vektoriu
        {
            failas1>>nd_paz;
            v.push_back(nd_paz);
        }
        failas1>>egz_paz;
        double vidurkis=0;
        for (auto it=v.begin(); it!=v.end(); ++it) vidurkis += (*it); //susumuoju nd pazymius
        vidurkis /= v.size();
        if (vidurkis>=6)
        {
            galBalas_m=galBalas_mediana(v,egz_paz);
            galBalas_v=galBalas_vidurkis(v,egz_paz);
            studentas stud;
            stud.vardas=vardas;
            stud.pavarde=pavarde;
            stud.galBalas_m=galBalas_m;
            stud.galBalas_v=galBalas_v;
            good.push_back(stud);
        }
        else
        {
            studentas stud;
            stud.vardas=vardas;
            stud.pavarde=pavarde;
            bad.push_back(stud);
        }
        vector<int>().swap(v);
    }
    sort(good.begin(), good.end(), compare);
    for(auto it=good.begin(); it!=good.end(); ++it) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<left<<setw(19)<<(*it).pavarde<<left<<setw(15)<<(*it).vardas<<left<<setw(20)<<setprecision(2) << fixed<<(*it).galBalas_v<<(*it).galBalas_m<<endl;
    }
    sort(bad.begin(), bad.end(), compare);
    failas2<<endl<<"Vargšiukai:"<<endl<<left<<setw(20)<<"Pavardė"<<left<<setw(15)<<"Vardas"<<endl;
    for(auto it=bad.begin(); it!=bad.end(); ++it) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<left<<setw(19)<<(*it).pavarde<<left<<setw(15)<<(*it).vardas<<endl;
    }
    failas1.close();
    failas2.close();
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    cout << "Programos vykdymo laikas: " << elapsed.count() << " s\n";
}
void failaid(string vardas, string pavarde, int egz_paz, vector<int> v, char *argv[], int nd_sk, int nd_paz)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::deque<studentas>good;
    std::deque<studentas>bad;
    ifstream failas1;
    try
    {
        failas1.open (argv[1]);
        if (failas1.is_open()) {
        } else {
            throw exception();
        }
    }
    catch(std::exception &e)
    {
        e.what();
        cout << "Duomenų failas nerastas."<<endl;
        exit(1);
    }
    ofstream failas2;
    failas2.open(argv[2]);
    if (!failas2)
    {
        cout << "Rezultatų failo atidaryti/sukurti nepavyko"<<endl;
        exit(1);
    }
    failas2<<"Tie geresni:"<<endl<<left<<setw(20)<<"Pavardė"<<left<<setw(15)<<"Vardas"<<left<<setw(20)<<"Galutinis-vidurkis"<<"Galutinis-mediana"<<endl;
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
    double galBalas_m=0;
    double galBalas_v=0;
    while(!failas1.eof()) //skaitau faila iki pabaigos ir issisaugau visa info apie studenta, skaiciuoju blogu ir geru studentu kieki
    {
        failas1>>pavarde>>vardas;
        for(int i=0; i<nd_sk;i++) //issisaugau nd pazymius i vektoriu
        {
            failas1>>nd_paz;
            v.push_back(nd_paz);
        }
        failas1>>egz_paz;
        double vidurkis=0;
        for (auto it=v.begin(); it!=v.end(); ++it) vidurkis += (*it); //susumuoju nd pazymius
        vidurkis /= v.size();
        if (vidurkis>=6)
        {
            galBalas_m=galBalas_mediana(v,egz_paz);
            galBalas_v=galBalas_vidurkis(v,egz_paz);
            studentas stud;
            stud.vardas=vardas;
            stud.pavarde=pavarde;
            stud.galBalas_m=galBalas_m;
            stud.galBalas_v=galBalas_v;
            good.push_back(stud);
        }
        else
        {
            studentas stud;
            stud.vardas=vardas;
            stud.pavarde=pavarde;
            bad.push_back(stud);
        }
        vector<int>().swap(v);
    }
    sort(good.begin(), good.end(), compare);
    for(auto it=good.begin(); it!=good.end(); ++it) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<left<<setw(19)<<(*it).pavarde<<left<<setw(15)<<(*it).vardas<<left<<setw(20)<<setprecision(2) << fixed<<(*it).galBalas_v<<(*it).galBalas_m<<endl;
    }
    sort(bad.begin(), bad.end(), compare);
    failas2<<endl<<"Vargšiukai:"<<endl<<left<<setw(20)<<"Pavardė"<<left<<setw(15)<<"Vardas"<<endl;
    for(auto it=bad.begin(); it!=bad.end(); ++it) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<left<<setw(19)<<(*it).pavarde<<left<<setw(15)<<(*it).vardas<<endl;
    }
    failas1.close();
    failas2.close();
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    cout << "Programos vykdymo laikas: " << elapsed.count() << " s\n";
}
void failail(string vardas, string pavarde, int egz_paz, vector<int> v, char *argv[], int nd_sk, int nd_paz)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::list<studentas>good;
    std::list<studentas>bad;
    ifstream failas1;
    try
    {
        failas1.open (argv[1]);
        if (failas1.is_open()) {
        } else {
            throw exception();
        }
    }
    catch(std::exception &e)
    {
        e.what();
        cout << "Duomenų failas nerastas."<<endl;
        exit(1);
    }
    ofstream failas2;
    failas2.open(argv[2]);
    if (!failas2)
    {
        cout << "Rezultatų failo atidaryti/sukurti nepavyko"<<endl;
        exit(1);
    }
    failas2<<"Tie geresni:"<<endl<<left<<setw(20)<<"Pavardė"<<left<<setw(15)<<"Vardas"<<left<<setw(20)<<"Galutinis-vidurkis"<<"Galutinis-mediana"<<endl;
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
    double galBalas_m=0;
    double galBalas_v=0;
    while(!failas1.eof()) //skaitau faila iki pabaigos ir issisaugau visa info apie studenta, skaiciuoju blogu ir geru studentu kieki
    {
        failas1>>pavarde>>vardas;
        for(int i=0; i<nd_sk;i++) //issisaugau nd pazymius i vektoriu
        {
            failas1>>nd_paz;
            v.push_back(nd_paz);
        }
        failas1>>egz_paz;
        double vidurkis=0;
        for (auto it=v.begin(); it!=v.end(); ++it) vidurkis += (*it); //susumuoju nd pazymius
        vidurkis /= v.size();
        if (vidurkis>=6)
        {
            galBalas_m=galBalas_mediana(v,egz_paz);
            galBalas_v=galBalas_vidurkis(v,egz_paz);
            good.push_back(studentas());
            good.back().vardas=vardas;
            good.back().pavarde=pavarde;
            good.back().galBalas_m=galBalas_m;
            good.back().galBalas_v=galBalas_v;
        }
        else
        {
            bad.push_back(studentas());
            bad.back().vardas=vardas;
            bad.back().pavarde=pavarde;
        }
        vector<int>().swap(v);
    }
    good.sort(compare);
    for(auto it=good.begin(); it!=good.end(); ++it) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<left<<setw(19)<<(*it).pavarde<<left<<setw(15)<<(*it).vardas<<left<<setw(20)<<setprecision(2) << fixed<<(*it).galBalas_v<<(*it).galBalas_m<<endl;
    }
    bad.sort(compare);
    failas2<<endl<<"Vargšiukai:"<<endl<<left<<setw(20)<<"Pavardė"<<left<<setw(15)<<"Vardas"<<endl;
    for(auto it=bad.begin(); it!=bad.end(); ++it) //irasineju rezultatus i kita faila apie visus mokinius
    {
        failas2<<left<<setw(19)<<(*it).pavarde<<left<<setw(15)<<(*it).vardas<<endl;
    }
    failas1.close();
    failas2.close();
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    cout << "Programos vykdymo laikas: " << elapsed.count() << " s\n";
}

