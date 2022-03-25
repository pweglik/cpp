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
        for(int j = 0; i < TwoDimensionMatrix::getSize(); i++) {
            matrix[i][j] = 0;
        }   
    }
}

TwoDimensionMatrix::TwoDimensionMatrix(TwoDimensionMatrix& source) {
    for(int i = 0; i < TwoDimensionMatrix::getSize(); i++) {
        for(int j = 0; i < TwoDimensionMatrix::getSize(); i++) {
            matrix[i][j] = source[i][j];
        }   
    }
}

TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement** source) {
    for(int i = 0; i < TwoDimensionMatrix::getSize(); i++) {
        for(int j = 0; i < TwoDimensionMatrix::getSize(); i++) {
            matrix[i][j] = source[i][j];
        }   
    }
}

MatrixElement* TwoDimensionMatrix::operator[](size_t i) {
    if (i >= TwoDimensionMatrix::getSize()) {
        cout << "Array index out of bound, exiting";
        exit(0);
    }
    return matrix[i];
}


