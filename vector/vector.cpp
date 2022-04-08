// author: Grzegorz Prowadzacy

#include <algorithm>
#include <stdexcept>
#include <utility> // std::swap()
#include <cstring>

#include "vector.h"

Vector::Vector(size_t init_capacity) 
{
    data_ = new Fraction[init_capacity];
    size_ = 0;
    capacity_ = init_capacity;
}

Vector::Vector(const Vector& other) {
    data_ = new Fraction[other.capacity()];
    size_ = other.size();
    capacity_ = other.capacity();

    for(size_t i = 0; i < other.size(); i++) {
        data_[i] = other[i];
    }
}

Vector::Vector(Vector&& other) {
    data_ = other.data_;
    size_ = other.size();
    capacity_ = other.capacity();

    // clear rvalue
    other.size_ = 0;
    other.capacity_ = 0;
    other.data_ = nullptr;
}

Vector& Vector::operator=(const Vector& other) {
    delete[] data_;
    data_ = new Fraction[other.size()];
    size_ = other.size();
    capacity_ = other.capacity();

    for(size_t i = 0; i < other.size(); i++) {
        data_[i] = other[i];
    }

    return *this;
}

Vector& Vector::operator=(Vector&& other) {
    delete[] data_;
    data_ = other.data_;
    size_ = other.size();
    capacity_ = other.capacity();

    // clear rvalue
    other.size_ = 0;
    other.capacity_ = 0;
    other.data_ = nullptr;

    return *this;
}



void Vector::push_back(const Fraction& element) {
    
    if(capacity_ <= size_)
    {
        Fraction* temp_data = data_;

        data_ = new Fraction[capacity_ + 1];
        std::memcpy(data_, temp_data, capacity_);
        delete[] temp_data;
        capacity_ += 1;
    }

    data_[size_] = element;
    size_ += 1;
    
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