using std::cout; using std::cin; using std::endl; using std::string; using std::setprecision; using std::fixed; using std::vector; using std::ifstream; using std::ofstream; using std::setw; using std::left;
void failai(string vardas, string pavarde, int egz_paz, vector<int> v, char *argv[], int nd_sk, int nd_paz);
struct studentas
{
    string vardas;
    string pavarde;
    double galBalas_m;
    double galBalas_v;
};
bool compare(const studentas &lhs, const studentas &rhs);
