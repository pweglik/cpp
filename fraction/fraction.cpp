#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <iosfwd>
#include <sstream>

using namespace std;

#include "fraction.h"

#if IMPLEMENTED_classFractionExists
#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
#endif // IMPLEMENTED_classFractionExists

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction (int numerator, int denominator):
numerator(numerator),
denominator(denominator)
{}

Fraction::Fraction (int numerator, int denominator, string fractionName):
numerator(numerator),
denominator(denominator),
fractionName(fractionName)
{}

void Fraction::print() const {
    cout<<numerator<<"/"<<denominator<<endl;
}

void Fraction::load(std::istream& is) {
    string fractionString;

    is >> fractionString;

    char *str = new char[fractionString.length() + 1];
    strcpy(str, fractionString.c_str());

    char * token = strtok(str, "/");
    
    numerator = atoi(token);

    token = strtok(NULL, "/");
    denominator = atoi(token);
}