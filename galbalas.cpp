#include <iostream>
#include <vector>
#include "galbalas.h"
double galBalas_vidurkis(const vector<int>& v, int egz_paz)
{
    double vidurkis=0;
    for (const auto& elem:v) vidurkis+=elem; //susumuoju nd pazymius
    vidurkis /= v.size();
    const double galBalas=(0.6*egz_paz)+(0.4*vidurkis);
    return galBalas;
}
double galBalas_mediana(vector<int>& v, int egz_paz)
{
    sort(v.begin(), v.end());
    double mediana=0;
    const auto vidurys=(v.size()/2);
    if (v.size()%2==0) mediana = (v[vidurys-1]+v[vidurys])/2.0;
    else mediana = v[vidurys];
    const double galBalas=(0.6*egz_paz)+(0.4*mediana);
    return galBalas;
}
