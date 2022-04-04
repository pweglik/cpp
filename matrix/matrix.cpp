#include <iostream>
#include <string>

using namespace std;

#include "matrix.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

TwoDimensionMatrix::TwoDimensionMatrix() {
    for(int i = 0; i < TwoDimensionMatrix::getSize(); i++) {
        for(int j = 0; j < TwoDimensionMatrix::getSize(); j++) {
            matrix[i][j] = 0;
        }   
    }
}

TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix& source) {
    for(int i = 0; i < TwoDimensionMatrix::getSize(); i++) {
        for(int j = 0; j < TwoDimensionMatrix::getSize(); j++) {
            matrix[i][j] = source[i][j];
        }   
    }
}

TwoDimensionMatrix::TwoDimensionMatrix(const  MatrixElement source[size][size] ) {
    for(int i = 0; i < TwoDimensionMatrix::getSize(); i++) {
        for(int j = 0; j < TwoDimensionMatrix::getSize(); j++) {
            matrix[i][j] = source[i][j];
        }   
    }
}

MatrixElement TwoDimensionMatrix::get(int i, int j) const {
    if (i >= TwoDimensionMatrix::getSize()) {
        cout << "Array index out of bound, exiting";
        exit(0);
    }
    return matrix[i][j];
}


MatrixElement* TwoDimensionMatrix::operator[](size_t i) {
    if (i >= TwoDimensionMatrix::getSize()) {
        cout << "Array index out of bound, exiting";
        exit(0);
    }
    return matrix[i];
}

const MatrixElement* TwoDimensionMatrix::operator[](size_t i) const {
    if (i >= TwoDimensionMatrix::getSize()) {
        cout << "Array index out of bound, exiting";
        exit(0);
    }
    return matrix[i];
}

TwoDimensionMatrix& TwoDimensionMatrix::operator=(const TwoDimensionMatrix& arg_matrix) {

    for(int i = 0; i < TwoDimensionMatrix::getSize(); i++) {
        for(int j = 0; j < TwoDimensionMatrix::getSize(); j++) {
            matrix[i][j] = arg_matrix.matrix[i][j];
        }   
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const TwoDimensionMatrix& td_matrix) {
    for(int i = 0; i < TwoDimensionMatrix::getSize(); i++) {
        for(int j = 0; j < TwoDimensionMatrix::getSize(); j++) {
            os << td_matrix.get(i, j) << " ";
        }
        os << "\n"; 
    }

    return os;
}

std::istream& operator>>(std::istream &is, TwoDimensionMatrix& td_matrix) {
    for(int i = 0; i < TwoDimensionMatrix::getSize(); i++) {
        for(int j = 0; j < TwoDimensionMatrix::getSize(); j++) {
            is >> td_matrix[i][j];
        }
    }

    return is;
}

TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2) {
    TwoDimensionMatrix td_matrix;

    for(int i = 0; i < TwoDimensionMatrix::getSize(); i++) {
        for(int j = 0; j < TwoDimensionMatrix::getSize(); j++) {
            td_matrix[i][j] = matrix1.get(i, j) + matrix2.get(i, j);
        }
    }
    return td_matrix;
}

TwoDimensionMatrix& TwoDimensionMatrix::operator*=(MatrixElement number) {
    for(int i = 0; i < TwoDimensionMatrix::getSize(); i++) {
        for(int j = 0; j < TwoDimensionMatrix::getSize(); j++) {
            matrix[i][j] = matrix[i][j] * number;
        }
    }

    return *this;
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix& other) const {
    TwoDimensionMatrix result;

    for(int i = 0; i < TwoDimensionMatrix::getSize(); i++) {
        for(int j = 0; j < TwoDimensionMatrix::getSize(); j++) {
            result[i][j] = matrix[i][j] && other[i][j];
        }
    }
    return result;
}

