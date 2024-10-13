#include <stdexcept>
#include "ArrayList.hpp"
#include <iostream>

template<typename T>
ArrayList<T>::ArrayList() {
    this->size = 1;
    length = 0;
    array = allocate(size);
}

template<typename T>
ArrayList<T>::ArrayList(int size) {
    this->size = size;
    length = 0;
    array = allocate(size);
}

template<typename T>
void ArrayList<T>::validateIndex(int index) {
    if (index < 0)
        throw std::invalid_argument("Index cannot be less than zero. Received: " +       
    std::to_string(index));
    if (index > length - 1) {
        throw std::invalid_argument("Index is out of bounds. Received: " +     
    std::to_string(index));
    }
}

template<typename T>
T ArrayList<T>::get(int index) {
    validateIndex(index);
    return array[index];
}

template<typename T>
void ArrayList<T>::doubleAndMove() {
    T* newArray = allocate(size * 2);
    copy(array, newArray, 0, size);
    delete [] array;
    array = newArray;
    size = size * 2;
}

template<typename T>
void ArrayList<T>::halfAndMove() {
    T* newArray = allocate(size / 2);
    copy(array, newArray, 0, size/2);
    delete[] array;
    array = newArray;
    size = size/2;
}

template<typename T>
void ArrayList<T>::append(T element) {
    if (length == size) {
        doubleAndMove();
    }
    array[length++] = element;
}

template<typename T>
void ArrayList<T>::set(int idx, int number) {
    validateIndex(idx);
    array[idx] = number;
}

template<typename T>
void ArrayList<T>::copy(T* from, T* to, int start_idx, int end_idx) {
   for (int i = start_idx; i < end_idx; i++) {
      to[i] = from[i];
   }   
}

template<typename T>
T ArrayList<T>::pop() {
    if (length <= 0) {
        throw std::out_of_range("Cannot pop from an empty list");
    }
    if (length - 1 < size / 2) {
        halfAndMove();
    }
    return array[--length];
}

template<typename T>
T ArrayList<T>::pop(int idx) {
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

template<typename T>
T ArrayList<T>::remove(int value) {
    for (int i = 0; i < length; i++) {
        if (array[i] == value) {
            return this->pop(i);
        }
    }
    throw std::invalid_argument("Value does not exist in array. Received: " + std::to_string(value));
}

template<typename T>
int ArrayList<T>::getSize() {
    return size;
}

template<typename T>
int ArrayList<T>::getLength() {
    return length;
}

template<typename T>
T* ArrayList<T>::allocate(int size) {
    return new T[size];
}


std::ostream& operator<<(std::ostream& os,  ArrayList& list) {
    os << "[";
    for (int i = 0; i < list.getLength(); ++i) {
        os << list.get(i);
        if (i < list.getLength() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
