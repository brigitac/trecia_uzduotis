#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include "sukurimas.h"
using std::cout; using std::cin; using std::endl; using std::string; using std::setprecision; using std::fixed; using std::vector; using std::ifstream; using std::ofstream; using std::setw; using std::left; using std::exception; using std::to_string;
int belekoks()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1,10);
    return dist(mt);
}
void sukurimas(int kiekis, char *argv[])
{
    int k=kiekis;
    int s=0; //cia bus skaitmenu kiekis skaiciuje 'kiekis'
    while(k>0) //suskaiciuoju skaitmenu kieki kintamajame kiekis, kuris parodo, kiek irasu sugeneruoti
    {
        k/=10;
        s++;
    }
    s++;
    ofstream sukurtas;
    sukurtas.open(argv[1]);
    if (!sukurtas)
    {
        cout << "Failo sukurti nepavyko";
        exit(1);
    }
    const auto tarpai=9+s;
    sukurtas<<left<<setw(tarpai)<<"Pavarde"<<left<<setw(tarpai)<<"Vardas";
    const auto nd_sk=5;
    for(int i=0; i<nd_sk;i++) //isspausdinu ND1 ND2 ... ND5
    {
        sukurtas<<left<<setw(4)<<"ND"+to_string(i+1);
    }
    sukurtas<<"Egzaminas "<<endl;
    for(int i=0; i<kiekis;i++) // isspausdinu 'kiekis' studentu irasu 
    {
        sukurtas<<left<<setw(tarpai)<<"Pavarde"+to_string(i+1)<<left<<setw(tarpai)<<"Vardas"+to_string(i+1);
        for(int j=0; j<=nd_sk;j++) //isspausdinu random sugeneruotus namu darbus ir egzamino pazymi
        {
            sukurtas<<left<<setw(4)<<belekoks();
        }
        sukurtas<<endl;
    }
    sukurtas.close();
}
