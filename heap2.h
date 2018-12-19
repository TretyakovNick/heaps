#include "array.h"
#pragma once

template <typename Key>
class THeap {
private:
    void sift_down(int index);
    void sift_up(int index);
    class Element {
    friend THeap;
    private:
        Key key;
        int index;
        Element(Key key, int index) : key(key), index(index) {}
    };
    Array <Element*> arr;
    Key get(int index) const;
    void swap(int a, int b);
public:
    class Pointer{
        friend THeap;
    private:
        Element *element;
        THeap *heap;
        Pointer(Element *element, THeap *heap) : element(element), heap(heap) {}
    };
    ~THeap();
    THeap();
    bool is_empty() const;
    int size() const;
    Key get_min() const;
    Key extract_min();
    Pointer insert(Key key);
    void erase(Pointer &ptr);
    void change(Pointer &ptr, Key key);
    bool exist(Pointer &ptr) const;
};

#include "heap2.cpp"
