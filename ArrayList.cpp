#include <stdexcept>
#include "ArrayList.hpp"
#include <iostream>

ArrayList::ArrayList() {
    size = 1;
    length = 0;
    array = allocate(size);
}
ArrayList::ArrayList(int size) {
    this->size = size;
    length = 0;
    array = allocate(size);
}

void ArrayList::validateIndex(int index) {
    if (index < 0)
        throw std::invalid_argument("Index cannot be less than zero. Received: " +       
    std::to_string(index));
    if (index > length - 1) {
        throw std::invalid_argument("Index is out of bounds. Received: " +     
    std::to_string(index));
    }
}

int ArrayList::get(int index) {
    validateIndex(index);
    return array[index];
}

void ArrayList::doubleAndMove() {
    int* newArray = allocate(size * 2);
    copy(array, newArray, 0, size);
    delete [] array;
    array = newArray;
    size = size * 2;
}

void ArrayList::halfAndMove() {
    int* newArray = allocate(size / 2);
    copy(array, newArray, 0, size/2);
    delete[] array;
    array = newArray;
    size = size/2;
}

void ArrayList::append(int number) {
    if (length == size) {
        doubleAndMove();
    }
    array[length++] = number;
}

void ArrayList::set(int idx, int number) {
    validateIndex(idx);
    array[idx] = number;
}

void ArrayList::copy(int* from, int* to, int start_idx, int end_idx) {
   for (int i = start_idx; i < end_idx; i++) {
      to[i] = from[i];
   }   
}

int ArrayList::pop() {
    if (length <= 0) {
        throw std::out_of_range("Cannot pop from an empty list");
    }
    if (length - 1 < size / 2) {
        halfAndMove();
    }
    return array[--length];
}


int ArrayList::pop(int idx) {
    if (idx < 0 || idx >= length) {
        throw std::invalid_argument("Index is out of bounds. Received: " + std::to_string(idx));
    }
    int toReturn = array[idx];
    if (length - 1< size / 2) {
        halfAndMove();
    }
    for (int i = idx; i < length - 1; i++) {
        array[i] = array[i+1];
    }
    length--;
    return toReturn;
}

int ArrayList::remove(int value) {
    for (int i = 0; i < length; i++) {
        if (array[i] == value) {
            return this->pop(i);
        }
    }
    throw std::invalid_argument("Value does not exist in array. Received: " + std::to_string(value));
}

int ArrayList::getSize() {
    return size;
}

int ArrayList::getLength() {
    return length;
}

int* ArrayList::allocate(int size) {
    return new int[size];
}


std::ostream& operator<<(std::ostream& os,  ArrayList& list) {
    os << "[";
    for (size_t i = 0; i < list.getLength(); ++i) {
        os << list.get(i);
        if (i < list.getLength() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}