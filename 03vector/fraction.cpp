#include <iostream>
#include <stdexcept> // std::out_of_range
#include <numeric> // std::gcd

#include "fraction.h"

Fraction::Fraction(int numerator, int denominator) {
    this->setNumerator(numerator);
    this->setDenominator(denominator);
}

void Fraction::setDenominator(int den) {
    if(den  == 0) {
        throw std::invalid_argument("You can't set denominator to 0, you dumbass!");
    }
    denominator_ = den;
}

Fraction Fraction::operator+(const Fraction& other) const{
    Fraction result;
    result.setDenominator(this->denominator() * other.denominator());
    result.setNumerator(this->numerator() * other.denominator() + other.numerator() * this->denominator());

    int result_gcd = std::gcd(result.numerator(), result.denominator());

    result.setNumerator(result.numerator() / result_gcd);
    result.setDenominator(result.denominator() / result_gcd);

    return result;
}

Fraction Fraction::operator*(const Fraction& other) const{

    Fraction result;
    result.setDenominator(this->denominator() * other.denominator());
    result.setNumerator(this->numerator() * other.numerator());

    int result_gcd = std::gcd(result.numerator(), result.denominator());

    result.setNumerator(result.numerator() / result_gcd);
    result.setDenominator(result.denominator() / result_gcd);

    return result;
}