#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <fstream>
#include "galbalas.h"
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
