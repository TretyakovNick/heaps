#include <cassert>
//#include "array.h"


template <typename Key>
Array<Key>::~Array() {
    capacity = 0;
    array_size = 0;
    delete []data;
}

template <typename Key>
Array<Key>::Array() {
    capacity = 1;
    array_size = 0;
    data = new int[1];
}

template <typename Key>
int Array<Key>::size() const {
    return array_size;
}

template <typename Key>
void Array<Key>::push_back(Key key) {
    reallocate();
    assert(capacity > array_size);
    data[array_size++] = key;
}

template <typename Key>
bool Array<Key>::empty() const{
    return !array_size;
}

template <typename Key>
void Array<Key>::pop_back() {
    if (empty()) {
        throw std::out_of_range("Array is empty");
    }
    reallocate();
    array_size--;
}

template <typename Key>
Key& Array<Key>::operator[](int v) {
    if (v < 0 || v >= size()) {
        throw std::out_of_range("Bad index of Array");
    }
    return data[v];
}

template <typename Key>
void Array<Key>::reallocate() {
    if (array_size == capacity) {
        capacity *= 2;
        Key *new_data = new int[capacity];
        assert(capacity > array_size);
        for (int i = 0; i < array_size; i++) {
            new_data[i] = data[i];
        }
        delete []data;
        data = new_data;
    } else if (array_size < capacity / 4) {
        capacity /= 2;
        Key *new_data = new int[capacity];
        assert(capacity > array_size);
        for (int i = 0; i < array_size; i++) {
            new_data[i] = data[i];
        }
        delete []data;
        data = new_data;
   }
}
