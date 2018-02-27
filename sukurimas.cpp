#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include "sukurimas.h"
int belekoks()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1,10);
    return dist(mt);
}
void sukurimas(int kiekis, char *argv[], int nd_sk)
{
    int k=kiekis;
    int s=0;
    while(k>0) //suskaiciuoju skaitmenu kieki kintamajame kiekis
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
    sukurtas<<left<<setw(9+s)<<"Pavarde"<<left<<setw(9+s)<<"Vardas";
    nd_sk=5;
    for(int i=0; i<nd_sk;i++) //isspausdinu ND1 ND2 ... ND5
    {
        sukurtas<<left<<setw(4)<<"ND"+to_string(i+1);
    }
    sukurtas<<"Egzaminas "<<endl;
    for(int i=0; i<kiekis;i++) // isspausdinu 'kiekis' studentu irasu 
    {
        sukurtas<<left<<setw(9+s)<<"Pavarde"+to_string(i+1)<<left<<setw(9+s)<<"Vardas"+to_string(i+1);
        for(int j=0; j<nd_sk;j++)
        {
            sukurtas<<left<<setw(4)<<belekoks();
        }
        sukurtas<<belekoks()<<endl;
    }
    sukurtas.close();
}


