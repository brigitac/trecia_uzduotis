#ifndef STRUKTURA_H
#define STRUKTURA_H
using std::cout; using std::cin; using std::endl; using std::string; using std::setprecision; using std::fixed; using std::vector; using std::ifstream; using std::ofstream; using std::setw; using std::left; using std::exception; using std::cerr;
class studentas
{
public:
    std::string vardas;
    std::string pavarde;
    double galBalas_m;
    double galBalas_v;
    std::vector<int>v;
void read(std::istream &in)
{
    int egz_paz=0, nd_paz=0;
    const int nd_sk=5;
    in>>pavarde>>vardas;
    for(int i=0; i<nd_sk;i++) //issisaugau nd pazymius i vektoriu
    {
        in>>nd_paz;
        if (in.fail() && v.size()<nd_sk)
        {
            cerr<<pavarde<<" "<<vardas<<" trūksta pažymių"<<endl;
            exit(1);
        }
        v.push_back(nd_paz);
    }
    in>>egz_paz;
    galBalas_m=galBalas_mediana(v,egz_paz);
    galBalas_v=galBalas_vidurkis(v,egz_paz);
}
};
#endif
