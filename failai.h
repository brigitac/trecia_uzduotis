#ifndef FAILAI_H
#define FAILAI_H
#include "struktura.h"
using std::cout; using std::cin; using std::endl; using std::string; using std::setprecision; using std::fixed; using std::vector; using std::ifstream; using std::ofstream; using std::setw; using std::left; using std::exception;
void failai(char *argv[]);
void failail(char *argv[]);
void failaid(char *argv[]);
bool compare(const studentas &lhs, const studentas &rhs);
#endif
