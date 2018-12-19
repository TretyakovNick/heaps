#include <exception>
#include <stdexcept>
#pragma once

template <typename Key>
class Array {
private:
    int capacity;
    int array_size;
    Key *data;
    void reallocate();
public:
    Array();
    ~Array();
    Key &operator[](int v);
    Key &operator[](int v) const;
    void push_back(Key key);
    bool empty() const;
    void pop_back();
    int size() const;
    void clear();
    Array <Key> &operator=(Array <Key> &otherArray);
};

#include "array.cpp"

