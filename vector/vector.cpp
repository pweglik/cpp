// author: Grzegorz Prowadzacy

#include <algorithm>
#include <stdexcept>
#include <utility> // std::swap()

#include "vector.h"

Vector::Vector(size_t init_capacity= 0) 
{
    data_ = new Fraction[init_capacity];
    size_ = 0;
    capacity_ = init_capacity;
}

Vector::Vector(const Vector& other) {
    data_ = new Fraction[other.size()];
    size_ = other.size();
    capacity_ = other.capacity();

    for(size_t i = 0; i < other.size(); i++) {
        data_[i] = other[i];
    }
}

Vector& Vector::operator=(const Vector& other) {
    delete data_;
    data_ = new Fraction[other.size()];

    for(size_t i = 0; i < other.size(); i++) {
        data_[i] = other[i];
    }

    return *this;
}

void Vector::push_back(const Fraction& element) {


}

Fraction Vector::operator[](size_t index) {
    if(index < 0 || index >= size_) {
        throw std::out_of_range("Index out of range!");
    }
    return data_[index];
}

const Fraction Vector::operator[](size_t index) const {
    if(index < 0 || index >= size_) {
        throw std::out_of_range("Index out of range!");
    }
    return data_[index];
}